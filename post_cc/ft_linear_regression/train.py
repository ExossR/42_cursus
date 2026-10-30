import matplotlib.pyplot as plt
import polars as pl
import numpy as np
import json
from predict import estimatePrice


def plotRegressionLine(mileage, price, theta0, theta1, mileage_norm=None, price_norm=None, title=None):
        plt.figure(figsize=(10, 8))

        # Plot regression line
        # Normalized data
        if (mileage_norm and price_norm):
            plt.subplot(2, 2, 1)
            plt.scatter(mileage_norm, price_norm, label="Data")
            plt.plot(mileage_norm, [estimatePrice(x, theta0, theta1) for x in mileage_norm], color='red', label="Regression Line")
            plt.xlabel("Mileage")
            plt.ylabel("Price")
            plt.legend()
            plt.title("Normalized")
            if (title):
                plt.title(f'Normalize {title}')

        # Denormalized data
        if (mileage_norm and price_norm):
            plt.subplot(2, 2, 3)
        else:
            plt.subplot(2, 2, 1)
        plt.scatter(mileage, price, label="Data")
        if (mileage_norm and price_norm):
            plt.plot(mileage, [estimatePrice((x - mileage.mean()) / mileage.std(), theta0, theta1) * price.std() + price.mean() for x in mileage], color='red', label="Regression Line")
        plt.xlabel("Mileage")
        plt.ylabel("Price")
        plt.legend()
        if (mileage_norm and price_norm):
            plt.title("Non-Normalized")
            if (title):
                plt.title(f'Non-Normalized {title}')

        plt.tight_layout()
        plt.show()

def plotCost(nb_iterations, costs):
    # Plot learning curve
    plt.subplot(1, 1, 1)
    plt.plot(range(nb_iterations), costs, label="Cost")
    plt.xlabel("Iteration")
    plt.ylabel("Cost")
    plt.title("Learning Curve")
    plt.legend()

    plt.tight_layout()
    plt.show()

def train(df, t0, t1, learningRate):
    m = len(df)
    sumErrorT0 = 0
    sumErrorT1 = 0
    cost = 0
    predictions = []

    for ex in df.iter_rows(named=True):
        mileage = ex["km"]
        price = ex["price"]

        prediction = estimatePrice(mileage, t0, t1)
        error = prediction - price

        predictions.append(prediction)
        cost += error ** 2
        sumErrorT0 += error
        sumErrorT1 += error * mileage

    t0 -= learningRate * (1 / m) * sumErrorT0
    t1 -= learningRate * (1 / m) * sumErrorT1
    cost = (1 / (2 * m)) * cost

    return (t0, t1, cost, predictions)

def check_input_learningRate(lr):
    try:
        lr = float(lr)
        if (lr >1 or lr <= 0.00001):
            lr = 0.01
    except:
        print("Invalid input for learning rate")
        exit(1)
    return (lr)

def check_input_nb_iterations(nb):
    try:
        nb = int(nb)
        if (nb <= 0):
            nb = 100
    except:
        print("Invalid input for number of iterations")
        exit(1)
    return (nb)

def denormalize(df, theta0, theta1):
    mileage = np.array(df.select(pl.col("km")).to_numpy())
    price = np.array(df.select(pl.col("price")).to_numpy())

    t0 = theta0 * price.std() + price.mean() - (theta1 * price.std() * mileage.mean() / mileage.std())
    t1 = theta1 * price.std() / mileage.std()
    return (t0, t1)

def coef_determination(y, pred):
    y = [float(x) for x in y]
    pred = [float(x) for x in pred]
    y = np.array(y)
    pred = np.array(pred)
    u = ((y - pred) ** 2).sum()
    v = ((y - y.mean()) ** 2).sum()
    return (1 - u / v)

def calculate_mae_rmse(y, pred, y_denorm):
    y = [float(x) for x in y]
    y_denorm = [float(x) for x in y_denorm]
    pred = [float(x) for x in pred]
    y = np.array(y)
    y_denorm = np.array(y_denorm)
    pred = np.array(pred)
    pred_denorm = pred * y_denorm.std() + y_denorm.mean()
    mae = (abs(y_denorm - pred_denorm)).mean()
    rmse = np.sqrt(((y - pred) ** 2).mean())
    return (mae, rmse)

def main():
    df = pl.read_csv("data.csv")
    mileage = np.array(df.select(pl.col("km")).to_numpy())
    price = np.array(df.select(pl.col("price")).to_numpy())

    mileage_norm = (mileage - mileage.mean()) / mileage.std()
    price_norm = (price - price.mean()) / price.std()

    mileage_norm = [m[0] for m in mileage_norm]
    price_norm = [p[0] for p in price_norm]

    df_norm = pl.DataFrame({"km":mileage_norm, "price":price_norm})

    with open("thetas.json", "r") as f:
        thetas = json.load(f)
    theta0 = thetas["theta0"]
    theta1 = thetas["theta1"]

    # show examples
    plotRegressionLine(mileage, price, theta0, theta1)

    learningRate = check_input_learningRate(input("Enter learning rate: "))
    nb_iterations = check_input_nb_iterations(input("Enter number of iterations: "))
    costs = []
    pred = []

    for i in range(nb_iterations):
        theta0, theta1, cost, pred = train(df_norm, theta0, theta1, learningRate)
        costs.append(cost)
        if (i == nb_iterations // 4 or i == nb_iterations // 2 or i == 3 * nb_iterations // 4):
            plotRegressionLine(mileage, price, theta0, theta1, mileage_norm, price_norm, f"Iteration {i}")

    mae, rmse = calculate_mae_rmse(price_norm, pred, price)
    print(f"Coef determination: {coef_determination(price_norm, pred)}")
    print(f"Mean Absolute Error (MAE): {mae}€")
    print(f"Root-Mean Square Error (RMSE): {rmse}")
    plotRegressionLine(mileage, price, theta0, theta1, mileage_norm, price_norm)
    plotCost(nb_iterations, costs)

    print(f"Final theta0: {theta0}, theta1: {theta1}")
    theta0_denormalize, theta1_denormalize = denormalize(df, theta0, theta1)
    print(f"Final theta0 denormalized: {theta0_denormalize}, theta1 denormalised: {theta1_denormalize}")

    with open("thetas.json", "w") as f:
        json.dump({"theta0": theta0_denormalize, "theta1": theta1_denormalize, 
                    "theta0_normalize": theta0, "theta1_normalize": theta1}, f)


if __name__ == "__main__":
    main()
