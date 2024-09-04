#include <bits/stdc++.h>
#include "Ordenamiento.h"
using namespace std;


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


void testAlgorithm(vector<int>& data, void (*sortFunction)(vector<int>&, int, int), const string& alg, ofstream& resultsFile, const string& size, const string& folder) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data, 0, data.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << alg << " Tiempo transcurrido: " << elapsed.count() << " segundos." << endl;
    
    // Escribir en el archivo de resultados
    resultsFile << folder << "," << alg << "," << size << "," << elapsed.count() << endl;
}

int main() {
    ofstream resultsFile("resultados.csv");
    resultsFile << "Carpeta,Algoritmo,Tamaño,Tiempo\n"; 

    vector<string> folders = {"random", "semi_sorted", "reverse_sorted"};
    vector<string> sizes = {"100", "500", "1000", "5000", "10000", "20000", "30000", "40000", "50000", "60000", "70000", "80000", "90000", "100000"};

    for (const auto& folder : folders) {
        for (const auto& size : sizes) {
            string filename = folder + "/" + folder + "_" + size + ".bin";
            vector<int> data = readFromFile(filename);
            if (data.empty()) {
                continue;
            }
            cout << "Procesando " << filename << endl;
            testAlgorithm(data, quickSort, "Quick Sort", resultsFile, size, folder);
            testAlgorithm(data, mergeSort, "Merge Sort", resultsFile, size, folder);
            testAlgorithm(data, selectionSort, "Selection Sort", resultsFile, size, folder);
            testAlgorithm(data, sort_estandar, "Sort Estándar", resultsFile, size, folder);
        }
    }

    resultsFile.close();
    return 0;
}
