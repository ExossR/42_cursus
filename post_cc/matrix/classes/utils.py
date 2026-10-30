def ft_sum(list) -> float:
    """Returns the sum of the elements in the vector."""
    sum = 0
    for x in list:
        sum += x
    return sum

def ft_abs(number: float) -> float:
    """Returns the absolute value of a number."""
    if not isinstance(number, (int, float)) or number is None:
        return -1
    return -number if number < 0 else number

def ft_vector_size(vector: list[float]) -> int:
    """Returns the size of the vector."""
    if not isinstance(vector, list) or vector is None:
        return -1
    return len(vector)

def ft_matrix_shape(matrix: list[list[float]]) -> list[int]:
    """Returns the shape of the matrix as a list of integers."""
    if not isinstance(matrix, list) or matrix is None:
        return -1
    if not all(isinstance(row, list) for row in matrix):
        return -1
    return [len(matrix), len(matrix[0])] if len(matrix) > 0 else [0, 0]