// C++ program for implementation of
// selection sort
#include "Ordenamiento.h"
#include <bits/stdc++.h>
using namespace std;

// Function for Selection sort
void selectionSort(vector<int>& arr, int left, int right) {
    for (int i = left; i < right; ++i) {
        int min_idx = i;
        for (int j = i + 1; j <= right; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

// This is code is contributed by rathbhupendra
