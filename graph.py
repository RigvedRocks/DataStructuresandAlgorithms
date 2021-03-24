import matplotlib.pyplot as plt
import numpy as np

size_list = [100,1000,10000,100000,1000000,10000000]
binary_search_array = [2.377,2.376,2,376,3.773,4.682,4.821]
linear_search_array = [2.864,7.613,59.648,598.296,5106.19,38237.5]

def plot_graph():
    plt.figure()
    plt.plot(size_list)
    plt.plot(binary_search_array)
    plt.plot(linear_search_array)
    plt.title("Binary Search vs Linear Search")
    plt.xlabel("Size of array")
    plt.ylabel("Running time in microseconds")
    plt.legend(['Linear Search','Binary Search'],loc = 'upper left')
    plt.show()

plot_graph()

