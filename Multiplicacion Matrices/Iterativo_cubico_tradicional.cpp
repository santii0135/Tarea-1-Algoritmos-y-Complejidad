#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplicar(vector<vector<int>> &A, vector<vector<int>> &B)
{
	int m = A.size();    // Número de filas en la matriz A 
	int n = A[0].size(); // Número de columnas en la matriz A y columnas de la matriz B

	vector<vector<int>> C(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return C;
}

