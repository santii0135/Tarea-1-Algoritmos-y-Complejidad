#include <bits/stdc++.h>
#include "Ordenamiento.h"
using namespace std;

// Define las funciones de los algoritmos aquí (mergeSort, selectionSort, quickSort)

// Función para leer datos desde un archivo binario
vector<int> readFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return {};
    }
    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    vector<int> data(size);
    file.read(reinterpret_cast<char*>(data.data()), size * sizeof(int));
    file.close();
    return data;
}

// Función para escribir los resultados en un archivo
void testAlgorithm(vector<int>& data, void (*sortFunction)(vector<int>&, int, int), const string& name, ofstream& resultsFile, const string& size, const string& folder) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data, 0, data.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << name << " elapsed time: " << elapsed.count() << " seconds." << endl;
    
    // Escribir en el archivo de resultados
    resultsFile << folder << "," << name << "," << size << "," << elapsed.count() << endl;
}

int main() {
    ofstream resultsFile("sort_results.csv");
    resultsFile << "Folder,Algorithm,Size,Time\n"; // Encabezado del archivo CSV

    vector<string> folders = {"random", "semi_sorted", "reverse_sorted"};
    vector<string> sizes = {"100", "200", "300", "400", "500", "1000", "5000", "10000", "50000", 100000"};

    for (const auto& folder : folders) {
        for (const auto& size : sizes) {
            string filename = folder + "/" + folder + "_" + size + ".bin";
            vector<int> data = readFromFile(filename);
            if (data.empty()) {
                continue;
            }
            cout << "Processing " << filename << endl;
            testAlgorithm(data, quickSort, "Quick Sort", resultsFile, size, folder);
            testAlgorithm(data, mergeSort, "Merge Sort", resultsFile, size, folder);
            testAlgorithm(data, selectionSort, "Selection Sort", resultsFile, size, folder);
        }
    }

    resultsFile.close();
    return 0;
}
