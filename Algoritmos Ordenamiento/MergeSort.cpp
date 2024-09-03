#include "Ordenamiento.h"
#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int l = mid - left + 1;
    int r = right - mid;

    vector<int> L(l), R(r);

    for (int i = 0; i < l; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < r; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < l && j < r) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < l) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < r) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right)  / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}