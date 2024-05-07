import sympy as sp

def gradient(vector_field):
    variables = sp.symbols('x y z')
    gradient_vector = [sp.diff(component, var) for component, var in zip(vector_field, variables)]
    return gradient_vector

def divergence(vector_field):
    variables = sp.symbols('x y z')
    divergence_scalar = sum(sp.diff(component, var) for component, var in zip(vector_field, variables))
    return divergence_scalar

def curl(vector_field):
    variables = sp.symbols('x y z')
    curl_vector = [
        sp.diff(vector_field[2], variables[1]) - sp.diff(vector_field[1], variables[2]),
        sp.diff(vector_field[0], variables[2]) - sp.diff(vector_field[2], variables[0]),
        sp.diff(vector_field[1], variables[0]) - sp.diff(vector_field[0], variables[1])
    ]
    return curl_vector

def main():
    # Input vector field
    vector_field = [sp.sympify(input(f"Enter component {i+1} of the vector field: ")) for i in range(3)]

    # Calculate and display gradient
    print("\nGradient:")
    gradient_vector = gradient(vector_field)
    for i, component in enumerate(gradient_vector):
        print(f"Component {i+1}: {component}")

    # Calculate and display divergence
    print("\nDivergence:")
    divergence_scalar = divergence(vector_field)
    print(divergence_scalar)

    # Calculate and display curl
    print("\nCurl:")
    curl_vector = curl(vector_field)
    for i, component in enumerate(curl_vector):
        print(f"Component {i+1}: {component}")

if __name__ == "__main__":
    main()
