import { TETRIS_SHAPES } from '../constant.js';
import { sendMessage } from '../utils/messaging.js';

export class Game {
  /**
   * Creates a Game instance.
   * @param {string} gameId - The unique identifier for the game.
   * @param {string} owner - The ID of the owner of the game.
   * @param {string} difficulty - The difficulty level of the game.
   * @param {object} gameManager - The game manager instance.
   */
  constructor(gameId, owner, difficulty, gameManager) {
    this.gameId = gameId;
    this.players = [];
    this.isStarted = false;
    this.pieceSeries = this.generatePieceSeries();
    this.owner = owner;
    this.difficulty = difficulty;
    this.isInfinite = false;
    this.onePiece = false;
    this.gameManager = gameManager;
    this.interval = null;
    this.winner = null;
    this.multiplayer = false;
    this.multiplier = 0;
  }

  /**
   * Gets the interval time based on the difficulty and multiplier.
   * @returns {number} The interval time in milliseconds.
   */
  getIntervalTime() {
    let baseTime;
    switch(this.difficulty) {
      case 'easy': baseTime = 1000; break;
      case 'medium': baseTime = 600; break;
      case 'hard': baseTime = 300; break;
      default: baseTime = 1000;
    }
    return (this.difficulty === 'easy' ? Math.max(baseTime, 100) : Math.max(baseTime - this.multiplier, 100));
  }

  /**
   * Converts a Tetris piece to a matrix representation.
   * @param {number} piece - The Tetris piece identifier.
   * @returns {number[][]} A 4x4 matrix representing the piece.
   */
  pieceToMatrix(piece) {
    const matrix = Array.from({length: 4}, () => Array.from({length: 4}, () => 0));
    if (piece - 1 < 0 || piece - 1 >= TETRIS_SHAPES.length) {
      return matrix;
    }
    const shape = TETRIS_SHAPES[piece - 1][0];
    shape.forEach(block => {
      const row = block[0] + 2;
      const col = block[1] + 2;
      if (row >= 0 && row < 4 && col >= 0 && col < 4) {
        matrix[row][col] = piece;
      }
    });
    return matrix;
  }

  /**
   * Updates the state of a single player.
   * @param {object} player - The player object.
   * @param {boolean} shouldGoDown - Whether the pieces should move down.
   */
  updatePlayerState(player, shouldGoDown) {
    if (shouldGoDown) {
      player.moveDown();
    }
  }

  /**
   * Gets the shadow grids of all other players for a given player.
   * @param {string} playerId - The ID of the player.
   * @returns {object[]} Array of shadow grid objects.
   */
  getShadowGridsForPlayer(playerId) {
    return Array.from(this.players)
      .filter(id => id !== playerId)
      .map(id => {
        const otherPlayer = this.gameManager.getPlayerById(id);
        return otherPlayer ? { playerId: id, playerName: otherPlayer.name, shadowGrid: otherPlayer.getShadowGrid() } : null;
      })
      .filter(shadow => shadow !== null);
  }

  /**
   * Sends a game update message to a player.
   * @param {object} player - The player object.
   * @param {object[]} shadowGrids - Array of shadow grid objects.
   */
  sendGameUpdateToPlayer(player, shadowGrids) {
    if (!this.winner) {
      sendMessage(player.socket, 'updateGame', null, 'success', 'Game updated', {
        playerId: player.socket.id,
        board: player.gameBoard.grid,
        score: player.score,
        shadowGrids: shadowGrids,
        nextPiece: this.pieceToMatrix(player.gameBoard.nextPiece.shape),
        owner: this.getPlayerNameById(this.owner),
        ownerId: this.owner,
      });
    }
  }

  /**
   * Handles game over for a single player.
   * @param {string} playerId - The ID of the player.
   * @param {object} player - The player object.
   */
  handleGameOverForPlayer(playerId, player) {
    this.multiplayer = this.players.length > 1;
    if (!this.multiplayer) {
      this.handleSinglePlayerGameOver(playerId, player);
    } else {
      this.handleMultiplayerGameOver(playerId, player);
    }
  }

    /**
   * Handles game over for a single-player game.
   * @param {string} playerId - The ID of the player.
   * @param {object} player - The player object.
   */
    handleSinglePlayerGameOver(playerId, player) {
      clearInterval(this.interval);
      this.winner = playerId;
      this.sendGameOverToPlayer(playerId);
      sendMessage(player.socket, 'allowRestart', null, 'success', 'allowRestart', null);
      this.winner = null;
      this.multiplier = 0;
    }

      /**
   * Handles game over for a multiplayer game.
   * @param {string} playerId - The ID of the player.
   * @param {object} player - The player object.
   */
  handleMultiplayerGameOver(playerId, player) {
    this.sendGameOverToPlayer(playerId);
    if ((!this.isInfinite && this.checkIfLeftOnePlayerAlive()) 
            || (this.isInfinite && this.areAllPlayersGameOver()) 
            || this.players.length === 1
        ) {
      this.endMultiplayerGame(playerId);
    }
  }

    /**
   * Checks if all players are game over.
   * @returns {boolean} True if all players are game over, false otherwise.
   */
    areAllPlayersGameOver() {
      return this.players.every(id => {
        const player = this.gameManager.getPlayerById(id);
        return player && player.gameBoard.gameOver;
      });
    }

    /**
     * 
     * @param {string} playerId - The ID of the player who triggered the end.
     */
    writeScoresForLastPlayer(playerId) {
        const player = this.gameManager.getPlayerById(playerId);
        player.writeScoreToLeaderboard(player.name, player.score);
    }

    /**
     * Ends a multiplayer game.
     * @param {string} playerId - The ID of the player who triggered the end.
     */
    endMultiplayerGame(playerId) {
        if (!this.winner && !this.isInfinite) {
            let last = this.getLastPlayerAlive();
            this.writeScoresForLastPlayer(last);
            this.winner = last;
        } 
        this.players.forEach((id) => {
        const otherPlayer = this.gameManager.getPlayerById(id);
        if (otherPlayer) {
            this.sendGameOverToPlayer(id);
            sendMessage(otherPlayer.socket, 'allowRestart', null, 'success', 'allowRestart', null);
        }
        });
        clearInterval(this.interval);
        if (!this.winner && this.isInfinite) {
            this.winner = playerId;
        }
        this.sendGameOverToPlayer(playerId);
        this.multiplier = 0;
    }


    getLastPlayerAlive() {
        for (const playerId of this.players) {
            const player = this.gameManager.getPlayerById(playerId);
            if (player && !player.gameBoard.gameOver) {
                return playerId;
            }
        }
        return null;
    }


    checkIfLeftOnePlayerAlive() {
        let count = 0;
        for (const playerId of this.players) {
            const player = this.gameManager.getPlayerById(playerId);
            if (player && !player.gameBoard.gameOver) {
                count++;
            }
        }
        return (count === 1);
    }

    /**
     * Updates the game state for all players.
     * @param {boolean} [shouldGoDown=true] - Whether the pieces should move down.
     */
    updateGame(shouldGoDown = true) {
        for (const playerId of this.players) {
            const player = this.gameManager.getPlayerById(playerId);
            if (player) {
                this.updatePlayerState(player, shouldGoDown);
                const shadowGrids = this.getShadowGridsForPlayer(playerId);
                this.sendGameUpdateToPlayer(player, shadowGrids);

                if (!this.winner) {
                    sendMessage(player.socket, 'updateGame', null, 'success', 'Game updated', {
                        playerId: player.socket.id,
                        board: player.gameBoard.grid,
                        score: player.score,
                        shadowGrids: shadowGrids,
                        nextPiece: this.pieceToMatrix(player.gameBoard.nextPiece.shape),
                        owner: this.getPlayerNameById(this.owner),
                        ownerId: this.owner,
                    });
                }
                if (player.gameBoard.gameOver) {
                    this.handleGameOverForPlayer(playerId, player);
                }
            }
        }
    }

  /**
   * Emits a signal to reload the game for all players.
   */
  emitReloadGameSignalToAllPlayers() {
    for (const playerId of this.players) {
      const player = this.gameManager.getPlayerById(playerId);
      if (player) {
        sendMessage(player.socket, 'reloadGame', null, 'success', 'Reload now', null);
      }
    }
  }

  /**
   * Changes the difficulty of the game and reloads the game for all players.
   * @param {string} difficulty - The new difficulty level.
   */
  changeDifficulty(difficulty, isInfinite) {
    this.difficulty = difficulty;
    this.isInfinite = isInfinite;
    this.emitReloadGameSignalToAllPlayers();
  }

  /**
   *
   * @returns {string} A string of 99 random pieces.
   */
  generatePieceSeries() {
    return Array.from({length: 99}, () => Math.floor(Math.random() * 7) + 1).join('');
  }


  /**
   *
   * @returns {string} A string of 1 random piece.
   */
  generateOnePieceSeries() {
    let piece = Math.floor(Math.random() * 7) + 1;
    return Array.from({length: 99}, () => piece).join('');
  }

  /**
   * Adds a player to the game.
   * @param {Player} player - The player to add to the game.
   */
  addPlayerToGame(player) {
    this.players.push(player.socket.id);
    if (!this.owner) {
      this.owner = player.socket.id;
    }
    player.gameBoard.initialize(this.pieceSeries);
    this.emitReloadGameSignalToAllPlayers();
    player.addGame(this);
  }

    verifOnePiece() {
        let isOnePiece = false;
        this.players.forEach((playerId) => {
            let p = this.gameManager.getPlayerById(playerId);
            if (p.name.toLowerCase().includes('onepiece') || p.name.toLowerCase().includes('luffy')) {
                isOnePiece = true;
            }
        });
        if (isOnePiece)
            return (true);
        return (false);
    }

  /**
   * Starts the game.
   */
    startGame() {
        this.onePiece = this.verifOnePiece();
        if (this.onePiece)
            this.pieceSeries = this.generateOnePieceSeries();
        else
            this.pieceSeries = this.generatePieceSeries();
        this.players.forEach((playerId) => {
            const player = this.gameManager.getPlayerById(playerId);
            if (player) {
                player.gameBoard.initialize(this.pieceSeries);
            }
        });
        if (this.players.length > 1)
            this.multiplayer = true;
        this.isStarted = true;
        const update = () => {
            this.updateGame();
            this.multiplier = this.multiplier + 1;
            if (this.isStarted) {
                clearInterval(this.interval);
                this.interval = setInterval(update, this.getIntervalTime());
            }
        };
        this.interval = setInterval(update, this.getIntervalTime());
    }


  /**
   * Removes a player from the game.
   * If the player was the owner, the next player in the list becomes the owner.
   * @param {string} playerId - The ID of the player to remove.
   */
  leaveGame(playerId) {
    if (playerId === this.owner) {
      if (this.players.length > 1) {
        this.players = this.players.filter(id => id !== playerId);
        this.owner = this.players[0];
      } else {
        this.players = this.players.filter(id => id !== playerId);
        this.owner = null;
      }
    }
    else {
      this.players = this.players.filter(id => id !== playerId);
    }
    this.emitReloadGameSignalToAllPlayers();
  }

  /**
   * Checks if a player is in the game.
   * @param {string} playerId - The ID of the player to check.
   * @returns {boolean} True if the player is in the game, false otherwise.
   */
  hasPlayer(playerId) {
    return this.players.includes(playerId);
  }

  /**
   * Sends malus lines to all players except the specified player.
   * @param {string} playerId - The ID of the player to exclude.
   * @param {number} malusLines - The number of malus lines to send.
   */
  sendMalusToAllPlayersExcept(playerId, malusLines) {
    for (const id of this.players) {
      if (id !== playerId) {
        const player = this.gameManager.getPlayerById(id);
        if (player) {
          player.gameBoard.upgradeMalus(malusLines);
        }
      }
    }
  }

  /**
   * Sends a game over message to a player.
   * @param {string} playerId - The ID of the player.
   */
  sendGameOverToPlayer(playerId) {
    const player = this.gameManager.getPlayerById(playerId);
    if (player) 
      sendMessage(player.socket, 'gameOver', null, 'success', 'Game over', { score: player.score, winner: this.winner === playerId });
  }

  /**
   * Gets the name of a player by their ID.
   * @param {string} playerId - The ID of the player.
   * @returns {string} The name of the player or "unknown" if not found.
   */
  getPlayerNameById(playerId) {
    const player = this.gameManager.getPlayerById(playerId);
    return player ? player.name : "unknown";
  }

  resetGame() {
    this.isStarted = false;
    this.multiplier = 0;
    clearInterval(this.interval);
    if (this.onePiece)
      this.pieceSeries = this.generateOnePieceSeries();
    else
      this.pieceSeries = this.generatePieceSeries();
    this.winner = null;
    this.players.forEach((playerId) => {
      const player = this.gameManager.getPlayerById(playerId);
      if (player) {
        player.resetScore();
        player.gameBoard.initialize(this.pieceSeries);
      }
    });
    this.emitReloadGameSignalToAllPlayers();
  }
}
