#ifndef NODE_H
#define NODE_H

class Node {
public:
    int ID;
    int key;

    Node(int ID = -1, int key = -1);
    bool compare(const Node& other, bool isMaxHeap = true) const;
};

#endif
