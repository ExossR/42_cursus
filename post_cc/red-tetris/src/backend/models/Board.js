import { Piece } from './Piece.js';
import { SHAPES, TETRIS_ROWS, TETRIS_COLS } from '../constant.js';

const FIXED = 8;

/**
 * Board class.
 */
export class Board {
    /**
     * Constructor.
     * @param {*} rows - Number of rows.
     * @param {*} columns - Number of columns.
     */
    constructor(r, c) {
      this.rows = r;
      this.columns = c;
      this.grid = this.initializeGrid(r, c);
    }

    /**
     * Initializes the board. Called when a player is added to a game.
     * @param {Array} series - The series of pieces.
     */
    initialize(series) {
      this.rows = TETRIS_ROWS;
      this.columns = TETRIS_COLS;
      this.grid = this.initializeGrid(this.rows, this.columns);
      this.malusLines = 0;
      this.pieceIndex = 0;
      this.pieceSeries = series
      this.currentPiece = this.getPieceAtIndex(this.pieceIndex)
      this.nextPiece = this.getPieceAtIndex(this.pieceIndex + 1)
      this.currentPos = { row: -1, col: Math.floor(this.columns / 2) };
      this.dropInterval = 1000;
      this.intervalId = null;
      this.gameOver = false;
    }

    /**
     * Generates a Tetris piece based on the random string and the index.
     * @param {number} index - The index of the piece to generate.
     * @returns {number} A piece instance
     */
    getPieceAtIndex(index) {
      if (!this.pieceSeries) {
        return new Piece(SHAPES[0]);
      }
      return new Piece(this.pieceSeries[index % this.pieceSeries.length]);
    }

    /**
     * Initializes the grid with empty cells.
     * @param {*} rows - Number of rows.
     * @param {*} columns - Number of columns.
     * @returns
     */
    initializeGrid(rows, columns) {
      const grid = [];
      for (let r = 0; r < rows; r++) {
        const row = [];
        for (let c = 0; c < columns; c++) {
          row.push(0);
        }
        grid.push(row);
      }
      return grid;
    }

    /**
     * Updates the grid with a new grid, and updates the malus lines.
     * @param {*} newGrid - The new grid.
     */
    updateGrid(newGrid) {
      this.grid = newGrid;
    }


    /**
     * Adds malus line(s).
     * @param {number} malus - The number of malus lines to add.
     */
    upgradeMalus(malus) {
      this.malusLines += malus;

      const malusRows = [];
      for (let i = 0; i < malus; i++) {
        const malusRow = new Array(this.columns).fill(9);
        malusRows.push(malusRow);
      }

      this.grid = this.grid.concat(malusRows);

      while (this.grid.length > this.rows) {
        this.grid.shift();
      }
    }

    /**
     * Erase full rows and add empty rows at the top.
     * @returns {number[]} The indexes of the full rows.
     */
    clearFullRows() {
      let fullRows = [];
      this.grid.forEach((row, index) => {
        if (row.every(cell => cell !== 0) && !row.every(cell => cell === 9)) {
          fullRows.push(index);
        }
      });

      const newGrid = this.grid.filter((_, index) => !fullRows.includes(index));

      for (let i = 0; i < fullRows.length; i++) {
        newGrid.unshift(new Array(this.columns).fill(0));
      }

      this.grid = newGrid;
      return fullRows;
    }

    /**
     * Places the current piece on the grid.
     */
    placeCurrentPieceOnGrid() {
      if (!this.currentPiece) {
        return;
      }
      const { row, col } = this.currentPos;
      const positions = this.currentPiece.getPositionInGrid(row, col);
      positions.forEach(([r, c]) => {
        this.grid[r][c] = this.currentPiece.shape;
      });
    }

    /**
     * Removes the current piece from the grid.
     */
    cleanCurrentPiece() {
      const { row, col } = this.currentPos;
      const positions = this.currentPiece.getPositionInGrid(row, col);

      positions.forEach(([r, c]) => {
        this.grid[r][c] = 0;
      });
    }

    /**
     * Checks if the current position of the piece is valid.
     * @param {Array} positions - The positions to check.
     * @returns {boolean} True if the position is valid, false otherwise.
     */
    isPositionValid(positions) {
      return positions.every(([r, c]) =>
        r < this.rows &&
        c >= 0 && c < this.columns &&
        (r < 0 || this.grid[r][c] < FIXED));
    }

    /**
     * Fixes the current piece on the grid.
     */
     fixPiece() {
      const { row, col } = this.currentPos;
      const positions = this.currentPiece.getPositionInGrid(row, col);
      positions.forEach(([r, c]) => {
        this.grid[r][c] = FIXED + this.currentPiece.shape;
      });
      this.pieceIndex++;
    }

    /**
     * Updates the current piece, the next piece and the current position.
     */
    updatePiece() {
      this.pieceIndex + 1 === 99 ? this.pieceIndex = 0 : this.pieceIndex++;
      this.currentPiece = this.nextPiece;
      this.nextPiece = this.getPieceAtIndex(this.pieceIndex + 1);
      this.currentPos = { row: -1, col: Math.floor(this.columns / 2) };
    }

    /**
     * Check if the game is over.
     * @returns {boolean} True if the game is over, false otherwise.
     */
    checkGameOver() {
      if (this.grid[0].some(cell => cell >= FIXED)) {
        clearInterval(this.intervalId);
        this.gameOver = true;
        return true;
      }
      return false;
    }
}
