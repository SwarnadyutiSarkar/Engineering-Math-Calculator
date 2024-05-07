from flask import Flask, render_template, request
from sympy import symbols, diff, simplify

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/differentiate', methods=['POST'])
def differentiate():
    expression = request.form['expression']
    variables = request.form['variables'].split(',')
    derivatives = []

    for variable in variables:
        x = symbols(variable)
        derivative = diff(expression, x)
        derivatives.append(derivative)

    result = simplify(derivatives)

    return render_template('result.html', result=result)

if __name__ == '__main__':
    app.run(debug=True)
