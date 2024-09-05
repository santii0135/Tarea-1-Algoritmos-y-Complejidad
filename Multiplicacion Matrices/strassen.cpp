#include <bits/stdc++.h>

using namespace std;

void sumar(vector<vector<int>>& result, const vector<vector<int>>& X, const vector<vector<int>>& Y) {
    int n = X.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = X[i][j] + Y[i][j];
}

void restar(vector<vector<int>>& result, const vector<vector<int>>& X, const vector<vector<int>>& Y) {
    int n = X.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = X[i][j] - Y[i][j];
}

vector<vector<int>> strassen(vector<vector<int>> &X, vector<vector<int>> &Y) {
    int n = X.size();
    if (n <= 64) { // Base case size, adjust based on profiling
        vector<vector<int>> Z(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    Z[i][j] += X[i][k] * Y[k][j];
        return Z;
    }

    int k = n / 2;
    vector<vector<int>> A(k, vector<int>(k)), B(k, vector<int>(k)), C(k, vector<int>(k)), D(k, vector<int>(k)),
                        E(k, vector<int>(k)), F(k, vector<int>(k)), G(k, vector<int>(k)), H(k, vector<int>(k));

    vector<vector<int>> Z11(k, vector<int>(k)), Z12(k, vector<int>(k)), Z21(k, vector<int>(k)), Z22(k, vector<int>(k)),
                        temp1(k, vector<int>(k)), temp2(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            int index_i_k = i + k;
            int index_j_k = j + k;
            A[i][j] = X[i][j];
            B[i][j] = X[i][index_j_k];
            C[i][j] = X[index_i_k][j];
            D[i][j] = X[index_i_k][index_j_k];

            E[i][j] = Y[i][j];
            F[i][j] = Y[i][index_j_k];
            G[i][j] = Y[index_i_k][j];
            H[i][j] = Y[index_i_k][index_j_k];
        }

    restar(temp1, F, H); // F-H
    vector<vector<int>> P1 = strassen(A, temp1); // P1 = A(F-H)

    sumar(temp1, A, B); // A+B
    vector<vector<int>> P2 = strassen(temp1, H); // P2 = (A+B)H

    sumar(temp1, C, D); // C+D
    vector<vector<int>> P3 = strassen(temp1, E); // P3 = (C+D)E

    restar(temp1, G, E); // G-E
    vector<vector<int>> P4 = strassen(D, temp1); // P4 = D(G-E)

    sumar(temp1, A, D); // A+D
    sumar(temp2, E, H); // E+H
    vector<vector<int>> P5 = strassen(temp1, temp2); // P5 = (A+D)(E+H)

    restar(temp1, B, D); // B-D
    sumar(temp2, G, H);  // G+H
    vector<vector<int>> P6 = strassen(temp1, temp2); // P6 = (B-D)(G+H)

    restar(temp1, A, C); // A-C
    sumar(temp2, E, F);  // E+F
    vector<vector<int>> P7 = strassen(temp1, temp2); // P7 = (A-C)(E+F)

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            Z11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            Z12[i][j] = P1[i][j] + P2[i][j];
            Z21[i][j] = P3[i][j] + P4[i][j];
            Z22[i][j] = P1[i][j] + P5[i][j] - P3[i][j] - P7[i][j];
        }
    }

    vector<vector<int>> Z(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            Z[i][j] = Z11[i][j];
            Z[i][j + k] = Z12[i][j];
            Z[i + k][j] = Z21[i][j];
            Z[i + k][j + k] = Z22[i][j];
        }
    }

    return Z;
}
