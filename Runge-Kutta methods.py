def runge_kutta(f, x0, y0, h, n):
    """
    Perform numerical integration using the fourth-order Runge-Kutta method.

    Parameters:
    - f: Function representing the first-order ordinary differential equation (ODE) dy/dx = f(x, y)
    - x0: Initial value of x
    - y0: Initial value of y corresponding to x0
    - h: Step size
    - n: Number of steps

    Returns:
    - List of tuples (xi, yi) representing the values of x and y at each step
    """
    result = [(x0, y0)]
    for i in range(1, n + 1):
        k1 = h * f(result[-1][0], result[-1][1])
        k2 = h * f(result[-1][0] + 0.5 * h, result[-1][1] + 0.5 * k1)
        k3 = h * f(result[-1][0] + 0.5 * h, result[-1][1] + 0.5 * k2)
        k4 = h * f(result[-1][0] + h, result[-1][1] + k3)
        y_next = result[-1][1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6
        x_next = x0 + i * h
        result.append((x_next, y_next))
    return result

def main():
    # Input function representing the first-order ODE dy/dx = f(x, y)
    expression = input("Enter the function f(x, y) representing the first-order ODE (use Python syntax): ")
    f = lambda x, y: eval(expression)

    # Input initial values and step size
    x0 = float(input("Enter the initial value of x: "))
    y0 = float(input("Enter the initial value of y corresponding to x0: "))
    h = float(input("Enter the step size (h): "))

    # Input number of steps
    n = int(input("Enter the number of steps: "))

    # Perform numerical integration using the fourth-order Runge-Kutta method
    result = runge_kutta(f, x0, y0, h, n)

    # Display the result
    print("\nResult of numerical integration using the fourth-order Runge-Kutta method:")
    for i, (x, y) in enumerate(result):
        print(f"Step {i + 1}: x = {x}, y = {y}")

if __name__ == "__main__":
    main()
