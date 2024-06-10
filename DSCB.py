import numpy as np
import matplotlib.pyplot as plt

def double_sided_crystal_ball(x, alpha_l, alpha_r, mean, sigma, n_l, n_r):
    """
    Compute the double-sided crystal ball function for given parameters.
    """
    z = (x - mean) / sigma
    if z < -alpha_l:
        return np.exp(-0.5 * alpha_l**2)
    elif z > alpha_r:
        return np.exp(-0.5 * alpha_r**2)
    else:
        return np.exp(-0.5 * z**2) * ((n_l if z < 0 else n_r) - abs(z))**-alpha_l

# Define parameters
alpha_l = 1.5
alpha_r = 2.0
mean = 0.0
sigma = 1.0
n_l = 1.0
n_r = 1.0

# Create x values
x_values = np.linspace(-5, 5, 100)

# Compute y values
y_values = [double_sided_crystal_ball(x, alpha_l, alpha_r, mean, sigma, n_l, n_r) for x in x_values]

# Plot
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, label=f'Double-Sided Crystal Ball Function')
plt.title('Double-Sided Crystal Ball Function')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid(True)
plt.show()

