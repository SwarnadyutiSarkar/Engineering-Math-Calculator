import numpy as np
from scipy.integrate import quad, dblquad, tplquad

# Function for the vector field F(x, y, z) = [P(x, y, z), Q(x, y, z), R(x, y, z)]
def vector_field(x, y, z):
    P = x + y + z
    Q = x * y * z
    R = x**2 + y**2 + z**2
    return P, Q, R

# Line integral of the vector field F along the curve defined by parametric equations x(t), y(t), z(t)
def line_integral(F, x, y, z, a, b):
    integrand = lambda t: np.dot(F(*[f(t) for f in (x, y, z)]), np.array([x(t).derivative(), y(t).derivative(), z(t).derivative()]))
    result, _ = quad(integrand, a, b)
    return result

# Surface integral of the vector field F over the surface defined by the functions x(u, v), y(u, v), z(u, v)
def surface_integral(F, x, y, z, u_min, u_max, v_min, v_max):
    integrand = lambda u, v: np.dot(F(*[f(u, v) for f in (x, y, z)]), np.cross(np.array([x(u, v).derivative(u), y(u, v).derivative(u), z(u, v).derivative(u)]), np.array([x(u, v).derivative(v), y(u, v).derivative(v), z(u, v).derivative(v)])))
    result, _ = dblquad(integrand, u_min, u_max, v_min, v_max)
    return result

# Volume integral of the scalar function f(x, y, z) over the region defined by the functions x(u, v, w), y(u, v, w), z(u, v, w)
def volume_integral(f, x, y, z, u_min, u_max, v_min, v_max, w_min, w_max):
    integrand = lambda u, v, w: f(*[f(u, v, w) for f in (x, y, z)]) * np.abs(np.linalg.det([[x(u, v, w).derivative(u), y(u, v, w).derivative(u), z(u, v, w).derivative(u)], [x(u, v, w).derivative(v), y(u, v, w).derivative(v), z(u, v, w).derivative(v)], [x(u, v, w).derivative(w), y(u, v, w).derivative(w), z(u, v, w).derivative(w)]]))
    result, _ = tplquad(integrand, u_min, u_max, v_min, v_max, w_min, w_max)
    return result

# Example usage
if __name__ == "__main__":
    # Example parametric equations for the curve
    x = lambda t: t
    y = lambda t: t**2
    z = lambda t: t**3
    
    # Example functions for the surface
    x_surface = lambda u, v: u
    y_surface = lambda u, v: v
    z_surface = lambda u, v: u * v
    
    # Example function for volume
    f_volume = lambda x, y, z: x**2 + y**2 + z**2
    
    # Example limits for integrals
    a, b = 0, 1
    u_min, u_max = 0, 1
    v_min, v_max = 0, 1
    w_min, w_max = 0, 1
    
    # Calculate line integral
    F_line_integral = vector_field(x, y, z)
    result_line_integral = line_integral(F_line_integral, x, y, z, a, b)
    print("Line Integral:", result_line_integral)
    
    # Calculate surface integral
    F_surface_integral = vector_field(x_surface, y_surface, z_surface)
    result_surface_integral = surface_integral(F_surface_integral, x_surface, y_surface, z_surface, u_min, u_max, v_min, v_max)
    print("Surface Integral:", result_surface_integral)
    
    # Calculate volume integral
    result_volume_integral = volume_integral(f_volume, x_surface, y_surface, z_surface, u_min, u_max, v_min, v_max, w_min, w_max)
    print("Volume Integral:", result_volume_integral)
