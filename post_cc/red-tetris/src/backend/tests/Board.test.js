import { Board } from '../models/Board';
import { Piece } from '../models/Piece';

const FIXED = 8;

describe('Board', () => {
  let board;
  const rows = 20;
  const cols = 10;

  beforeEach(() => {
    board = new Board(rows, cols);
  });

  test('constructor initializes rows and columns', () => {
    expect(board.rows).toBe(rows);
    expect(board.columns).toBe(cols);
    expect(board.grid.length).toBe(rows);
    expect(board.grid.every(row => row.length === cols)).toBe(true);
  });

  test('initialize method sets up initial conditions correctly', () => {
    const series = [1, 2, 3];
    board.initialize(series);
    expect(board.pieceSeries).toEqual(series);
    expect(board.currentPiece).toBeDefined();
    expect(board.nextPiece).toBeDefined();
    expect(board.grid.every(row => row.every(cell => cell === 0))).toBe(true);
  });

  test('getPieceAtIndex returns a new Piece instance', () => {
    const index = 0;
    const piece = board.getPieceAtIndex(index);
    expect(piece).toBeInstanceOf(Piece);
  });

  test('initializeGrid fills grid with zeros', () => {
    const newGrid = board.initializeGrid(rows, cols);
    expect(newGrid.length).toBe(rows);
    expect(newGrid.every(row => row.every(cell => cell === 0))).toBe(true);
  });

  test('updateGrid updates the grid', () => {
    const newGrid = Array.from({ length: rows }, () => Array.from({ length: cols }, () => 1));
    board.updateGrid(newGrid);
    expect(board.grid).toEqual(newGrid);
  });

  test('upgradeMalus adds malus lines correctly', () => {
    const malus = 2;
    board.upgradeMalus(malus);
    expect(board.grid.slice(-malus).every(row => row.every(cell => cell === 9))).toBe(true);
  });

  test('clearFullRows removes full rows and adds empty rows', () => {
    board.grid[10] = new Array(cols).fill(1);
    const fullRows = board.clearFullRows();
    expect(fullRows).toContain(10);
    expect(board.grid[0].every(cell => cell === 0)).toBe(true);
  });

  test('placeCurrentPieceOnGrid places a piece on the grid', () => {
    board.currentPiece = new Piece(1);
    board.currentPos = { row: 0, col: 0 };
    board.placeCurrentPieceOnGrid();
    expect(board.grid[0][0]).toBe(0);
    board.currentPiece = null;
    board.placeCurrentPieceOnGrid();
    expect(board.grid[0][0]).toBe(0);
  });

  test('cleanCurrentPiece removes the piece from the grid', () => {
    board.currentPiece = new Piece(1);
    board.currentPos = { row: 0, col: 0 };
    board.placeCurrentPieceOnGrid();
    board.cleanCurrentPiece();
    expect(board.grid[0][0]).toBe(0);
  });

  test('isPositionValid returns true for valid positions', () => {
    expect(board.isPositionValid([[0, 0]])).toBe(true);
  });

  test('fixPiece fixes a piece on the grid', () => {
    board.currentPiece = new Piece(1);
    board.currentPos = { row: 0, col: 0 };
    board.fixPiece();
    expect(board.grid[1][0]).toBe(0);
  });

  test('updatePiece updates current and next pieces', () => {
    board.initialize([1, 2, 3, 4, 5, 6, 7]);
    board.updatePiece();
    expect(board.currentPiece.shape).toBe(2);
    expect(board.nextPiece.shape).toBe(3);
  });

  test('checkGameOver checks if game is over when top row is occupied', () => {
    board.grid[0][0] = FIXED;
    expect(board.checkGameOver()).toBe(true);
    board.grid[0][0] = 0;
    expect(board.checkGameOver()).toBe(false);
  });
});
