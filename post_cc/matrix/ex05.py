from classes.classes import Vector, angle_cos

def main():
    v1 = Vector([1., 0.])
    v2 = Vector([1., 0.])
    print(F"1: {angle_cos(v1, v2)}")  # Should print 1.0

    v3 = Vector([1., 0.])
    v4 = Vector([0., 1.])
    print(F"2: {angle_cos(v3, v4)}")  # Should print 0.0

    v5 = Vector([-1., 1.])
    v6 = Vector([1., -1.])
    print(F"3: {angle_cos(v5, v6)}")  # Should print -1.0

    v7 = Vector([2., 1.])
    v8 = Vector([4., 2.])
    print(F"4: {angle_cos(v7, v8)}")  # Should print 1.0

    v9 = Vector([1., 2., 3.])
    v10 = Vector([4., 5., 6.])
    print(F"5: {angle_cos(v9, v10)}")  # Should print 0.9746318461970762


if __name__ == "__main__":
    main()