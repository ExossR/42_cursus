from typing import List
from .utils import *

class Vector:
    def __init__(self, data: List[float]):
        self.data = data
        self.size = ft_vector_size(data)

    def __str__(self):
        return f"{self.data}"
    
    def __repr__(self):
        return f"{self.data}"

    ## Exercise 00 ##
    def add(self, other: 'Vector') -> 'Vector':
        """Adds two vectors."""
        if not isinstance(other, Vector) or other is None:
            return None
        if self.size != other.size:
            return None
        result_data = [self.data[i] + other.data[i] for i in range(self.size)]
        return Vector(result_data)

    def sub(self, other: 'Vector') -> 'Vector':
        """Subtracts two vectors."""
        if not isinstance(other, Vector) or other is None:
            return None
        if self.size != other.size:
            return None
        result_data = [self.data[i] - other.data[i] for i in range(self.size)]
        return Vector(result_data)

    def scl(self, scalar: float) -> 'Vector':
        """Scales the vector by a scalar."""
        if not isinstance(scalar, (int, float)) or scalar is None:
            return None
        result_data = [item * scalar for item in self.data]
        return Vector(result_data)
    #################

    # Exercice 03
    def dot(self, other: 'Vector') -> float:
        """Computes the dot product of two vectors."""
        if not isinstance(other, Vector) or other is None:
            return None
        if self.size != other.size:
            return None
        result = ft_sum(self.data[i] * other.data[i] for i in range(self.size))
        return result

    ## Exercise 04 ##
    def norm_1(self) -> float:
        """Computes the 1-norm (Manhattan norm) of the vector."""
        if self.size == 0:
            return None
        if any(x is None for x in self.data):
            return None
        return ft_sum(ft_abs(x) for x in self.data)

    def norm(self) -> float:
        """Computes the Euclidean norm (2-norm) of the vector."""
        if self.size == 0:
            return None
        if any(x is None for x in self.data):
            return None
        return ft_sum(x ** 2 for x in self.data) ** 0.5

    def norm_inf(self) -> float:
        """Computes the infinity norm (maximum norm) of the vector."""
        if self.size == 0:
            return None
        if any(x is None for x in self.data):
            return None
        return max(ft_abs(x) for x in self.data)
    #################


class Matrix:
    def __init__(self, data: List[List[float]]):
        self.data = data
        self.rows = ft_matrix_shape(data)[0]
        self.cols = ft_matrix_shape(data)[1]

    def __str__(self):
        return f"{self.data}"

    def __repr__(self):
        return f"{self.data}"

    ## Exercise 00 ##
    def add(self, other: 'Matrix') -> 'Matrix':
        """Adds two matrices."""
        if not isinstance(other, Matrix) or other is None:
            return None
        if self.rows != other.rows or self.cols != other.cols:
            return None
        result_data = [[self.data[i][j] + other.data[i][j] for j in range(self.cols)] for i in range(self.rows)]
        return Matrix(result_data)

    def sub(self, other: 'Matrix') -> 'Matrix':
        """Subtracts two matrices."""
        if not isinstance(other, Matrix) or other is None:
            return None
        if self.rows != other.rows or self.cols != other.cols:
            return None
        result_data = [[self.data[i][j] - other.data[i][j] for j in range(self.cols)] for i in range(self.rows)]
        return Matrix(result_data)

    def scl(self, scalar: float) -> 'Matrix':
        """Scales the matrix by a scalar."""
        if not isinstance(scalar, (int, float)) or scalar is None:
            return None
        result_data = [[item * scalar for item in row] for row in self.data]
        return Matrix(result_data)
    #################

    ## Exercice 07 ##
    def mul_vec(self, vec: Vector) -> Vector:
        """Multiplies the matrix by a vector."""
        if not isinstance(vec, Vector) or vec is None:
            return None
        if self.cols != vec.size:
            return None
        result_data = [ft_sum(self.data[i][j] * vec.data[j] for j in range(self.cols)) for i in range(self.rows)]
        return Vector(result_data)

    def mul_mat(self, other: 'Matrix') -> 'Matrix':
        """Multiplies two matrices."""
        if not isinstance(other, Matrix) or other is None:
            return None
        if self.cols != other.rows:
            return None
        result_data = [[ft_sum(self.data[i][k] * other.data[k][j] for k in range(self.cols)) for j in range(other.cols)] for i in range(self.rows)]
        return Matrix(result_data)
    ###################

    # Exercice 08
    def trace(self) -> float:
        """Computes the trace of the matrix."""
        if self.rows != self.cols:
            return None
        return ft_sum(self.data[i][i] for i in range(self.rows))

    # Exercice 09
    def transpose(self) -> 'Matrix':
        """Computes the transpose of the matrix."""
        return Matrix([[self.data[j][i] for j in range(self.rows)] for i in range(self.cols)])

    # Exercice 10
    def row_echelon(self) -> 'Matrix':
        """Transforms the matrix to row echelon form."""
        if self.rows == 0 or self.cols == 0:
            return None
        data = [row[:] for row in self.data]
        rows = self.rows
        cols = self.cols

        for i in range(rows):
            pvt_idx = next((j for j in range(cols) if data[i][j] != 0), None)

            if pvt_idx is not None:
                pvt = data[i][pvt_idx]
                data[i] = [x / pvt for x in data[i]]

                for j in range(i+1, rows):
                    factor = data[j][pvt_idx]
                    data[j] = [data[j][k] - factor * data[i][k] for k in range(cols)]

        for i in range(rows-1, -1, -1):
            pvt_idx = next((j for j in range(cols) if data[i][j] != 0), None)

            if pvt_idx is not None:
                for j in range(i-1, -1, -1):
                    factor = data[j][pvt_idx]
                    data[j] = [data[j][k] - factor * data[i][k] for k in range(cols)]

        return Matrix(data)

    # Exercice 11
    def determinant(self) -> float:
        """Computes the determinant of the matrix."""
        if self.rows != self.cols or self.rows == 0 or self.rows > 4:
            return None
        if self.rows == 1:
            return self.data[0][0]
        if self.rows == 2:
            return self.data[0][0] * self.data[1][1] - self.data[0][1] * self.data[1][0]
        if self.rows == 3:
            return (self.data[0][0] * self.data[1][1] * self.data[2][2] +
                    self.data[0][1] * self.data[1][2] * self.data[2][0] +
                    self.data[0][2] * self.data[1][0] * self.data[2][1] -
                    self.data[0][2] * self.data[1][1] * self.data[2][0] -
                    self.data[0][1] * self.data[1][0] * self.data[2][2] -
                    self.data[0][0] * self.data[1][2] * self.data[2][1])
        det = 0
        for i in range(self.cols):
            sub_matrix = [row[:i] + row[i+1:] for row in self.data[1:]]
            det += self.data[0][i] * Matrix(sub_matrix).determinant() * (-1) ** i
        return det

    # Exercice 12
    def inverse(self) -> 'Matrix':
        """Computes the inverse of the matrix."""
        if self.rows != self.cols:
            return None
        det = self.determinant()
        if det == 0:
            return ValueError("Matrix is singular and cannot be inverted.")
        if self.rows == 1:
            return Matrix([[1 / self.data[0][0]]])
        if self.rows == 2:
            return Matrix([[self.data[1][1] / det, -self.data[0][1] / det],
                           [-self.data[1][0] / det, self.data[0][0] / det]])
        
        m_i = [[1 if j == i else 0 for j in range(self.rows)] for i in range(self.rows)]
        data = [row[:] for row in self.data]
        for i in range(self.rows):
            pvt_idx = next((j for j in range(self.cols) if data[i][j] != 0), None)
            if pvt_idx is None:
                return None
            pvt = data[i][pvt_idx]
            data[i] = [x / pvt for x in data[i]]
            m_i[i] = [x / pvt for x in m_i[i]]

            for j in range(i + 1, self.rows):
                factor = data[j][pvt_idx]
                data[j] = [data[j][k] - factor * data[i][k] for k in range(self.cols)]
                m_i[j] = [m_i[j][k] - factor * m_i[i][k] for k in range(self.rows)]

        for i in range(self.rows - 1, -1, -1):
            pvt_idx = next((j for j in range(self.cols) if data[i][j] != 0), None)
            if pvt_idx is None:
                return None
            for j in range(i - 1, -1, -1):
                factor = data[j][pvt_idx]
                data[j] = [data[j][k] - factor * data[i][k] for k in range(self.cols)]
                m_i[j] = [m_i[j][k] - factor * m_i[i][k] for k in range(self.rows)]

        return Matrix(m_i)

    # Exercice 13
    def rank(self) -> int:
        """Computes the rank of the matrix."""
        if self.rows == 0 or self.cols == 0:
            return 0
        ref_matrix = self.row_echelon()
        rank = 0
        for i in range(ref_matrix.rows):
           if any(ref_matrix.data[i][j] != 0 for j in range(ref_matrix.cols)):
                rank += 1
        return rank


# Exercice 01
def linear_combination(vectors: List[Vector], scalars: List[float]) -> Vector:
    """Computes the linear combination of vectors with given scalars."""
    if not all(isinstance(v, Vector) for v in vectors) or not all(isinstance(s, (int, float)) for s in scalars):
        return None
    if any(v is None for v in vectors) or any(s is None for s in scalars):
        return None
    if len(vectors) == 0 or len(scalars) == 0:
        return None
    if not all(v.size == vectors[0].size for v in vectors):
        return None
    if len(vectors) != len(scalars):
        return None
    result = Vector([0] * vectors[0].size)
    for i in range(len(vectors)):
        result = result.add(vectors[i].scl(scalars[i]))
    return result

# Exercice 02
def lerp(o1, o2, t: float):
    """Computes the linear interpolation between two vectors or two matrix."""
    if t is None or float(t) < 0 or float(t) > 1:
        return None
    if not (isinstance(o1, Vector) and isinstance(o2, Vector) or (isinstance(o1, Matrix) and isinstance(o2, Matrix))):
        return None
    if isinstance(o1, Vector) and o1.size != o2.size:
        return None
    if isinstance(o1, Matrix) and (o1.rows != o2.rows or o1.cols != o2.cols):
        return None
    return o1.scl(1 - t).add(o2.scl(t))

# Exercice 05
def angle_cos(v1: Vector, v2: Vector) -> float:
    """Computes the cosine of the angle between two vectors"""
    if not isinstance(v1, Vector) or not isinstance(v2, Vector):
        return None
    if v1.size != v2.size or v1.size == 0:
        return None
    dot_product = v1.dot(v2)
    norm_v1 = v1.norm()
    norm_v2 = v2.norm()
    if norm_v1 == 0 or norm_v2 == 0:
        return None
    return f"{dot_product / (norm_v1 * norm_v2):.9f}"

# Exercice 06
def cross_product(v1: Vector, v2: Vector) -> Vector:
    """Computes the cross product of two 3D vectors."""
    if not isinstance(v1, Vector) or not isinstance(v2, Vector):
        return None
    if v1.size != 3 or v2.size != 3:
        return None
    return Vector([
        v1.data[1] * v2.data[2] - v1.data[2] * v2.data[1],
        v1.data[2] * v2.data[0] - v1.data[0] * v2.data[2],
        v1.data[0] * v2.data[1] - v1.data[1] * v2.data[0]
    ])
