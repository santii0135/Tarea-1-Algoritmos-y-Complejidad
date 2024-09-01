import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos
data = pd.read_csv('sort_results.csv')

# Obtener tipos de archivo únicos
folders = data['Folder'].unique()  # Asumiendo que hay una columna 'Folder' que describe el tipo de archivo

# Crear un gráfico para cada tipo de archivo
for folder in folders:
    plt.figure(figsize=(10, 6))  # Crea una nueva figura para cada tipo
    subset_folder = data[data['Folder'] == folder]  # Filtra los datos por tipo de archivo

    # Graficar cada algoritmo para este tipo de archivo
    for name in subset_folder['Algorithm'].unique():
        subset_algorithm = subset_folder[subset_folder['Algorithm'] == name]
        plt.plot(subset_algorithm['Size'], subset_algorithm['Time'], marker='o', label=name)

    plt.title(f'Sorting Algorithm Performance - {folder}')
    plt.xlabel('Size of Data')
    plt.ylabel('Time (seconds)')
    plt.legend()
    plt.grid(True)
    plt.show()
