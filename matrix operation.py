from flask import Flask, render_template, request
import numpy as np

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    operation = request.form['operation']
    matrix_a = np.matrix(request.form['matrix_a'])
    matrix_b = np.matrix(request.form['matrix_b'])

    result = None
    if operation == 'add':
        result = matrix_a + matrix_b
    elif operation == 'subtract':
        result = matrix_a - matrix_b
    elif operation == 'multiply':
        result = np.dot(matrix_a, matrix_b)
    elif operation == 'divide':
        # Division is not typically defined for matrices, but you can perform element-wise division
        result = np.divide(matrix_a, matrix_b)

    return render_template('result.html', result=result)

if __name__ == '__main__':
    app.run(debug=True)
