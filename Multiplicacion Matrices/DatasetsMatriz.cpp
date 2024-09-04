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
            matriz[i][j] = rand() % 10 + 1;;
        }
    }
    return matriz;
}


void guardarMatriz(const string& archivo, const vector<vector<int>>& matriz, bool cuadrada) {
    string carpeta;
    if (cuadrada) {
        carpeta = "cuadradas/";
    } else {
        carpeta = "rectangulares/";
    }
    ofstream file("matrices/" + carpeta + archivo, ios::binary);
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
    vector<int> dimensiones = {50, 100, 200, 300, 400, 500, 600, 700, 800};

    for (int dim1 : dimensiones) {
        for (int dim2 : dimensiones) {
            auto matrizA = generarMatriz(dim1, dim2);
            auto matrizB = generarMatriz(dim2, dim1);
            bool cuadrada = dim1 == dim2;
            guardarMatriz("matrixA_" + to_string(dim1) + "x" + to_string(dim2) + ".bin", matrizA, cuadrada);
            guardarMatriz("matrixB_" + to_string(dim2) + "x" + to_string(dim1) + ".bin", matrizB, cuadrada);
        }  
    }

    return 0;
}
