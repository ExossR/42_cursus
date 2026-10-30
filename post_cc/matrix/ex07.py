from classes.classes import Matrix, Vector

def main():
    m = Matrix([[1., 0.], [0., 1.]])
    v = Vector([4., 2.])
    print(f"1: {m.mul_vec(v)}")

    m = Matrix([[2., 0.], [0., 2.]])
    v = Vector([4., 2.])
    print(f"2: {m.mul_vec(v)}")

    m = Matrix([[2., -2.], [-2., 2.]])
    v = Vector([4., 2.])
    print(f"3: {m.mul_vec(v)}")

    m0 = Matrix([[1., 0.], [0., 1.]])
    m1 = Matrix([[1., 0.], [0., 1.]])
    print(f"4: {m0.mul_mat(m1)}")

    m0 = Matrix([[1., 0.], [0., 1.]])
    m1 = Matrix([[2., 1.], [4., 2.]])
    print(f"5: {m0.mul_mat(m1)}")

    m0 = Matrix([[3., -5.], [6., 8.]])
    m1 = Matrix([[2., 1.], [4., 2.]])
    print(f"6: {m0.mul_mat(m1)}")

if __name__ == "__main__":
    main()