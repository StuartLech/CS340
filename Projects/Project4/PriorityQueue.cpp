#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    indices = std::vector<int>(256, -1); 
}

void PriorityQueue::siftDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < nodes.size() && nodes[left] < nodes[smallest])
        smallest = left;
    if (right < nodes.size() && nodes[right] < nodes[smallest])
        smallest = right;
    if (smallest != index) {
        std::swap(nodes[index], nodes[smallest]);
        std::swap(indices[nodes[index].id], indices[nodes[smallest].id]);
        siftDown(smallest);
    }
}

void PriorityQueue::constructHeap() {
    for (int i = nodes.size() / 2 - 1; i >= 0; i--) {
        siftDown(i);
    }
}

Node PriorityQueue::removeTop() {
    if (nodes.empty()) {
        throw std::runtime_error("Priority Queue is empty");
    }
    Node topNode = nodes.front();
    nodes[0] = nodes.back();
    nodes.pop_back();
    if (!nodes.empty()) {
        siftDown(0);
    }
    return topNode;
}

Node* PriorityQueue::getNodeById(int nodeId) {
    if (indices[nodeId] != -1)
        return &nodes[indices[nodeId]];
    return nullptr;
}

void PriorityQueue::updateDistance(int nodeId, double newDistance) {
    if (indices[nodeId] != -1) {
        nodes[indices[nodeId]].minDistance = newDistance;
        constructHeap();
    }
}
