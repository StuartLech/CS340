#include "PriorityQueue.h"
#include <iostream>

int main() {
    PriorityQueue pq;

    pq.insert(Node(0, 3));
    pq.insert(Node(1, 14));
    pq.insert(Node(2, 7));
    pq.insert(Node(3, 9));
    pq.insert(Node(4, 99));
    pq.insert(Node(5, 2));
    pq.insert(Node(6, 46));

    for (int i = 0; i < 7; i++) {
        std::cout << pq.extract().key << " ";
    }

    return 0;
}
