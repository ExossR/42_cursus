from classes.classes import Matrix

def main():
    m = Matrix([[1., 0., 0.], [0., 1., 0.], [0., 0., 1.]])
    print(f"1: {m.row_echelon()}")

    m = Matrix([[1., 2.], [3., 4.]])
    print(f"2: {m.row_echelon()}")

    m = Matrix([[1., 2.], [2., 4.]])
    print(f"3: {m.row_echelon()}")

    m = Matrix([[8., 5., -2., 4., 28.], [4., 2.5, 20., 4., -4], [8., 5., 1., 4., 17.]])
    print(f"4: {m.row_echelon()}")


if __name__ == "__main__":
    main()