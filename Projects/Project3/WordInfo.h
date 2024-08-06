#ifndef WORDINFO_H
#define WORDINFO_H

#include <string>

struct WordNode {
    std::string word;
    int occurrences;
    int steps;

    WordNode(const std::string& word, int occurrences, int steps) :
        word(word), occurrences(occurrences), steps(steps) {}
};

#endif
