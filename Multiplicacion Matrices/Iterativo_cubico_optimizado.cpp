#include <bits/stdc++.h>
using namespace std;

// Función para trasponer una matriz de cualquier tamaño
vector<vector<int>> trasponer(vector<vector<int>> matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<int>> T(columnas, vector<int>(filas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            T[j][i] = matriz[i][j];
        }
    }
    return T;
}

// Función para multiplicar matrices de dimensiones m x n y n x m
vector<vector<int>> multiplicar_t(vector<vector<int>> &A, vector<vector<int>> &B) {
    int m = A.size();        // Número de filas de A
    int n = A[0].size();     // Número de columnas de A y filas de B
    
    vector<vector<int>> Bt = trasponer(B);  
    vector<vector<int>> C(m, vector<int>(m, 0));  

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * Bt[j][k];
            }
        }
    }
    return C;
}
