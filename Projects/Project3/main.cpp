#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::vector<int> sizes = {500, 1000, 2000, 5000, 10000};
    std::ifstream infile("LittleWomen.txt");
    std::string word;

    for (int size : sizes) {
        HashTable hashTable(size);

        // Reset file to the beginning
        infile.clear();
        infile.seekg(0, std::ios::beg);

        while (infile >> word) {
            hashTable.addWord(word);
        }

        std::string filename = "HashTable_" + std::to_string(size) + ".csv";
        hashTable.writeToCSV(filename);

        std::cout << "Table size: " << size << std::endl;
        std::cout << "Total steps: " << hashTable.totalSteps() << std::endl;
        std::cout << "Average steps: " << hashTable.averageSteps() << std::endl;
    }

    return 0;
}
