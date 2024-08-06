#include "HashTable.h"
#include <fstream>
#include <cmath>
#include <cstdlib>

HashTable::HashTable(int size) : tableSize(size) {
    table.resize(size);
}

void HashTable::addWord(const std::string& word) {
    std::string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    int hash = abs(hashCode(lowerWord) % tableSize);
    int steps = 0;
    for (auto& node : table[hash]) {
        steps++;
        if (node.word == lowerWord) {
            node.occurrences++;
            node.steps += steps;
            return;
        }
    }
    table[hash].emplace_back(lowerWord, 1, steps + 1);
}

int HashTable::hashCode(const std::string& word) const {
    int h = 0;
    for (size_t i = 0; i < word.size(); ++i)
        h = h * 31 + static_cast<int>(word[i]);
    return h;
}

void HashTable::writeToCSV(const std::string& filename) {
    std::ofstream outfile(filename);

    outfile << "Word,Occurrences,Steps\n";
    for (const auto& list : table) {
        for (const auto& node : list) {
            outfile << node.word << "," << node.occurrences << "," << node.steps << "\n";
        }
    }
}

int HashTable::totalSteps() const {
    int total = 0;
    for (const auto& list : table) {
        for (const auto& node : list) {
            total += node.steps;
        }
    }
    return total;
}

double HashTable::averageSteps() const {
    int total = 0, count = 0;
    for (const auto& list : table) {
        for (const auto& node : list) {
            total += node.steps;
            count++;
        }
    }
    return static_cast<double>(total) / count;
}
