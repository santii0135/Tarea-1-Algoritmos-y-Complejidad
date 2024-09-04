#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


vector<vector<int>> generarMatriz(int filas, int columnas) {
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 30 + 1;;
        }
    }

    return matriz;
}


void guardarMatriz(const string& archivo, const vector<vector<int>>& matriz) {
    ofstream file("matrices/" + archivo, ios::binary);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo para escribir: " << archivo << endl;
        return;
    }

    int filas = matriz.size();
    int columnas = filas ? matriz[0].size() : 0;
    file.write(reinterpret_cast<char*>(&filas), sizeof(filas));
    file.write(reinterpret_cast<char*>(&columnas), sizeof(columnas));

    for (const auto& fila : matriz) {
        for (int val : fila) {
            file.write(reinterpret_cast<char*>(&val), sizeof(val));
        }
    }

    file.close();
}

int main() {
    srand(time(0));
    vector<int> dimensiones = {2, 5, 10, 20, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};

    for (int dim : dimensiones) {
        auto matrizA = generarMatriz(dim, dim);
        auto matrizB = generarMatriz(dim, dim);
        guardarMatriz("matrixA_" + to_string(dim) + "x" + to_string(dim) + ".bin", matrizA);
        guardarMatriz("matrixB_" + to_string(dim) + "x" + to_string(dim) + ".bin", matrizB);
    }

    return 0;
}
