#include "HeapSort.h"
#include <vector>
#include <algorithm> 

void maxHeapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    buildMaxHeap(arr);
    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}
