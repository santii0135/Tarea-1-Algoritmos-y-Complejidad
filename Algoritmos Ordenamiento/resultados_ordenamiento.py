import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos
data = pd.read_csv('resultados.csv')

# Obtener tipos de archivo únicos
folders = data['Carpeta'].unique()  # Asumiendo que hay una columna 'Folder' que describe el tipo de archivo

# Crear un gráfico para cada tipo de archivo
for folder in folders:
    plt.figure(figsize=(10, 6))  # Crea una nueva figura para cada tipo
    subset_folder = data[data['Carpeta'] == folder]  # Filtra los datos por tipo de archivo

    # Graficar cada algoritmo para este tipo de archivo
    for name in subset_folder['Algoritmo'].unique():
        subset_algorithm = subset_folder[subset_folder['Algoritmo'] == name]
        plt.plot(subset_algorithm['Tamaño'], subset_algorithm['Tiempo'], marker='o', label=name)

    plt.title(f'Rendimiento Algoritmos - {folder}')
    plt.xlabel('Tamaño del arreglo')
    plt.ylabel('Tiempo (segundos)')
    plt.xlim(left=0) 
    plt.ylim(bottom=0)
    plt.legend()
    plt.grid(True)
    plt.show()
