#include <bits/stdc++.h>

using namespace std;

void sumar(vector<vector<int>>& result, const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void restar(vector<vector<int>>& result, const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
}

vector<vector<int>> strassen(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    if (n <= 64) { // Base case size, adjust based on profiling
        vector<vector<int>> C(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k)),
                        B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    vector<vector<int>> C11(k, vector<int>(k)), C12(k, vector<int>(k)), C21(k, vector<int>(k)), C22(k, vector<int>(k)),
                        temp1(k, vector<int>(k)), temp2(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            int index_i_k = i + k;
            int index_j_k = j + k;
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][index_j_k];
            A21[i][j] = A[index_i_k][j];
            A22[i][j] = A[index_i_k][index_j_k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][index_j_k];
            B21[i][j] = B[index_i_k][j];
            B22[i][j] = B[index_i_k][index_j_k];
        }

    sumar(temp1, A11, A22); // P1 = (A11 + A22)
    sumar(temp2, B11, B22); // (B11 + B22)
    vector<vector<int>> P1 = strassen(temp1, temp2);

    sumar(temp1, A21, A22); // P2 = (A21 + A22)
    vector<vector<int>> P2 = strassen(temp1, B11);

    restar(temp1, B12, B22); // P3 = (B12 - B22)
    vector<vector<int>> P3 = strassen(A11, temp1);

    restar(temp1, B21, B11); // P4 = (B21 - B11)
    vector<vector<int>> P4 = strassen(A22, temp1);

    sumar(temp1, A11, A12); // P5 = (A11 + A12)
    vector<vector<int>> P5 = strassen(temp1, B22);

    restar(temp1, A21, A11); // P6 = (A21 - A11)
    sumar(temp2, B11, B12);  // (B11 + B12)
    vector<vector<int>> P6 = strassen(temp1, temp2);

    restar(temp1, A12, A22); // P7 = (A12 - A22)
    sumar(temp2, B21, B22);  // (B21 + B22)
    vector<vector<int>> P7 = strassen(temp1, temp2);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C11[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P2[i][j] + P4[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}
