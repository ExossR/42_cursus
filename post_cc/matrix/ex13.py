from classes.classes import Matrix

def main():
    m = Matrix([[1., 0., 0.], [0., 1., 0.], [0., 0., 1.]])
    print(f"1: {m.rank()}")

    m = Matrix([[1., 2., 0., 0.], [2., 4., 0., 0.], [-1., 2., 1., 1.]])
    print(f"2: {m.rank()}")

    m = Matrix([[8., 5., -2.], [4., 7., 20.], [7., 6., 1.], [21., 18., 7.]])
    print(f"3: {m.rank()}")


if __name__ == "__main__":
    main()