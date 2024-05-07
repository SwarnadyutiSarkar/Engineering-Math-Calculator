import sympy as sp

def greens_theorem(function, x_range, y_range):
    x, y = sp.symbols('x y')
    fx, fy = function

    # Calculate the partial derivatives
    dfx_dy = sp.diff(fx, y)
    dfy_dx = sp.diff(fy, x)

    # Calculate the line integral using Green's theorem
    integral = sp.integrate(dfx_dy - dfy_dx, (x, x_range[0], x_range[1])) + sp.integrate(dfy_dx - dfx_dy, (y, y_range[0], y_range[1]))
    return integral

def main():
    # Input the components of the vector field F
    fx = input("Enter the x-component of the vector field F: ")
    fy = input("Enter the y-component of the vector field F: ")

    # Parse the input strings as sympy expressions
    fx_expr = sp.sympify(fx)
    fy_expr = sp.sympify(fy)

    # Define the function as a tuple (fx, fy)
    function = (fx_expr, fy_expr)

    # Input the range of integration
    x_start = float(input("Enter the start value of x: "))
    x_end = float(input("Enter the end value of x: "))
    y_start = float(input("Enter the start value of y: "))
    y_end = float(input("Enter the end value of y: "))

    # Calculate the line integral using Green's theorem
    result = greens_theorem(function, (x_start, x_end), (y_start, y_end))
    print("Result of line integral using Green's theorem:", result)

if __name__ == "__main__":
    main()
