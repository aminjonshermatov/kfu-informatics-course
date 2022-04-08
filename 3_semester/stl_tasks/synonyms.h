//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_SYNONYMS_H
#define INFORMATICS_SYNONYMS_H

#include "bits/stdc++.h"

using namespace std;

enum SynonymsCommands {
    ADD,
    COUNT,
    CHECK
};

istream& operator>>(istream& in, SynonymsCommands& sc) {
    string cmd;
    in >> cmd;

    if (cmd == "ADD") sc = ADD;
    else if (cmd == "COUNT") sc = COUNT;
    else if (cmd == "CHECK") sc = CHECK;

    return in;
}

class Synonyms {
public:
    Synonyms() = default;

    void add(const string& word1, const string& word2) {
        store[word1].insert(word2);
        store[word2].insert(word1);
    }

    size_t synonymCount(const string& word) const {
        if (store.count(word) > 0) return store.at(word).size();
        return 0;
    }

    bool check(const string& word1, const string& word2) const {
        return store.count(word1) > 0 && store.at(word1).count(word2) > 0;
    }

private:
    unordered_map<string, unordered_set<string>> store;
};

#endif //INFORMATICS_SYNONYMS_H
