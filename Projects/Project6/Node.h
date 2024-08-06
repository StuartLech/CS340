#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>

class Node {
public:
    int id;
    std::vector<int> adjacentIds;
    std::vector<double> weights;
    int parentId;
    double minDistance;
    std::vector<int> edgeIds;
    std::vector<double> edgeWeights;
    double x;   
    double y;

    Node();
    explicit Node(std::string info);
    Node& operator=(const Node& other);
    bool operator<(const Node& other);
};

#endif 
