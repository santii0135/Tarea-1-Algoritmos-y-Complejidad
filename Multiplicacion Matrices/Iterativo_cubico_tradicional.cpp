#include <bits/stdc++.h>
using namespace std;

void multiplicar(vector<vector<int>> A, vector<vector<int>> B)
{
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}

