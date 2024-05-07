import numpy as np
import matplotlib.pyplot as plt

def central_limit_theorem(sample_size, num_samples, distribution='uniform', dist_params=None):
    if dist_params is None:
        dist_params = {}
    
    # Generate samples
    samples = []
    for _ in range(num_samples):
        if distribution == 'uniform':
            sample = np.random.uniform(**dist_params, size=sample_size)
        elif distribution == 'normal':
            sample = np.random.normal(**dist_params, size=sample_size)
        else:
            raise ValueError("Unsupported distribution")

        samples.append(np.mean(sample))

    return samples

def plot_distribution(samples):
    plt.hist(samples, bins=30, density=True, alpha=0.6, color='b')
    plt.xlabel('Sample Mean')
    plt.ylabel('Density')
    plt.title('Distribution of Sample Means')
    plt.show()

def main():
    sample_size = int(input("Enter the sample size: "))
    num_samples = int(input("Enter the number of samples: "))
    distribution = input("Enter the distribution (uniform/normal): ")

    if distribution == 'uniform':
        a = float(input("Enter the lower bound of the uniform distribution: "))
        b = float(input("Enter the upper bound of the uniform distribution: "))
        dist_params = {'low': a, 'high': b}
    elif distribution == 'normal':
        mu = float(input("Enter the mean of the normal distribution: "))
        sigma = float(input("Enter the standard deviation of the normal distribution: "))
        dist_params = {'loc': mu, 'scale': sigma}
    else:
        print("Invalid distribution")
        return

    samples = central_limit_theorem(sample_size, num_samples, distribution, dist_params)
    plot_distribution(samples)

if __name__ == "__main__":
    main()
