#include <bits/stdc++.h>
#include <chrono>
#include "Matrices.h" 
using namespace std;

vector<vector<int>> leerMatriz(const string& archivo) {
    ifstream file("matrices/" + archivo, ios::binary);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << archivo << endl;
        return {};
    }
    int filas, colum;
    file.read(reinterpret_cast<char*>(&filas), sizeof(filas));
    file.read(reinterpret_cast<char*>(&colum), sizeof(colum));
    vector<vector<int>> matriz(filas, vector<int>(colum));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < colum; ++j) {
            file.read(reinterpret_cast<char*>(&matriz[i][j]), sizeof(matriz[i][j]));
        }
    }
    file.close();
    return matriz;
}

void testMultMatriz(const vector<vector<int>>& A, const vector<vector<int>>& B, void (*multiplyFunction)(const vector<vector<int>>, const vector<vector<int>>), const string& alg, ofstream& resultsFile, const string& size) {
    auto start = chrono::high_resolution_clock::now();
    multiplyFunction(A, B);  
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << alg << " Tiempo transcurrido: " << elapsed.count() << " segundos." << endl;
    resultsFile << alg << "," << size << "," << elapsed.count() << endl;
}


int main() {
    vector<string> matrix_sizes = {"2", "5", "10", "20", "50", "100", "200", "300", "400", "500", "600", "700", "800", "900", "1000", "1100", "1200", "1300", "1400", "1500"};
    ofstream resultsFile("resultados.csv");
    resultsFile << "Algoritmo,Tamaño,Tiempo\n";

    for (const auto& size : matrix_sizes) {
        string archivoA = "matrixA_" + size + "x" + size + ".bin";
        string archivoB = "matrixB_" + size + "x" + size + ".bin";
        vector<vector<int>> A = leerMatriz(archivoA);
        vector<vector<int>> B = leerMatriz(archivoB);

        if (A.empty() || B.empty()) {
            continue;
        }

        cout << "Procesando matrix de tamaño: " << size << "x" << size << endl;
        testMultMatriz(A, B, multiplicar, "Iterativo Cubico", resultsFile, size);
        testMultMatriz(A, B, multiplicar_t, "Iterativo Cubico Optimizado", resultsFile, size);
    }

    return 0;
}
