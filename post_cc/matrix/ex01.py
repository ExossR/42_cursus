from classes.classes import Vector, Matrix, linear_combination

def main():
    e1 = Vector([1, 0, 0])
    e2 = Vector([0, 1, 0])
    e3 = Vector([0, 0, 1])

    v1 = Vector([1, 2, 3])
    v2 = Vector([0, 10, -100])

    print("1: ", linear_combination([e1, e2, e3], [10, -2, 0.5]))
    print("2: ", linear_combination([v1, v2], [10, -2]))

if __name__ == "__main__":
    main()