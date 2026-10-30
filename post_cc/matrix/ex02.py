from classes.classes import Vector, Matrix, lerp

def main():
    v1 = Vector([1, 8, 5])
    v2 = Vector([5, 6, -1])

    m1 = Matrix([[1, 2], [44, 63]])
    m2 = Matrix([[50, 25], [32, -47]])

    print("1: ", lerp(v1, v2, 0.5))
    print("2: ", lerp(m1, m2, 0.30))

if __name__ == "__main__":
    main()