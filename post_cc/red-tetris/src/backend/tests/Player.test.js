import { Player } from '../models/Player';
import { Board } from '../models/Board';
import { SHAPES, TETRIS_ROWS, TETRIS_COLS } from '../constant';

describe('Player class tests', () => {
  let player;

  beforeEach(() => {
    player = new Player("test", "TestPlayer");
    player.gameBoard = new Board(TETRIS_COLS, TETRIS_ROWS);
    player.gameBoard.initialize(['1', '2', '3']);
    player.gameBoard.fixPiece = jest.fn();
    player.gameBoard.checkGameOver = jest.fn();
    player.addScore = jest.fn();
    player.game = {
      sendMalusToAllPlayersExcept: jest.fn(),
    };
  });

  test('Player initialization', () => {
    expect(player.name).toBe("TestPlayer");
    expect(player.score).toBe(0);
    expect(player.gameBoard).toBeInstanceOf(Board);
  });

  test('test addGame', () => {
	player.addGame("testGame");
	expect(player.game).toBe("testGame");
  });

  test('getShadowGrid should return a grid with the shadow of the current piece', () => {
	const shadowGrid = player.getShadowGrid();
	expect(shadowGrid).toEqual(player.gameBoard.grid);
	});

  test('addScore should increase the score by the specified amount', () => {
    const mockPlayer = new Player("test", "TestPlayer");
    mockPlayer.addScore(100);
    expect(mockPlayer.score).toBe(100);
  });

  test('getScore should return the player\'s score', () => {
	expect(player.getScore()).toBe(0);
  });

  test('rotate should rotate the piece if possible', () => {
    const canRotate = player.rotate();
    expect(canRotate).toBe(true);
  });

  test('getName should return the player\'s name', () => {
    expect(player.getName()).toBe("TestPlayer");
  });

  test('changeName should change the player\'s name', () => {
    player.changeName("NewName");
    expect(player.getName()).toBe("NewName");
  });

  test('moveDown should move the piece down if possible', () => {
    const moved = player.moveDown();
    expect(moved).toBe(true);

  });

  test('moveDown should return false if the piece cannot move down and fix piece', () => {
    player.gameBoard.currentPos.row = TETRIS_ROWS + 1;
    const moved = player.moveDown();
    expect(moved).toBe(false);
    expect(player.gameBoard.fixPiece).toHaveBeenCalled();
    expect(player.gameBoard.checkGameOver).toHaveBeenCalled();
  });

  test.each([
    { fullRows: [0], expectedScore: 40, malus: 0 },
    { fullRows: [0, 1], expectedScore: 100, malus: 1 },
    { fullRows: [0, 1, 2], expectedScore: 300, malus: 2 },
    { fullRows: [0, 1, 2, 3], expectedScore: 1200, malus: 3 }
  ])('should add $expectedScore points and send $malus lines malus for $fullRows.length full rows',
    ({ fullRows, expectedScore, malus }) => {
      player.gameBoard.currentPos.row = TETRIS_ROWS + 1;
      player.gameBoard.clearFullRows = jest.fn().mockReturnValue(fullRows);
      player.moveDown();

      expect(player.addScore).toHaveBeenCalledWith(expectedScore);
      if (malus > 0) {
        expect(player.game.sendMalusToAllPlayersExcept).toHaveBeenCalledWith(player.socket.id, malus);
      } else {
        expect(player.game.sendMalusToAllPlayersExcept).not.toHaveBeenCalled();
      }
    });

  test('moveSide should move the piece to the side if possible', () => {
    const moved = player.moveSide(1);
    expect(moved).toBe(true);
    player.gameBoard.currentPos.col = TETRIS_COLS + 1;
    const moved2 = player.moveSide(1);
    expect(moved2).toBe(false);
  });

  test('hardDrop should move the piece to the bottom', () => {
    player.hardDrop();
    expect(player.gameBoard.fixPiece).toHaveBeenCalled();
  });
});
