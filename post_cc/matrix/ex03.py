from classes.classes import Vector

def main():
    v1 = Vector([1., 1.])
    v2 = Vector([1., 1.])
    v3 = Vector([-1., 6.])
    v4 = Vector([3., 2.])

    print("1: ", v1.dot(v2))
    print("2: ", v3.dot(v4))

if __name__ == "__main__":
    main()