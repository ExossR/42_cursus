import { sendMessage } from '../utils/messaging.js';
import { Game } from './Game.js';
import { Player } from './Player.js';

/**
 * Manages multiple game instances.
 */
export class GameManager {
  /**
   * Creates a GameManager instance.
   */
  constructor() {
    this.games = new Map(); // Map pour stocker les parties par ID
    this.players = new Map(); // Map pour stocker les joueurs par socket ID
  }

  /**
   * Sends a signal to all connected players to refresh the game list.
   */
  emitRefreshSignalToAllPlayers() {
    for (const player of this.players.values()) {
        sendMessage(player.socket, 'reloadHome', null, 'succes', 'reloadHome');
      }
    }

  /**
   * Creates a new game, adds it to the games map, adds the player to the game, and returns the game instance.
   * @param {string} playerId - The unique identifier for the player creating the game.
   * @param {string} difficulty - The difficulty level of the game.
   * @returns {Game|null} The newly created game instance or null if the player is already in a game.
   */
  createGame(playerId, difficulty) {
    if (this.games.size > 0) {
      for (const game of this.games.values()) {
        if (game.players.some(player => player.id === playerId)) {
          return null;
        }
      }
    }
    const gameId = this.getUniqueGameId();
    const newGame = new Game(gameId, playerId, difficulty, this);
    this.games.set(newGame.gameId, newGame);
    const player = this.getPlayerById(playerId);

    newGame.addPlayerToGame(player);

    this.emitRefreshSignalToAllPlayers();

    return newGame;
  }

  /**
   * Retrieves all existing games.
   * @returns {Array<Game>} An array of all game instances.
   */
  getGames() {
    return Array.from(this.games.values()).map(game => {
      const owner = this.getPlayerById(game.owner);
      return {
        isStarted: game.isStarted,
        gameId: game.gameId,
        owner: owner ? owner.name : 'Unknown',
        players: game.players.length
      };
    });
    // return Array.from(this.games.values());
  }

  /**
   * Retrieves a game by its ID.
   * @param {string} gameId - The unique identifier of the game to retrieve.
   * @returns {object|null} An object containing the game and its players, or null if the game does not exist.
   */
  getGame(gameId) {
    const game = this.games.get(gameId);
    if (!game) {
      return null;
    }

    const players = game.players.map(playerId => {
      const player = this.getPlayerById(playerId);
      return player ? { id: playerId, name: player.name } : { id: playerId, name: 'Unknown' };
    });

    return {
      game: game,
      players: players
    };
  }

  /**
   * Deletes an existing game by its ID.
   * @param {string} gameId - The unique identifier of the game to delete.
   * @returns {boolean} True if the game was deleted, false if the game was not found.
   */
  deleteGame(gameId) {
    if (!this.games.has(gameId)) {
      return false;
    }
    this.games.delete(gameId);
    return true;
  }

  /**
   * Adds a player to the players map.
   * @param {Player} player - The player to add to the map.
   */
  addPlayer(player) {
    this.players.set(player.socket.id, player);
  }

  /**
   * Generate a unique game ID.
   * @returns {string} A unique game ID.
   */
   getUniqueGameId() {
    let gameId;
    do {
      gameId = Math.random().toString(36).substr(2, 9);
    } while (this.games.has(gameId));
    return gameId;
  }

  /**
   * Resets the game manager.
   */
  reset() {
    this.games.clear();
    this.players.clear();
  }

  /**
   * Retrieves a player by its ID.
   * @param {string} playerId - The unique identifier of the player to retrieve.
   * @returns {Player} The player instance associated with the given ID.
   */
  getPlayerById(socketId) {
    return this.players.get(socketId);
}

  /**
   * Handles a player leaving a room.
   * @param {string} playerId - The unique identifier of the player leaving the room.
   * @param {string} gameId - The unique identifier of the game.
   */
  handlePlayerLeavesRoom(playerId, gameId) {
    const game = this.games.get(gameId);
    if (game) {
      game.leaveGame(playerId);
      if (game.players.length === 0) {
        this.emitRefreshSignalToAllPlayers();
        this.deleteGame(gameId);
      }
    }
  }


  /**
   * Handles a player disconnecting from the server.
   * @param {string} playerId - The unique identifier of the player who disconnected.
   */
  handlePlayerDisconnect(playerId) {
    this.games.forEach((game, gameId) => {
      if (game.hasPlayer(playerId)) {
        game.leaveGame(playerId);
        if (game.players.length === 0) {
          this.emitRefreshSignalToAllPlayers();
          this.deleteGame(gameId);
        }
      }
    });
    this.players.delete(playerId);
  }
}
