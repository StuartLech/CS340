#include "Heap.h"

Heap::Heap() : heapSize(0) {}

void Heap::heapify(int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heapSize && heap[l].compare(heap[i]))
        largest = l;

    if (r < heapSize && heap[r].compare(heap[largest]))
        largest = r;

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        updateLocation(i, largest); // New line
        heapify(largest);
    }
}

// New Method
void Heap::updateLocation(int i, int j) {
    location[heap[i].ID] = i;
    location[heap[j].ID] = j;
}
