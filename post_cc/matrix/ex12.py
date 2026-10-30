from classes.classes import Matrix

def main():
    m = Matrix([[1., 0., 0.], [0., 1., 0.], [0., 0., 1.]])
    print(f"1: {m.inverse()}")

    m = Matrix([[2., 0., 0.], [0., 2., 0.], [0., 0., 2.]])
    print(f"2: {m.inverse()}")

    m = Matrix([[8., 5., -2.], [4., 7., 20.], [7., 6., 1.]])
    print(f"3: {m.inverse()}")

if __name__ == "__main__":
    main()