#include "PriorityQueue.h"
#include <iostream> // For debugging, feel free to remove

PriorityQueue::PriorityQueue() : Heap() {
    // Constructor, Initialize heapSize to 0 in the Heap constructor
}

void PriorityQueue::insert(Node newNode) {
    heap.push_back(newNode);  // Add the new node at the end of the heap
    location.push_back(heapSize);  // Add the location of the new node
    heapSize++;  // Increase the size of the heap

    // "Bubble-up" the inserted node to its correct position
    int i = heapSize - 1;
    while (i > 0 && heap[(i - 1) / 2].compare(heap[i]) == false) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        updateLocation(i, (i - 1) / 2);  // Update location table
        i = (i - 1) / 2;
    }
}

Node PriorityQueue::peek() {
    if (heapSize <= 0) {
        throw std::runtime_error("The heap is empty");
    }
    return heap[0];  // The top of the heap contains the maximum or minimum element
}

Node PriorityQueue::extract() {
    if (heapSize <= 0) {
        throw std::runtime_error("The heap is empty");
    }

    Node root = heap[0];  // Store the root node to return later

    // Move the last node to the root and "bubble-down"
    heap[0] = heap[heapSize - 1];
    updateLocation(0, heapSize - 1);  // Update location table
    heapSize--;  // Reduce the size of the heap
    heapify(0);  // Restore heap property
    
    return root;
}

void PriorityQueue::changeKey(int ID, int newKey) {
    int i = location[ID];  // Find the location of the node with the given ID
    heap[i].key = newKey;  // Update its key value

    // "Bubble-up" or "Bubble-down" to restore heap property
    while (i > 0 && heap[(i - 1) / 2].compare(heap[i]) == false) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        updateLocation(i, (i - 1) / 2);  // Update location table
        i = (i - 1) / 2;
    }
    heapify(i);
}
