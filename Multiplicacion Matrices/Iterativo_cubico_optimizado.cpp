#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> trasponer(vector<vector<int>>& matriz) {
    int n = matriz.size();
    vector<vector<int>> T(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            T[j][i] = matriz[i][j];
        }
    }
    return T;
}

void multiplicar_t(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> Bt = trasponer(B);
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * Bt[j][k];
            }
        }
    }
}