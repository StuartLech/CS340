#ifndef GRAPH_H
#define GRAPH_H

#include "PriorityQueue.h"
#include <fstream>
#include <iostream>
#include <vector>

class Graph {
public:
    PriorityQueue graphNodes;
    PriorityQueue minHeap;

    Graph(PriorityQueue &queue, int startNodeId);
    void generateMST();
    void findShortestPaths();
    void resetGraph(int startNodeId);
    void outputToFile(std::string fileName);
};

#endif 
