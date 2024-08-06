#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "WordInfo.h"
#include <list>
#include <vector>
#include <string>
#include <algorithm> // for std::transform

class HashTable {
public:
    HashTable(int size);
    void addWord(const std::string& word);
    int hashCode(const std::string& word) const;
    void writeToCSV(const std::string& filename);
    int totalSteps() const;
    double averageSteps() const;

private:
    std::vector<std::list<WordNode>> table;
    int tableSize;
};

#endif
