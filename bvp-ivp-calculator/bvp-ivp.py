from flask import Flask, render_template, request
from scipy.integrate import solve_bvp, solve_ivp
import numpy as np

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/solve', methods=['POST'])
def solve_problem():
    problem_type = request.form['problem_type']
    if problem_type == 'bvp':
        result = solve_bvp_problem(request.form)
    elif problem_type == 'ivp':
        result = solve_ivp_problem(request.form)
    else:
        result = "Invalid problem type"
    return render_template('result.html', result=result)

def solve_bvp_problem(form_data):
    def bvp_equations(x, y):
        dydx = np.zeros((2, len(x)))
        dydx[0] = y[1]
        dydx[1] = -y[0]  # Example equation: y'' + y = 0
        return dydx

    def bvp_boundary_conditions(ya, yb):
        return np.array([ya[0], yb[0]])  # Example boundary conditions: y(0) = 0, y(1) = 0

    x_grid = np.linspace(float(form_data['x_start']), float(form_data['x_end']), int(form_data['num_points']))
    y_init = np.array([float(form_data['y_init_1']), float(form_data['y_init_2'])])
    
    solution = solve_bvp(bvp_equations, bvp_boundary_conditions, x_grid, y_init)
    return solution

def solve_ivp_problem(form_data):
    def ivp_equations(x, y):
        dydx = -y  # Example equation: y' + y = 0
        return dydx

    x_span = (float(form_data['x_start']), float(form_data['x_end']))
    y_init = [float(form_data['y_init'])]

    solution = solve_ivp(ivp_equations, x_span, y_init)
    return solution

if __name__ == '__main__':
    app.run(debug=True)
