#include <bits/stdc++.h>
#include <chrono>
#include "Matrices.h" 
using namespace std;

vector<vector<int>> leerMatriz(const string& archivo, bool cuadrada) {
    string carpeta;
    if (cuadrada) {
        carpeta = "cuadradas/";
    } else {
        carpeta = "rectangulares/";
    }
    ifstream file("matrices/" + carpeta + archivo, ios::binary);
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

void testMultMatriz(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>> (*multiplyFunction)(vector<vector<int>>&, vector<vector<int>>&), const string& alg, ofstream& resultsFile, const string& size) {
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> C = multiplyFunction(A, B);  
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo = end - start;
    cout << alg << " Tiempo transcurrido: " << tiempo.count() << " segundos." << endl;
    resultsFile << alg << "," << size << "," << tiempo.count() << endl;
}


int main() {
    vector<string> matrix_sizes = {"50", "100", "200", "300", "400", "500", "600", "700", "800"};
    ofstream resultscuadrada("resultados_cuadrada.csv");
    resultscuadrada << "Algoritmo,Tamaño,Tiempo\n";
    ofstream resultsrect("resultados_rect.csv");
    resultsrect << "Algoritmo,Cantidad Elementos,Tiempo\n";

    for (const auto& dim1 : matrix_sizes) {
        for (const auto& dim2 : matrix_sizes) {
            string archivoA = "matrixA_" + dim1 + "x" + dim2 + ".bin";
            string archivoB = "matrixB_" + dim2 + "x" + dim1 + ".bin";
            bool cuadrada = dim1 == dim2;   
            vector<vector<int>> A = leerMatriz(archivoA, cuadrada);
            vector<vector<int>> B = leerMatriz(archivoB, cuadrada);

            if (A.empty() || B.empty()) {
                continue;
            }
            int sizeint = stoi(dim1) * stoi(dim2);
            string size = to_string(sizeint);
            cout << "Procesando matrix de tamaño: " << dim1 << "x" << dim2 << endl;
            if (cuadrada) {
                testMultMatriz(A, B, multiplicar_t, "Iterativo Cubico Optimizado", resultscuadrada, dim1);
                testMultMatriz(A, B, multiplicar, "Iterativo Cubico", resultscuadrada, dim1);
                testMultMatriz(A, B, strassen, "Strassen", resultscuadrada, dim1);
            } else {
                testMultMatriz(A, B, multiplicar, "Iterativo Cubico", resultsrect, size);
            }
        }
    }

    return 0;
}
