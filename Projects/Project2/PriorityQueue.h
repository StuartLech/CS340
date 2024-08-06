#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Heap.h"

class PriorityQueue : public Heap {
public:
    PriorityQueue();
    void insert(Node newNode);
    Node peek();
    Node extract();
    void changeKey(int ID, int newKey); // New line
};

#endif
