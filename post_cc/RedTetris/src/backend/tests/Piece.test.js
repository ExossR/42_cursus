import { Piece } from '../models/Piece';
import { TETRIS_SHAPES } from '../constant';

describe('Piece', () => {
  let piece;

  beforeEach(() => {
    piece = new Piece(1);
  });

  test('constructor initializes shape and rotation', () => {
    expect(piece.shape).toBe(1);
    expect(piece.rotate).toBe(0);
  });

  test('getWholePosition returns correct transformed positions', () => {
    const row = 5, col = 5;
    const expectedPositions = TETRIS_SHAPES[piece.shape - 1][piece.rotate].map(([r, c]) => [r + row, c + col]);
    expect(piece.getWholePosition(row, col)).toEqual(expectedPositions);
  });

  test('getPositionInGrid filters out positions above the grid', () => {
    const row = 0, col = 0;
    const expectedPositions = TETRIS_SHAPES[piece.shape - 1][piece.rotate]
        .map(([r, c]) => [r + row, c + col])
        .filter(([r, _]) => r >= 0);
    expect(piece.getPositionInGrid(row, col)).toEqual(expectedPositions);
  });
});
