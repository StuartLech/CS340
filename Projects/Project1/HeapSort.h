#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

void maxHeapify(std::vector<int>& arr, int n, int i);
void buildMaxHeap(std::vector<int>& arr);
void heapSort(std::vector<int>& arr);

#endif
