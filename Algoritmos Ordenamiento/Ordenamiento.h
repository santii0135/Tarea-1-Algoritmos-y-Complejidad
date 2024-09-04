#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>

void selectionSort(std::vector<int>& data,int left, int right);
void quickSort(std::vector<int>& data, int low, int high);
void mergeSort(std::vector<int>& data, int left, int right);
void sort_estandar(std::vector<int>& data, int n1, int n2);

#endif 
