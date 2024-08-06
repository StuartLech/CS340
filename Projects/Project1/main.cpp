#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "InsertionSort.h"
#include "HeapSort.h"
#include "ArrayGeneration.h"

using std::vector;
using std::cout;
using std::endl;
using std::swap;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

int main() {
    srand(time(0));


    vector<int> sizes = { 100000, 200000, 300000, 400000, 500000 };

    for (int size : sizes) {
        cout << "Array size: " << size << endl;

       
        vector<int> randomArr = randomArray(size);
        vector<int> sortedArr = sortedArray(size);

       
        auto start = high_resolution_clock::now();
        insertionSort(randomArr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Insertion Sort (Unsorted): " << duration.count() << " microseconds" << endl;

        
        randomArr = randomArray(size);  
        start = high_resolution_clock::now();
        heapSort(randomArr);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Heap Sort (Unsorted): " << duration.count() << " microseconds" << endl;

       
        start = high_resolution_clock::now();
        insertionSort(sortedArr);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Insertion Sort (Sorted): " << duration.count() << " microseconds" << endl;

       
        sortedArr = sortedArray(size);  
        start = high_resolution_clock::now();
        heapSort(sortedArr);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Heap Sort (Sorted): " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
