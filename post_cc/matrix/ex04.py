from classes.classes import Vector

def main():
    v1 = Vector([0., 0., 0.])
    v2 = Vector([1., 2., 3.])
    v3 = Vector([-1., -2.])

    print(F"1: {v1.norm_1()}, {v1.norm()}, {v1.norm_inf()}")
    print(F"2: {v2.norm_1()}, {v2.norm()}, {v2.norm_inf()}")
    print(F"3: {v3.norm_1()}, {v3.norm()}, {v3.norm_inf()}")

if __name__ == "__main__":
    main()