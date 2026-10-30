from classes.classes import Matrix

def main():

    m = Matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    print(f"1: {m.transpose()}")

    m = Matrix([[1, 2], [3, 4], [5, 6]])
    print(f"2: {m.transpose()}")

    m = Matrix([[1, 2, 3], [4, 5, 6]])
    print(f"3: {m.transpose()}")

if __name__ == "__main__":
    main()