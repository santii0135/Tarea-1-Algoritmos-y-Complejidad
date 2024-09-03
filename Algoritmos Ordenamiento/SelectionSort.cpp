#include "Ordenamiento.h"
#include <bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>& arr, int izq, int der) {
    for (int i = izq; i < der; ++i) {
        int min = i;
        for (int j = i + 1; j <= der; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

