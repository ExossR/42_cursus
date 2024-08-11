jest.mock('../utils/messaging', () => ({
  sendMessage: jest.fn(),
  }));

  jest.mock('../models/Game', () => {
  const actualGame = jest.requireActual('../models/Game').Game;
  return {
    Game: jest.fn().mockImplementation(
    function(gameId, owner, difficulty, gameManager) {
      const instance = new actualGame(gameId, owner, difficulty, gameManager);
      instance.addPlayerToGame = jest.fn();
      instance.hasPlayer = jest.fn();
      instance.leaveGame = jest.fn();
      instance.players = [];
      return instance;
    }
    ),
  };
  });


  jest.mock('../models/Player', () => {
  return jest.fn().mockImplementation((socket, name) => ({
    socket,
    name,
    gameBoard: {
    initialize: jest.fn(),
    upgradeMalus: jest.fn(),
    },
    addGame: jest.fn(),
  }));
  });

const { GameManager } = require('../models/GameManager');
const Game = require('../models/Game');
const Player = require('../models/Player');
const { sendMessage } = require('../utils/messaging');

describe('GameManager', () => {
  let manager;

  beforeEach(() => {
    manager = new GameManager();
  });

  test('constructor initializes maps correctly', () => {
    expect(manager.games instanceof Map).toBeTruthy();
    expect(manager.players instanceof Map).toBeTruthy();
  });

  describe('emitRefreshSignalToAllPlayers', () => {
    it('should emit a refresh signal to all connected players', () => {
  const fakeSocket1 = { id: 'socket1' };
  const fakeSocket2 = { id: 'socket2' };
      const player1 = new Player(fakeSocket1, 'Player1');
      const player2 = new Player(fakeSocket2, 'Player2');
      manager.addPlayer(player1);
      manager.addPlayer(player2);
      manager.emitRefreshSignalToAllPlayers();

      expect(sendMessage).toHaveBeenCalledTimes(2);
      expect(sendMessage).toHaveBeenNthCalledWith(1, player1.socket, 'reloadHome', null, 'succes', 'reloadHome');
      expect(sendMessage).toHaveBeenNthCalledWith(2, player2.socket, 'reloadHome', null, 'succes', 'reloadHome');
    });
  });

  describe('createGame', () => {
    it('should create a new game and add the player', () => {
      const player = new Player('socket1', 'Alice');
      manager.addPlayer(player);
      const game = manager.createGame(player.socket.id, 'easy');

      expect(game).toBeDefined();
      expect(manager.games.size).toBe(1);
      expect(game.addPlayerToGame).toHaveBeenCalledWith(player);
    });
  });

  describe('getGames', () => {
    it('should return all games', () => {
      const player1 = new Player('socket1', 'Alice');
      const player2 = new Player('socket2', 'Bob');
      manager.addPlayer(player1);
      manager.addPlayer(player2);
      manager.createGame(player1.socket.id, 'easy');
      manager.createGame(player2.socket.id, 'medium');

      const games = manager.getGames();

      expect(games.length).toBe(2);
    });

  it('should return an empty array if no games exist', () => {
    const games = manager.getGames();
    expect(games.length).toBe(0);
  });
  });

  describe('deleteGame', () => {
    it('should delete a game by id', () => {
      const player = new Player('socket1', 'Alice');
      manager.addPlayer(player);
      const game = manager.createGame(player.socket.id, 'easy');
      const result = manager.deleteGame(game.gameId);

      expect(result).toBeTruthy();
      expect(manager.games.size).toBe(0);
    });

    it('should return false if game does not exist', () => {
      const result = manager.deleteGame('nonexistent');
      expect(result).toBeFalsy();
    });
  });

describe('reset', () => {
  it('should clear all games and players', () => {
    const manager = new GameManager();
    manager.addPlayer(new Player('socket1', 'Player1'));
    manager.createGame('socket1', 'easy');

    expect(manager.getGames().length).toBeGreaterThan(0);
    expect(manager.players.size).toBeGreaterThan(0);

    manager.reset();

    expect(manager.getGames().length).toBe(0);
    expect(manager.players.size).toBe(0);
  });
  });

describe('handlePlayerLeavesRoom', () => {
  it('should handle a player leaving a room correctly', () => {
    const manager = new GameManager();
    const fakeSocket1 = { id: 'socket1' };
    const fakeSocket2 = { id: 'socket2' };
    const player1 = new Player(fakeSocket1, 'Player1');
    const player2 = new Player(fakeSocket2, 'Player2');
    manager.addPlayer(player1);
    manager.addPlayer(player2);
    const game1 = manager.createGame(player1.socket.id, 'easy');
    const game2 = manager.createGame(player2.socket.id, 'medium');
    game1.addPlayerToGame(player2);

    manager.handlePlayerLeavesRoom(player2.socket.id, game1.gameId);

    expect(game1.leaveGame).toHaveBeenCalledWith(player2.socket.id);
    expect(game1.players.length).toBe(0);
  });
  });

describe('getGame', () => {
  it('should return a game by its ID', () => {
    const manager = new GameManager();
    const fakeSocket1 = { id: 'socket1' };
    const player = new Player(fakeSocket1, 'Player1');
    manager.addPlayer(player);
    const game = manager.createGame(player.socket.id, 'easy');
    const result = manager.getGame(game.gameId);
    expect(result.game.gameId).toBe(game.gameId);
  });
  });

});
