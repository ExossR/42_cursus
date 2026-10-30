from classes.classes import Matrix

def main():

    m = Matrix([[1., 0.], [0., 1.]])
    print(f"1: {m.trace()}")

    m = Matrix([[2., -5., 0.], [4., 3., 7.], [-2., 3., 4.]])
    print(f"2: {m.trace()}")

    m = Matrix([[-2., -8., 4.], [1., -23., 4.], [0., 6., 4.]])
    print(f"3: {m.trace()}")

if __name__ == "__main__":
    main()