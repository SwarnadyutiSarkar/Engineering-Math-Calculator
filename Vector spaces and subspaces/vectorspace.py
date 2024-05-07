from flask import Flask, render_template, request
import numpy as np

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    operation = request.form['operation']
    vectors = request.form.getlist('vector')

    try:
        vectors = [np.array(eval(v)) for v in vectors]
        result = perform_operation(operation, vectors)
    except Exception as e:
        result = f"Error: {e}"

    return render_template('result.html', result=result)

def perform_operation(operation, vectors):
    if operation == 'addition':
        result = np.sum(vectors, axis=0)
    elif operation == 'subtraction':
        result = np.subtract(vectors[0], vectors[1])
    elif operation == 'scalar_multiplication':
        scalar = float(request.form['scalar'])
        result = scalar * vectors[0]
    elif operation == 'dot_product':
        result = np.dot(vectors[0], vectors[1])
    elif operation == 'cross_product':
        result = np.cross(vectors[0], vectors[1])
    elif operation == 'magnitude':
        result = np.linalg.norm(vectors[0])
    else:
        result = "Invalid operation"
    return result

if __name__ == '__main__':
    app.run(debug=True)
