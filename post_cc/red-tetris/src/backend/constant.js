export const TETRIS_ROWS = 20;
export const TETRIS_COLS = 10;

export const SHAPES = {
  I: 1,
  J: 2,
  L: 3,
  O: 4,
  S: 5,
  T: 6,
  Z: 7
}

export const TETRIS_SHAPES = [
  // I
  [
    [[-1, -2], [-1, -1], [-1, 0], [-1, 1]],
    [[-2, 0], [-1, 0], [0, 0], [1, 0]],
    [[0, -2], [0, -1], [0, 0], [0, 1]],
    [[-2, -1], [-1, -1], [0, -1], [1, -1]]
  ],
  // J
  [
    [[0, -1], [0, 0], [0, 1], [-1, 1]],
    [[-1, 0], [0, 0], [1, 0], [1, 1]],
    [[0, -1], [0, 0], [1, -1], [0, 1]],
    [[-1, -1], [-1, 0], [0, 0], [1, 0]],
  ],
  // L
  [
    [[-1, -1], [0, -1], [0, 0], [0, 1]],
    [[-1, 0], [-1, 1], [0, 0], [1, 0]],
    [[0, -1], [0, 0], [0, 1], [1, 1]],
    [[-1, 0], [0, 0], [1, 0], [1, -1]],
  ],
  // O
  [
    [[0, 0], [1, 0], [0, 1], [1, 1]],
    [[0, 0], [1, 0], [0, 1], [1, 1]],
    [[0, 0], [1, 0], [0, 1], [1, 1]],
    [[0, 0], [1, 0], [0, 1], [1, 1]],
  ],
  // S
  [
    [[-1, -1], [-1, 0], [0, 0], [0, 1]],
    [[0, 0], [1, 0], [-1, 1], [0, 1]],
    [[0, -1], [0, 0], [1, 0], [1, 1]],
    [[0, -1], [1, -1], [-1, 0], [0, 0]],
  ],
  // T
  [
    [[-1, 0], [0, -1], [0, 0], [0, 1]],
    [[-1, 0], [0, 0], [1, 0], [0, 1]],
    [[0, -1], [0, 0], [0, 1], [1, 0]],
    [[-1, 0], [0, 0], [1, 0], [0, -1]],
  ],
  // Z
  [
    [[0, -1], [-1, 0], [0, 0], [-1, 1]],
    [[-1, 0], [0, 0], [0, 1], [1, 1]],
    [[1, -1], [0, 0], [1, 0], [0, 1]],
    [[-1, -1], [0, -1], [0, 0], [1, 0]],
  ]
]