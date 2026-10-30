from classes.classes import Matrix

def main():
    m = Matrix([[1., -1.], [-1., 1.]])
    print(f"1: {m.determinant()}")

    m = Matrix([[2., 0., 0.], [0., 2., 0.], [0., 0., 2.]])
    print(f"2: {m.determinant()}")

    m = Matrix([[8., 5., -2.], [4., 7., 20.], [7., 6., 1.]])
    print(f"3: {m.determinant()}")

    m = Matrix([[8., 5., -2., 4.], [4., 2.5, 20., 4.], [8., 5., 1., 4.], [28., -4, 17., 1.]])
    print(f"4: {m.determinant()}")

if __name__ == "__main__":
    main()