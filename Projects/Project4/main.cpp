#include "Graph.h"
#include "PriorityQueue.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFileName = "example.txt";
    std::ifstream inputFile(inputFileName);
    PriorityQueue queue;
    std::string line;

    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return -1;
    }

    while (getline(inputFile, line)) {
        queue.nodes.push_back(Node(line));
    }

    Graph graph(queue, 0);
    graph.generateMST();
    graph.outputToFile("primout.txt");
    graph.resetGraph(0);
    graph.findShortestPaths();
    graph.outputToFile("dijksraout.txt");

    return 0;
}
