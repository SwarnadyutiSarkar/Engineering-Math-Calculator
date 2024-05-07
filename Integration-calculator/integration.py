from flask import Flask, render_template, request
from sympy import symbols, integrate, oo

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/integrate', methods=['POST'])
def integrate_function():
    expression = request.form['expression']
    variable = symbols(request.form['variable'])
    integration_type = request.form['integration_type']

    if integration_type == 'indefinite':
        result = integrate(expression, variable)
    elif integration_type == 'definite':
        lower_limit = float(request.form['lower_limit'])
        upper_limit = float(request.form['upper_limit'])
        result = integrate(expression, (variable, lower_limit, upper_limit))
    else:
        result = "Invalid integration type."

    return render_template('result.html', result=result)

if __name__ == '__main__':
    app.run(debug=True)
