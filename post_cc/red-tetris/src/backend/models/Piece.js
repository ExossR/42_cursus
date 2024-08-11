import { TETRIS_SHAPES } from "../constant.js";

/**
 * Represents a Tetris piece.
 */
export class Piece {
  /**
   * Creates a Piece instance.
   * @param {number} shape - The shape identifier of the piece.
   */
  constructor(shape) {
    this.shape = shape;
    this.rotate = 0;
  }

  /**
   * Gets the full position of the piece on the grid, including rows that may be outside the visible grid.
   * @param {number} row - The row position of the piece.
   * @param {number} col - The column position of the piece.
   * @returns {Array<Array<number>>} An array of [row, col] pairs representing the piece's position on the grid.
   */
  getWholePosition(row, col) {
    return TETRIS_SHAPES[this.shape - 1][this.rotate]
      .map(([r, c]) => [r + row, c + col])
  }

  /**
   * Gets the position of the piece on the grid, excluding rows that are outside the visible grid.
   * @param {number} row - The row position of the piece.
   * @param {number} col - The column position of the piece.
   * @returns {Array<Array<number>>} An array of [row, col] pairs representing the piece's position on the grid, excluding rows less than 0.
   */
  getPositionInGrid(row, col) {
    return TETRIS_SHAPES[this.shape - 1][this.rotate]
      .map(([r, c]) => [r + row, c + col])
      .filter(([r, _]) => r >= 0)
  }

  /**
   * Gets the rotated position of the piece on the grid.
   * @param {number} row - The row position of the piece.
   * @param {number} col - The column position of the piece.
   * @returns {Array<Array<number>>} An array of [row, col] pairs representing the piece's rotated position on the grid.
   */
  getRotatedPositionInGrid(row, col) {
    return TETRIS_SHAPES[this.shape - 1][(this.rotate + 1) % 4]
      .map(([r, c]) => [r + row, c + col])
  }
}
