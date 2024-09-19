import tkinter as tk
from tkinter import messagebox
import sympy as sp

class DifferentiationCalculator:
    def __init__(self, master):
        self.master = master
        master.title("Differentiation Calculator")

        self.label = tk.Label(master, text="Enter a function (in terms of x):")
        self.label.pack()

        self.function_input = tk.Entry(master)
        self.function_input.pack()

        self.differentiate_button = tk.Button(master, text="Differentiate", command=self.differentiate)
        self.differentiate_button.pack()

        self.result_label = tk.Label(master, text="")
        self.result_label.pack()

    def differentiate(self):
        # Get the input function
        function_str = self.function_input.get()

        # Define the variable
        x = sp.symbols('x')

        try:
            # Parse the function and compute the derivative
            function = sp.sympify(function_str)
            derivative = sp.diff(function, x)

            # Display the result
            self.result_label.config(text=f"Derivative: {derivative}")
        except Exception as e:
            messagebox.showerror("Input Error", "Invalid function input. Please enter a valid mathematical expression.")

if __name__ == "__main__":
    root = tk.Tk()
    app = DifferentiationCalculator(root)
    root.mainloop()
