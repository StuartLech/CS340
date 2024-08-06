#include "Node.h"

Node::Node(int ID, int key) : ID(ID), key(key) {}

bool Node::compare(const Node& other, bool isMaxHeap) const {
    return isMaxHeap ? (this->key > other.key) : (this->key < other.key);
}
