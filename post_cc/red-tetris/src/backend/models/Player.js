import { Board } from './Board.js';
import { TETRIS_ROWS, TETRIS_COLS, SHAPES } from '../constant.js';
import { sendMessage } from '../utils/messaging.js';
import { createObjectCsvWriter } from 'csv-writer';


/**
 * Represents a Tetris player.
 */
export class Player {
  /**
   * Creates a Player instance.
   * @param {object} socket - The socket associated with the player.
   * @param {string} name - The name of the player.
   */
  constructor(socket, name) {
    this.socket = socket;
    this.name = name;
    this.score = 0;
    this.gameBoard = new Board(TETRIS_COLS, TETRIS_ROWS);
    this.game = null;
  }

  /**
   * Adds the player to a game.
   * @param {Game} game - The game instance to add the player to.
   */
  addGame(game) {
    this.game = game;
  }

  /**
   * Gets the shadow grid of the player's board.
   * @returns {Array<Array<number>>} The shadow grid of the player's board.
   */
  getShadowGrid() {
    const shadowGrid = this.gameBoard.grid.map(row => [...row]);

    for (let col = 0; col < this.gameBoard.columns; col++) {
      let pieceFound = false;
      for (let row = 0; row < this.gameBoard.rows; row++) {
        if (shadowGrid[row][col] !== 0) {
          pieceFound = true;
        }
        if (pieceFound) {
          shadowGrid[row][col] = 1;
        }
      }
    }
    return shadowGrid;
  }

  /**
   * Add points to the player's score
      * @param {number} toadd - The number of points to add
  */
  addScore(toadd) {
    this.score += toadd;
  }

  /**
   * Get the player's score
   * @returns {number} The player's score
   */
  getScore() {
    return this.score;
  }

  resetScore() {
    this.score = 0;
  }

  /**
   * Get the player's name
   * @returns {string} The player's name
   */
  getName() {
    return this.name;
  }

  /**
   * Change the player's name
   * @param {string} newName - The new name
   */
  changeName(newName) {
    this.name = newName;
  }

  /**
   * Move the current piece down
   * @returns {boolean} True if the piece has been moved, false otherwise
   */
  moveDown() {
    if (this.gameBoard.gameOver) return false;

    const { row, col } = this.gameBoard.currentPos;
    const positions = this.gameBoard.currentPiece.getWholePosition(row + 1, col);

    if (this.gameBoard.isPositionValid(positions)) {
      this.gameBoard.cleanCurrentPiece();
      this.gameBoard.currentPos.row++;
      positions.forEach(([r, c]) => {
        if (r < 0) return;
        this.gameBoard.grid[r][c] = this.gameBoard.currentPiece.shape;
      });
      return true;
    }
    else {
      this.gameBoard.fixPiece();
      let fullRows = this.gameBoard.clearFullRows();
      if (fullRows.length > 0) {
        if (fullRows.length === 1) {
            this.addScore(40);
        }
        else if (fullRows.length === 2) {
            this.addScore(100);
            this.game.sendMalusToAllPlayersExcept(this.socket.id, 1);
        }
        else if (fullRows.length === 3) {
            this.addScore(300);
            this.game.sendMalusToAllPlayersExcept(this.socket.id, 2);
        }
        else if (fullRows.length === 4) {
            this.addScore(1200);
            this.game.sendMalusToAllPlayersExcept(this.socket.id, 3);
        }
      }
      this.gameBoard.updatePiece();
      if (this.gameBoard.checkGameOver()) {
        sendMessage(this.socket, 'gameOver', null, 'success', 'Game over', { score: this.score, winner: false })
        this.writeScoreToLeaderboard(this.name, this.score);
        return false;
      }
    }
    return false;
  }

  /**
   * Move the current piece to the left or to the right
   * @param {boolean} left - True if the piece has to be moved to the left, false otherwise
   * @returns {boolean} True if the piece has been moved, false otherwise
   */
  moveSide(left) {
    if (this.gameBoard.gameOver) return false;

    const { row, col } = this.gameBoard.currentPos;
    const positions = this.gameBoard.currentPiece.getWholePosition(row, col + (left ? -1 : 1));

    if (this.gameBoard.isPositionValid(positions)) {
      this.gameBoard.cleanCurrentPiece();
      this.gameBoard.currentPos.col += left ? -1 : 1;
      positions.forEach(([r, c]) => {
        if (r < 0) return;
        this.gameBoard.grid[r][c] = this.gameBoard.currentPiece.shape;
      });
      return true;
    }
    return false;
  }

  /**
   * Rotate the current piece
   * @returns {boolean} True if the piece has been rotated, false otherwise
   */
  rotate() {
    if (this.gameBoard.gameOver) return false;

    if (this.gameBoard.currentPiece.shape === SHAPES.O) return true;

    const { row, col } = this.gameBoard.currentPos;
    let rotatedPositions = this.gameBoard.currentPiece.getRotatedPositionInGrid(row, col);

    if (this.gameBoard.isPositionValid(rotatedPositions)) {
      this.gameBoard.cleanCurrentPiece();
      this.gameBoard.currentPiece.rotate = (this.gameBoard.currentPiece.rotate + 1) % 4;
      rotatedPositions.forEach(([r, c]) => {
        if (r < 0) return;
        this.gameBoard.grid[r][c] = this.gameBoard.currentPiece.shape;
      });
      return true;
    }

    const adjustments = [-1, 1];
    for (let i = 0; i < adjustments.length; i++) {
      const adjustedCol = col + adjustments[i];
      rotatedPositions = this.gameBoard.currentPiece.getRotatedPositionInGrid(row, adjustedCol);

      if (this.gameBoard.isPositionValid(rotatedPositions)) {
        this.gameBoard.cleanCurrentPiece();
        this.gameBoard.currentPos.col = adjustedCol;
        this.gameBoard.currentPiece.rotate = (this.gameBoard.currentPiece.rotate + 1) % 4;
        rotatedPositions.forEach(([r, c]) => {
          if (r < 0) return;
          this.gameBoard.grid[r][c] = this.gameBoard.currentPiece.shape;
        });
        return true;
      }
    }

    return false;
  }

  /**
   * Drop the current piece
   * @returns {boolean} True if the piece has been dropped, false otherwise
   */
  hardDrop() {
    if (this.gameBoard.gameOver) return false;

    while (this.moveDown())
      continue;

    return true;
  }

  /**
   * Writes a player's score to the leaderboard.
   * @param {string} playerId - The ID of the player.
   * @param {number} score - The score of the player.
   */
  writeScoreToLeaderboard(playerId, score) {
    const csvWriter = createObjectCsvWriter({
      path: './scores.csv',
      append: true,
      header: [
        { id: 'playerId', title: 'login' },
        { id: 'score', title: 'score' },
      ]
    });

    const data = [{
      playerId: playerId,
      score: score,
    }];

    csvWriter.writeRecords(data)
      .then(() => { })
      .catch(err => {
        console.error('Error writing score to leaderboard:', err);
      });
  }

}

export default Player;
