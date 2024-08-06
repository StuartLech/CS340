#include "Graph.h"

Graph::Graph(PriorityQueue &queue, int startNodeId) : graphNodes(queue), minHeap(queue) {
    graphNodes.updateDistance(startNodeId, 0);
    minHeap.constructHeap();
}

void Graph::generateMST() {
    while (!minHeap.nodes.empty()) {
        Node u = minHeap.removeTop();
        for (int i = 0; i < u.adjacentIds.size(); i++) {
            Node* v = graphNodes.getNodeById(u.adjacentIds[i]);
            if (v != nullptr && u.weights[i] < v->minDistance) {
                v->parentId = u.id;
                v->minDistance = u.weights[i];
                minHeap.updateDistance(v->id, u.weights[i]);
            }
        }
    }
}

void Graph::findShortestPaths() {
    while (!minHeap.nodes.empty()) {
        Node u = minHeap.removeTop();
        for (int i = 0; i < u.adjacentIds.size(); i++) {
            Node* v = graphNodes.getNodeById(u.adjacentIds[i]);
            if (v != nullptr && v->minDistance > u.minDistance + u.weights[i]) {
                v->parentId = u.id;
                v->minDistance = u.minDistance + u.weights[i];
                minHeap.updateDistance(v->id, u.minDistance + u.weights[i]);
            }
        }
    }
}

void Graph::resetGraph(int startNodeId) {
    for (Node& node : graphNodes.nodes) {
        node.minDistance = INT_MAX;
        node.parentId = -1;
    }
    graphNodes.updateDistance(startNodeId, 0);
    minHeap = graphNodes;
    minHeap.constructHeap();
}

void Graph::outputToFile(std::string fileName) {
    std::ofstream outFS(fileName);
    if (!outFS.is_open()) {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return;
    }
    for (Node &node : graphNodes.nodes) {
        if (node.parentId != -1) {
            outFS << node.id << " " << node.parentId << " " << node.minDistance << std::endl;
        }
    }
    outFS.close();
}
