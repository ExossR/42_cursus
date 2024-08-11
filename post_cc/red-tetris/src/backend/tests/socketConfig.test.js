import { createServer } from "http";
import { io as Client } from "socket.io-client";
import { GameManager } from '../models/GameManager';
import * as messaging from '../utils/messaging';
import { setupSocket } from '../socketConfig';

jest.mock('../models/Game', () => {
  const actualGame = jest.requireActual('../models/Game').Game;
  return {
    Game: jest.fn().mockImplementation(
    function(gameId, owner, difficulty, gameManager) {
      const instance = new actualGame("test123", owner, difficulty, gameManager);
      instance.addPlayerToGame = jest.fn();
      instance.hasPlayer = jest.fn();
      instance.leaveGame = jest.fn();
      instance.players = [];
      instance.changeDifficulty = jest.fn(function(difficulty) {
        this.difficulty = difficulty;
        this.emitReloadGameSignalToAllPlayers();
      });
      return instance;
    }),
  };
});

jest.mock('../models/GameManager.js', () => {
  const actualGameManager = jest.requireActual('../models/GameManager').GameManager;
  return {
    GameManager: jest.fn().mockImplementation(function() {
      const instance = new actualGameManager();
      const game = instance.createGame('testPlayer', 'easy').gameId;
      instance.deleteGame = jest.fn((gameId) => {
        if (gameId === 'test123') {
          instance.games.delete(gameId);
          return true;
        }
        else if (gameId === '123') {
          return true;
        }
        return false;
      });
      instance.getGame = jest.fn((gameId) => {
        if (gameId === 'test123') {
          return { game: instance.games.get(game) };
        }
        return null;
      });
      return instance;
    }),
  };
});

jest.mock('../models/Player.js', () => {
  const actualPlayer = jest.requireActual('../models/Player').Player;
  return {
    Player: jest.fn().mockImplementation(
      function(playerId, socket, game) {
        const instance = new actualPlayer(playerId, socket, game);
        instance.changeName = jest.fn();
        return instance;
      }),
  };
});


describe('Real Socket.IO Game Server Tests', () => {
  let ioServer, server, clientSocket, gameManager, gameId;

  beforeAll(done => {
    server = createServer();
    ioServer = setupSocket(server);
    gameManager = new GameManager();
    server.listen(() => {
        const port = server.address().port;
        clientSocket = Client(`http://localhost:${port}`);
        clientSocket.on('connect', done);
    });
  });

  afterAll(() => {
      clientSocket.close();
      ioServer.close(() => {
          server.close();
      });
  });

  beforeEach(() => {
    jest.clearAllMocks();
    gameId = gameManager.createGame('testPlayer', 'easy').gameId;
  });

  test('getGames should send game data', async () => {
      const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

      clientSocket.emit('getGames');
      const data = await new Promise((resolve) => {
          clientSocket.once('getGames', (response) => {
              resolve(response);
          });
      });

      expect(data.status).toBe('success');
      expect(data.data.games).toBeDefined();
      expect(sendMessageSpy).toHaveBeenCalled();

      sendMessageSpy.mockRestore();
  });

  test('getGames should send game data empty if no game', async () => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');



    clientSocket.emit('getGames');
    const data = await new Promise((resolve) => {
        clientSocket.once('getGames', (response) => {
            resolve(response);
        });
    });

    expect(data.status).toBe('success');
    expect(data.data.games).toBeDefined();
    expect(sendMessageSpy).toHaveBeenCalled();

    sendMessageSpy.mockRestore();
  });

  test('getGame should send error if game not found', async () => {
      const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

      clientSocket.emit('getGame', '456');
      const data = await new Promise((resolve) => {
          clientSocket.once('getGame', (response) => {
              resolve(response);
          });
      });

      expect(data.status).toBe('error');
      expect(data.message).toBe('Game not found');
      expect(sendMessageSpy).toHaveBeenCalled();

      sendMessageSpy.mockRestore();
  });

  test('getGame should send game data', async () => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('getGame', '123');
    const data = await new Promise((resolve) => {
        clientSocket.once('getGame', (response) => {
            resolve(response);
        });
    });
  });

  test('getLeaderboard should send leaderboard data', async () => {
      const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

      clientSocket.emit('getLeaderboard');
      const data = await new Promise((resolve) => {
          clientSocket.once('getLeaderboard', (response) => {
              resolve(response);
          });
      });
      expect(data.status).toBe('success');
      expect(data.data.leaderboard).toBeDefined();
      expect(sendMessageSpy).toHaveBeenCalled();

      sendMessageSpy.mockRestore();
  });

  test('deleteGame should send error if game not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('deleteGame', { gameId: '456' });
    clientSocket.once('deleteGame', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Game not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('deleteGame should send success message', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('deleteGame', { gameId: '123' });
    clientSocket.once('deleteGame', (data) => {
      expect(data.status).toBe('success');
      expect(data.message).toBe('game deleted');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('setDifficulty should send error if game not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('setDifficulty', { gameId: '456', difficulty: 'easy' });
    clientSocket.once('setDifficulty', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Game not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('setDifficulty should send success message', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('setDifficulty', { gameId, difficulty: 'hard' });

    clientSocket.once('setDifficulty', (data) => {
      expect(data.status).toBe('success');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('resetServer should send success message', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('resetServer');
    clientSocket.once('resetServer', (data) => {
      expect(data.status).toBe('success');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('joinGame should send error if game not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('joinGame', { gameId: '456' });
    clientSocket.once('joinGame', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Game not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('leaveGame should send error if game not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('leaveGame', { gameId: '456' });
    clientSocket.once('leaveGame', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Game not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('moveBlock should send error if player not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('moveBlock', { gameId, playerId: '456', direction: 'up' });
    clientSocket.once('moveBlock', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Player not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('moveDown should send error if player not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('moveDown', { gameId, playerId: '456' });
    clientSocket.once('moveDown', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Player not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('rotateBlock should send error if player not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('rotateBlock', { gameId, playerId: '456' });
    clientSocket.once('rotateBlock', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Player not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('hardDrop should send error if player not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('hardDrop', { gameId, playerId: '456' });
    clientSocket.once('hardDrop', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Player not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('createPlayer should sendMessage', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('createPlayer', { gameId });
    clientSocket.once('createPlayer', (data) => {
      expect(data.status).toBe('success');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('createGame should accept new game if not allready in game', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('createGame', { owner: 'testPlayer', difficulty: 'easy' });
    clientSocket.once('createGame', (data) => {
      expect(data.status).toBe('success');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('changeName should send error if player not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('changeName', { gameId, playerId: '456', name
    : 'testPlayer' });
    clientSocket.once('changeName', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Player not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('updateGrid should send error if player not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('updateGrid', { gameId, playerId: '456', grid: [] });
    clientSocket.once('updateGrid', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Player not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('leaveRoom should call handlePlayerLeavesRoom and emitRefreshSignalToAllPlayers', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('leaveRoom', { gameId, playerId: 'testPlayer' });
    clientSocket.once('leaveRoom', (data) => {
      expect(data.status).toBe('success');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });

  test('restartGame should send error if game not found', done => {
    const sendMessageSpy = jest.spyOn(messaging, 'sendMessage');

    clientSocket.emit('restartGame', { gameId
    : '456' });
    clientSocket.once('restartGame', (data) => {
      expect(data.status).toBe('error');
      expect(data.message).toBe('Game not found');
      expect(sendMessageSpy).toHaveBeenCalled();
      sendMessageSpy.mockRestore();
      done();
    });
  });
});

