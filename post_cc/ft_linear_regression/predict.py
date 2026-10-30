import numpy as np
import polars as pl
import json

def estimatePrice(mileage, theta0, theta1):
    return float(theta0) + (float(theta1) * mileage)

def check_input(f, mileage):
    try:
        x = f(mileage)
    except:
        print("Invalid input")
        exit(1)
    return (x)

def predict():
    df = pl.read_csv("data.csv")

    with open("thetas.json", "r") as f:
        thetas = json.load(f)
        theta0 = thetas["theta0"]
        theta1 = thetas["theta1"]

    mileage = check_input(float, input("Enter a mileage: "))

    # Calculate estimated price
    estimated_price = estimatePrice(mileage, theta0, theta1)
    if (estimated_price < 0):
        estimated_price = 0

    print(f"Estimated price for {int(mileage)} km: {estimated_price:.2f} €")

if __name__ == "__main__":
    predict()