#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Node.h"
#include <vector>
#include <stdexcept>

class PriorityQueue {
public:
    std::vector<Node> nodes;
    std::vector<int> indices;

    PriorityQueue();
    void siftDown(int index);
    void constructHeap();
    Node removeTop();
    Node* getNodeById(int nodeId);
    void updateDistance(int nodeId, double newDistance);
};

#endif 
