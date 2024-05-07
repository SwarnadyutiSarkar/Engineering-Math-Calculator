import numpy as np
import matplotlib.pyplot as plt

# Define the Euler method for solving ODEs
def euler_method(f, y0, t0, t_end, h):
    t_values = np.arange(t0, t_end + h, h)
    y_values = [y0]

    for t in t_values[1:]:
        y_next = y_values[-1] + h * f(t, y_values[-1])
        y_values.append(y_next)

    return t_values, np.array(y_values)

# Define the function representing the differential equation (example: dy/dt = t*y)
def ode_function(t, y):
    return t * y

# Main function to get user input and solve the ODE
def main():
    # Get user input for initial condition, time range, and step size
    y0 = float(input("Enter the initial condition (y0): "))
    t0 = float(input("Enter the initial time (t0): "))
    t_end = float(input("Enter the end time (t_end): "))
    h = float(input("Enter the step size (h): "))

    # Solve the ODE using Euler method
    t_values, y_values = euler_method(ode_function, y0, t0, t_end, h)

    # Plot the solution
    plt.plot(t_values, y_values, label="Euler Method")
    plt.xlabel("Time (t)")
    plt.ylabel("Solution (y)")
    plt.title("Solution of ODE using Euler Method")
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
