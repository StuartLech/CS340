#include "Node.h"

Node::Node() : id(0), parentId(-1), minDistance(INT_MAX) {}

Node::Node(std::string info) {
    std::istringstream iss(info);
    iss >> id;
    int adjId;
    double weight;
    while (iss >> adjId >> weight) {
        adjacentIds.push_back(adjId);
        weights.push_back(weight);
    }
    parentId = -1;
    minDistance = INT_MAX;
}

Node& Node::operator=(const Node& other) {
    if (this != &other) {
        id = other.id;
        adjacentIds = other.adjacentIds;
        weights = other.weights;
        parentId = other.parentId;
        minDistance = other.minDistance;
        edgeIds = other.edgeIds;
        edgeWeights = other.edgeWeights;
    }
    return *this;
}

bool Node::operator<(const Node& other) {
    return minDistance < other.minDistance;
}
