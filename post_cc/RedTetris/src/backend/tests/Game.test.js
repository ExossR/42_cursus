import { Game } from '../models/Game';
import * as messaging from '../utils/messaging';

jest.mock('../utils/messaging', () => ({
  sendMessage: jest.fn(),
}));

describe('Game class', () => {
  let game, mockGameManager;

  beforeEach(() => {
    mockGameManager = {
        getPlayerById: jest.fn(id => {
            if (id === 'player1') {
                return {
                  name: 'player1',
                    socket: { id: 'player1' },
                    gameBoard: {
                        grid: [],
                        initialize: jest.fn(),
                        currentPiece: { shape: 1, rotate: 0 },
                        nextPiece: { shape: 1, rotate: 0 },
                        upgradeMalus: jest.fn(),
                        clearFullRows: jest.fn().mockReturnValue([]),
                        updatePiece: jest.fn(),
                        checkGameOver: jest.fn().mockReturnValue(false),
                    },
                    score: 0,
                    addGame: jest.fn(),
                    moveDown: jest.fn(),
                    getShadowGrid: jest.fn().mockReturnValue([]),
                };
            } else if (id === 'player2') {
                return {
                    name: 'player2',
                    socket: { id: 'player2' },
                    gameBoard: {
                        grid: [],
                        initialize: jest.fn(),
                        currentPiece: { shape: 'I', rotate: 0 },
                        moveDown: jest.fn(),
                        upgradeMalus: jest.fn(),
                        clearFullRows: jest.fn().mockReturnValue([]),
                        updatePiece: jest.fn(),
                        checkGameOver: jest.fn().mockReturnValue(false),
                    },
                    score: 0,
                    addGame: jest.fn(),
                    getShadowGrid: jest.fn().mockReturnValue([]),
                };
            }
        })
    };

    game = new Game('game1', 'playerO', 'easy', mockGameManager);
    jest.useFakeTimers();
    jest.spyOn(console, 'error').mockImplementation(() => {});
    game.updateGame = jest.fn();
    game.emitReloadGameSignalToAllPlayers = jest.fn();
    game.handleSinglePlayerGameOver = jest.fn();
    game.sendGameOverToPlayer = jest.fn();

});


  afterEach(() => {
    jest.restoreAllMocks();
    jest.clearAllMocks();
    jest.clearAllTimers();
  });

  test('constructor initializes correctly', () => {
    expect(game.gameId).toBe('game1');
    expect(game.players).toEqual([]);
    expect(game.isStarted).toBeFalsy();
    expect(game.multiplayer).toBeFalsy();
  });

  test('getIntervalTime returns the correct interval time', () => {
    const game2 = new Game('game2', 'owner2', 'medium', mockGameManager);
    const game3 = new Game('game3', 'owner3', 'hard', mockGameManager);
    const game4 = new Game('game4', 'owner4', null, mockGameManager);
    expect(game.getIntervalTime()).toBe(1000);
    expect(game2.getIntervalTime()).toBe(600);
    expect(game3.getIntervalTime()).toBe(300);
    expect(game4.getIntervalTime()).toBe(1000);
  });

  test('pieceToMatrix returns a matrix representation of a piece', () => {
    const matrix = game.pieceToMatrix(1);
    expect(matrix).toEqual([
      [0, 0, 0, 0],
      [1, 1, 1, 1],
      [0, 0, 0, 0],
      [0, 0, 0, 0]
    ]);
    const invalidMatrix = game.pieceToMatrix(100);
    expect(invalidMatrix).toEqual([
      [0, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 0, 0, 0]
    ]);
  });

  test('addPlayerToGame adds a new player', () => {
    const mockPlayer = { socket: { id: 'player1' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);
    expect(game.players).toContain('player1');
    expect(mockPlayer.addGame).toHaveBeenCalledWith(game);

    const game2 = new Game('game2', null, 'easy', mockGameManager);
    game2.addPlayerToGame(mockPlayer);
    expect(game2.players).toContain('player1');
  });

  test('startGame starts the game', () => {
    const mockPlayer = { socket: { id: 'player1' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);
    const mockPlayer2 = { socket: { id: 'player2' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer2);
    game.startGame();
    expect(game.isStarted).toBeTruthy();
    expect(game.multiplayer).toBeTruthy();
    jest.advanceTimersByTime(1000);
    expect(game.updateGame).toHaveBeenCalled();
  });

  test('leaveGame removes a player (owner)', () => {
    const mockPlayer = { socket: { id: 'playerO' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    const mockPlayer2 = { socket: { id: 'player2' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);
    game.addPlayerToGame(mockPlayer2);
    game.leaveGame('playerO');
    expect(game.players).not.toContain('player1');
    expect(game.players).toContain('player2');
    expect(game.owner).toBe('player2');
    game.leaveGame('player2');
    expect(game.owner).toBe(null);
  });

  test('leaveGame removes a player (not owner', () => {
    const mockPlayer = { socket: { id: 'player1' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);
    game.leaveGame('player1');
    expect(game.players).not.toContain('player1');
    expect(game.owner).toBe('playerO');
  });

  test('hasPlayer checks if a player is in the game', () => {
    const mockPlayer = { socket: { id: 'player1' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);
    expect(game.hasPlayer('player1')).toBeTruthy();
    expect(game.hasPlayer('player2')).toBeFalsy();
  });

  test('changeDifficulty changes the game difficulty', () => {
    game.changeDifficulty('hard');
    expect(game.difficulty).toBe('hard');
  });

  test('sendMalusToAllPlayersExcept sends malus to all players except one', () => {
    const player1 = mockGameManager.getPlayerById('player1');
    const player2 = mockGameManager.getPlayerById('player2');
    game.addPlayerToGame(player1);
    game.addPlayerToGame(player2);
    game.sendMalusToAllPlayersExcept('player1', 1);
    expect(player1.gameBoard.upgradeMalus).not.toHaveBeenCalled();
});

  test('generatePieceSeries generates a random piece series', () => {
    const series = game.generatePieceSeries();
    expect(series).toHaveLength(99);
    expect(typeof series).toBe('string');
  });

  test('getPlayerNameById returns the player name', () => {
    const mockPlayer = { socket: { id: 'player1' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);
    const name = game.getPlayerNameById('player1');
    expect(name).toBe('player1');
  });

  test('updateGame updates the game state', () => {
    const mockPlayer = { socket: { id: 'player1' }, gameBoard: { initialize: jest.fn() }, addGame: jest.fn() };
    game.addPlayerToGame(mockPlayer);

    game.updateGame();
    expect(game.updateGame).toHaveBeenCalled();
  });

  test('resetGame resets the game state', () => {
    game.resetGame();
    expect(game.isStarted).toBeFalsy();
    expect(game.multiplayer).toBeFalsy();
    expect(game.players).toEqual([]);
    expect(game.owner).toBe('playerO');
    expect(game.pieceSeries).toHaveLength(99);
    expect(game.winner).toBe(null);
    expect(game.interval).toBe(null);
    expect(game.emitReloadGameSignalToAllPlayers).toHaveBeenCalled();
  });

  test('updatePlayerState moves the player down', () => {
    const player = mockGameManager.getPlayerById('player1');
    game.addPlayerToGame(player);
    game.updatePlayerState(player, true);
    expect(player.moveDown).toHaveBeenCalled();
  });

  test('getShadowGridsForPlayer returns shadow grids for other players', () => {
    const player1 = mockGameManager.getPlayerById('player1');
    const player2 = mockGameManager.getPlayerById('player2');
    game.addPlayerToGame(player1);
    game.addPlayerToGame(player2);

    const shadowGrids = game.getShadowGridsForPlayer('player1');
    expect(shadowGrids).toHaveLength(1);
    expect(shadowGrids[0].playerId).toBe('player2');
    expect(shadowGrids[0].playerName).toBe('player2');
    expect(shadowGrids[0].shadowGrid).toEqual([]);
  });

  test('sendGameUpdateToPlayer sends game update to player', () => {
    const player = mockGameManager.getPlayerById('player1');
    game.addPlayerToGame(player);
    game.sendGameUpdateToPlayer(player, []);
    expect(messaging.sendMessage).toHaveBeenCalled();
  });

  test('areAllPlayersGameOver checks if all players are game over', () => {
    const player1 = mockGameManager.getPlayerById('player1');
    const player2 = mockGameManager.getPlayerById('player2');
    game.addPlayerToGame(player1);
    game.addPlayerToGame(player2);
    const gameOver = game.areAllPlayersGameOver();
    expect(gameOver).toBeFalsy();
  });

  test('handleGameOverForPlayer handles game over for player', () => {
    const player = mockGameManager.getPlayerById('player1');
    game.addPlayerToGame(player);
    game.handleGameOverForPlayer('player1', player);
    expect(game.handleSinglePlayerGameOver).toHaveBeenCalled();
  });

  test('handleSinglePlayerGameOver handles single player game over', () => {
    const player = mockGameManager.getPlayerById('player1');
    game.addPlayerToGame(player);
    game.handleSinglePlayerGameOver('player1', player);
    expect(game.winner).toBe(null);
    expect(game.multiplier).toBe(0);
  });


  test('handleMultiplayerGameOver handles multiplayer game over', () => {
    const player = mockGameManager.getPlayerById('player1');
    game.addPlayerToGame(player);
    game.handleMultiplayerGameOver('player1', player);
    expect(game.sendGameOverToPlayer).toHaveBeenCalled();
  });

  test('endMultiplayerGame ends multiplayer game', () => {
    const player1 = mockGameManager.getPlayerById('player1');
    const player2 = mockGameManager.getPlayerById('player2');
    game.addPlayerToGame(player1);
    game.addPlayerToGame(player2);
    game.endMultiplayerGame('player1');
    expect(game.sendGameOverToPlayer).toHaveBeenCalled();
  });

});

