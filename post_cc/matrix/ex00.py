from classes.classes import Vector, Matrix

def main():
    # Example usage
    vector1 = Vector([1, 2, 3])
    vector2 = Vector([4, 5, 6])
    
    matrix1 = Matrix([[1, 2], [3, 4]])
    matrix2 = Matrix([[5, 6], [7, 8]])
    
    # Vector operations
    print("Vector Addition:", vector1.add(vector2))
    print("Vector Subtraction:", vector1.sub(vector2))
    print("Vector Scaling:", vector1.scl(2))
    
    # Matrix operations
    print("Matrix Addition:", matrix1.add(matrix2))
    print("Matrix Subtraction:", matrix1.sub(matrix2))
    print("Matrix Scaling:", matrix1.scl(2))

if __name__ == "__main__":
    main()