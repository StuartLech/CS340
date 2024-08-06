#ifndef ARRAY_GENERATION_H
#define ARRAY_GENERATION_H

#include <vector>

class ArrayGeneration {
public:
    
    static std::vector<int> generateRandomArray(int size, int maxValue);

    static std::vector<int> generateSortedArray(int size);

    static std::vector<int> generateReverseSortedArray(int size);
};

#endif


