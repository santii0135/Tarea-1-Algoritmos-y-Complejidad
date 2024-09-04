import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos desde el CSV
data = pd.read_csv('resultados.csv')

# Definir el tamaño de la figura
plt.figure(figsize=(12, 8))

# Iterar sobre cada algoritmo y graficar su rendimiento
for name in data['Algoritmo'].unique():
    subset_algorithm = data[data['Algoritmo'] == name]
    plt.plot(subset_algorithm['Tamaño'], subset_algorithm['Tiempo'], marker='o', label=name)

# Configurar el título y las etiquetas de los ejes
plt.title('Rendimiento de Algoritmos de Multiplicación de Matrices')
plt.xlabel('Tamaño de la matriz (n x n)')
plt.xlim(left=0) 
plt.ylim(bottom=0)
plt.ylabel('Tiempo (segundos)')
plt.legend()
plt.grid(True)

# Mostrar el gráfico
plt.show()
