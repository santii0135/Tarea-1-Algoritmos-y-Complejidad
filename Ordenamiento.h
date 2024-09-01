#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>

// Declaraciones de funciones para algoritmos de ordenamiento
void selectionSort(std::vector<int>& data,int left, int right);
void quickSort(std::vector<int>& data, int low, int high);
void mergeSort(std::vector<int>& data, int left, int right);

#endif 
