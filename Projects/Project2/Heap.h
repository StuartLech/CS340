#ifndef HEAP_H
#define HEAP_H

#include "Node.h"
#include <vector>

class Heap {
protected:
    std::vector<Node> heap;
    std::vector<int> location; // New line
    int heapSize;

public:
    Heap();
    void heapify(int i);
    void updateLocation(int i, int j); // New line
};

#endif
