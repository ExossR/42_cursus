from classes.classes import Vector, cross_product

def main():
    v1 = Vector([0., 0., 1.])
    v2 = Vector([1., 0., 0.])
    print(F"1: {cross_product(v1, v2)}") 

    v3 = Vector([1., 2., 3.])
    v4 = Vector([4., 5., 6.])
    print(F"1: {cross_product(v3, v4)}")

    v5 = Vector([4., 2., -3.])
    v6 = Vector([-2., -5., 16.])
    print(F"1: {cross_product(v5, v6)}")  

if __name__ == "__main__":
    main()