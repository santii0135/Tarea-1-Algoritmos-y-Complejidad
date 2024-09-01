import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos
data = pd.read_csv('sort_results.csv')

# Filtrar por algoritmo
for name in data['Algorithm'].unique():
    subset = data[data['Algorithm'] == name]
    plt.plot(subset['Size'], subset['Time'], label=name)

plt.xlabel('Size of Data')
plt.ylabel('Time (seconds)')
plt.title('Sorting Algorithm Performance')
plt.legend()
plt.xscale('log')  # Escala logarítmica en x si los tamaños varían mucho
plt.yscale('log')  # Escala logarítmica en y si los tiempos varían mucho
plt.grid(True)
plt.show()
