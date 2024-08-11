import { GameManager } from './models/GameManager.js';
import { Player } from './models/Player.js';
import { Server } from 'socket.io';
import { sendMessage } from './utils/messaging.js';
import fs from 'fs';
import { parse } from 'csv-parse';

/**
 * Get the leaderboard from the CSV file.
 * @returns {Promise<Array>} Promise that resolves with the leaderboard array.
 */
export function getLeaderboard() {
  const filePath = './scores.csv';

  return new Promise((resolve, reject) => {
    const records = [];
    const stream = fs.createReadStream(filePath, 'utf8');

    stream.on('error', (error) => {
      reject('Erreur lors de l\'ouverture du fichier: ' + error.message);
    });

    const parser = stream.pipe(parse({
      columns: false,
      fromLine: 1,
      delimiter: ','
    }));

    parser.on('data', (row) => {
      const rowData = {
        user: row[0],
        score: row[1]
      }
      records.push(rowData);
    });

    parser.on('end', () => {
      try {
        const sorted = records.sort((a, b) => parseFloat(b.score) - parseFloat(a.score));
        resolve(sorted.slice(0, 10));
      } catch (error) {
        reject('Error while sorting data: ' + error.message);
      }
    });

    parser.on('error', (error) => {
      reject('Error while parsing data: ' + error.message);
    });
  });
}

const gameManager = new GameManager();

export function setupSocket(server) {

  const io = new Server(server, {
    cors: {
      origin: '*',
      methods: ['GET', 'POST'],
    }
  });

  io.on('connection', (socket) => {
    socket.on('moveBlock', ({direction, gameId}) => {
      const player = gameManager.getPlayerById(socket.id);
      const game = gameManager.getGame(gameId);
      if (player) {
        if (player.gameBoard.gameOver) {
          sendMessage(socket, 'moveBlock', null, 'error', 'Move not allowed');
          return;
        }
        player.moveSide(direction);
        game.game.updateGame(false);
      }
      else {
        sendMessage(socket, 'moveBlock', null, 'error', 'Player not found');
      }
    })

    socket.on('moveDown', ({gameId}) => {
      const player = gameManager.getPlayerById(socket.id);
      const game = gameManager.getGame(gameId);
      if (player) {
        if (player.gameBoard.gameOver) {
          sendMessage(socket, 'moveDown', null, 'error', 'Move not allowed');
          return;
        }
        player.moveDown();
        game.game.updateGame(false);
      }
      else {
        sendMessage(socket, 'moveDown', null, 'error', 'Player not found');
      }
    })

    socket.on('rotateBlock', ({gameId}) => {
      const player = gameManager.getPlayerById(socket.id);
      const game = gameManager.getGame(gameId);
      if (player) {
        if (player.gameBoard.gameOver) {
          sendMessage(socket, 'rotateBlock', null, 'error', 'Move not allowed');
          return;
        }
        player.rotate();
        if (game) {
          game.game.updateGame(false);
        }
      }
      else {
        sendMessage(socket, 'rotateBlock', null, 'error', 'Player not found');
      }
    })

    socket.on('hardDrop', ({gameId}) => {
      const player = gameManager.getPlayerById(socket.id);
      const game = gameManager.getGame(gameId);
      if (player) {
        if (player.gameBoard.gameOver) {
          sendMessage(socket, 'hardDrop', null, 'error', 'Move not allowed');
          return;
        }
        player.hardDrop();
        game.game.updateGame(false);
      }
      else {
        sendMessage(socket, 'hardDrop', null, 'error', 'Player not found');
      }
    })

    socket.on('getLeaderboard', async () => {
      try {
        const leaderboard = await getLeaderboard();
        sendMessage(socket, 'getLeaderboard', null, 'success', 'leaderboard sent', { leaderboard });
      } catch (error) {
        sendMessage(socket, 'getLeaderboard', null, 'error', 'leaderboard error');
      }
    });

    socket.on('createPlayer', ({ playerName }) => {
      const player = new Player(socket, playerName);
      gameManager.addPlayer(player);
      sendMessage(socket, 'createPlayer', null, 'success', 'player created', { playerName: player.name });
    });

    socket.on('createGame', () => {
      const game = gameManager.createGame(socket.id, "easy");

      if (!game) {
        sendMessage(socket, 'createGame', null, 'error', 'You are already in a game');
        return;
      }
      sendMessage(socket, 'createGame', null, 'success', 'game created', { gameId: game.gameId });
    });

    socket.on('getGames', () => {
      const games = gameManager.getGames();
      if (games.length === 0) {
        sendMessage(socket, 'getGames', null, 'success', 'No games available', { games });
        return;
      }
      sendMessage(socket, 'getGames', null, 'success', 'games list sent', { games });
    });

    socket.on("getGame", ({ gameId }) => {
      const game = gameManager.getGame(gameId);
      if (!game) {
        sendMessage(socket, "getGame", null, 'error', 'Game not found');
        return;
      }
      sendMessage(socket, "getGame", null, 'success', 'game info sent', { difficulty: game.game.difficulty, isInfinite: game.game.isInfinite, players: game.players, owner: game.game.owner });
    });

    socket.on("deleteGame", ({ gameId }) => {
      const ret = gameManager.deleteGame(gameId);
      if (!ret) {
        sendMessage(socket, "deleteGame", null, 'error', 'Game not found');
        return;
      }
      sendMessage(socket, "deleteGame", null, 'success', 'game deleted', { gameId });
    });

    socket.on("startGame", ({ gameId, playerId }) => {
      const game = gameManager.getGame(gameId);
      if (!game) {
        sendMessage(socket, "startGame", null, 'error', 'Game not found');
        return;
      }
      game.game.startGame(playerId);
      game.game.players.forEach(player => {
        sendMessage(io, "startGame", player.id, 'success', 'game started', { gameId });
      });
      gameManager.emitRefreshSignalToAllPlayers();
    });

    socket.on("setDifficulty", ({ gameId, difficulty, isInfinite }) => {
      const game = gameManager.getGame(gameId);
      if (!game) {
        sendMessage(socket, "setDifficulty", null, 'error', 'Game not found');
        return;
      }
      game.game.changeDifficulty(difficulty, isInfinite);
      sendMessage(socket, "setDifficulty", null, 'success', 'difficulty changed', { gameId, difficulty, isInfinite });
    });

    socket.on("resetServer", () => {
      gameManager.reset();
      sendMessage(socket, "resetServer", null, 'success', 'server reset');
    });

    socket.on("joinGame", ({ gameId, playerId }) => {
      const game = gameManager.getGame(gameId);
      if (!game)
        return sendMessage(socket, "joinGame", null, 'error', 'Game not found');
      if (game.game.isStarted)
        return sendMessage(socket, "joinGame", null, 'error', 'Game already started');
      const player2 = gameManager.getPlayerById(playerId);
      game.game.addPlayerToGame(player2);
      gameManager.emitRefreshSignalToAllPlayers();
      sendMessage(socket, "joinGame", null, 'success', 'player joined', { gameId, playerId });
    });

    socket.on("leaveRoom", ({ gameId, playerId }) => {
      gameManager.handlePlayerLeavesRoom(playerId, gameId);
      gameManager.emitRefreshSignalToAllPlayers();
      sendMessage(socket, "leaveRoom", null, 'success', 'player left', { gameId, playerId });
    });

    socket.on("leaveGame", ({ gameId, playerId }) => {
      const game = gameManager.getGame(gameId);
      if (game) {
          if (game.players) {
            game.players.forEach(player => {
              if (player.id != socket.id)
                sendMessage(io, "leaveGame", player.id, 'success', 'player left', { gameId, playerId });
            });
          }
          game.game.leaveGame(playerId);
        }
        else {
          sendMessage(socket, "leaveGame", null, 'error', 'Game not found');
        }
        gameManager.handlePlayerDisconnect(playerId);
      });

    socket.on('updateGrid', ({ gameId, playerId, grid }) => {
      const game = gameManager.getGame(gameId);
      const player = gameManager.getPlayerById(playerId);
      if (!player) {
        sendMessage(socket, 'updateGrid', null, 'error', 'Player not found');
        return;
      }
      const board = player.gameBoard;
      if (!game) {
        sendMessage(socket, 'updateGrid', null, 'error', 'Game not found');
        return;
      }
      board.updateGrid(grid);
      game.players.forEach(player => {
        if (player.id != socket.id)
          sendMessage(io, 'updateGrid', player.id, 'success', 'grid updated', { gameId, playerId, grid });
      });
    });

    socket.on('changeName', ({ playerId, newName }) => {
      const player = gameManager.getPlayerById(playerId);
      if (!player) {
        sendMessage(socket, 'changeName', null, 'error', 'Player not found');
        return;
      }
      player.changeName(newName);
      sendMessage(socket, 'changeName', null, 'success', 'name changed', { playerId, newName });
    });

    socket.on('disconnect', () => {
      gameManager.handlePlayerDisconnect(socket.id);
    });

    socket.on('restartGame', ({ gameId }) => {
      const game = gameManager.getGame(gameId);
      if (!game) {
        sendMessage(socket, 'restartGame', null, 'error', 'Game not found');
        return;
      }
      game.game.resetGame();
      game.players.forEach(player => {
        sendMessage(io, 'restartGame', player.id, 'success', 'game restarted', { gameId });
      });
    });

  });

  return io;
}
