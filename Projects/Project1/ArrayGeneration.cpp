#include "ArrayGeneration.h"
#include <cstdlib>
#include <vector>

std::vector<int> randomArray(int n) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n + 1;
    }
    return arr;
}

std::vector<int> sortedArray(int n) {
    std::vector<int> arr(n);
    for (int i = 1; i <= n; ++i) {
        arr[i - 1] = i;
    }
    return arr;
}
