import tkinter as tk
from tkinter import messagebox
import numpy as np
from scipy.integrate import quad

class IntegrationCalculator:
    def __init__(self, master):
        self.master = master
        master.title("Advanced Integration Calculator")

        # Input function label and entry
        self.label_function = tk.Label(master, text="Enter function of x (e.g., np.sin(x), x**2):")
        self.label_function.pack()

        self.function_entry = tk.Entry(master)
        self.function_entry.pack()

        # Lower limit label and entry
        self.label_lower = tk.Label(master, text="Enter lower limit:")
        self.label_lower.pack()

        self.lower_entry = tk.Entry(master)
        self.lower_entry.pack()

        # Upper limit label and entry
        self.label_upper = tk.Label(master, text="Enter upper limit:")
        self.label_upper.pack()

        self.upper_entry = tk.Entry(master)
        self.upper_entry.pack()

        # Calculate button
        self.calculate_button = tk.Button(master, text="Calculate Integral", command=self.calculate_integral)
        self.calculate_button.pack()

        # Result label
        self.result_label = tk.Label(master, text="")
        self.result_label.pack()

    def calculate_integral(self):
        function_str = self.function_entry.get()
        lower_limit = self.lower_entry.get()
        upper_limit = self.upper_entry.get()

        try:
            # Convert limits to float
            lower_limit = float(lower_limit)
            upper_limit = float(upper_limit)

            # Define the function using eval
            func = lambda x: eval(function_str)

            # Calculate the integral
            result, error = quad(func, lower_limit, upper_limit)

            # Display the result
            self.result_label.config(text=f"Integral: {result:.4f} (Error estimate: {error:.4e})")

        except Exception as e:
            messagebox.showerror("Error", f"Invalid input: {e}")

if __name__ == "__main__":
    root = tk.Tk()
    app = IntegrationCalculator(root)
    root.mainloop()
