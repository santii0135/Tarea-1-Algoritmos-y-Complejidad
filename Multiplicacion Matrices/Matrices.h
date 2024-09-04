#ifndef MATRICES_H
#define MATRICES_H

#include <vector>
using namespace std;

vector<vector<int>> multiplicar(vector<vector<int>> &A, vector<vector<int>> &B);
vector<vector<int>> multiplicar_t(vector<vector<int>> &A, vector<vector<int>> &B);
vector<vector<int>> strassen(vector<vector<int>> &A, vector<vector<int>> &B);

#endif 