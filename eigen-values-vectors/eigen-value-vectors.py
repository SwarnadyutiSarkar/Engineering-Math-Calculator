from flask import Flask, render_template, request
import numpy as np

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate_eigenvalues_eigenvectors():
    try:
        matrix = parse_matrix(request.form['matrix'])
        eigenvalues, eigenvectors = np.linalg.eig(matrix)
        result = {
            'eigenvalues': eigenvalues,
            'eigenvectors': eigenvectors
        }
    except Exception as e:
        result = {'error': str(e)}

    return render_template('result.html', result=result)

def parse_matrix(matrix_string):
    rows = matrix_string.strip().split(';')
    matrix = []
    for row in rows:
        matrix.append([float(val) for val in row.split(',')])
    return np.array(matrix)

if __name__ == '__main__':
    app.run(debug=True)
