//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_POPLES_QUEUE_H
#define INFORMATICS_POPLES_QUEUE_H

#include "bits/stdc++.h"

using namespace std;

enum PeoplesQueueCommands {
    WORRY,
    QUIET,
    COME,
    WORRY_COUNT
};

istream& operator>>(istream& in, PeoplesQueueCommands& pqc) {
    string cmd;
    in >> cmd;

    if (cmd == "WORRY") pqc = WORRY;
    else if (cmd == "QUIET") pqc = QUIET;
    else if (cmd == "COME") pqc = COME;
    else if (cmd == "WORRY_COUNT") pqc = WORRY_COUNT;

    return in;
}

class PeoplesQueue {
public:
    PeoplesQueue() = default;

    void come(int k) {
        while (k--) peoplesWorry.push_back(false);
    }

    void leave(int k) {
        peoplesWorry.resize(peoplesWorry.size() - k);
    }

    void quiet(int idx) {
        peoplesWorry[idx] = false;
    }

    void worry(int idx) {
        peoplesWorry[idx] = true;
    }

    void printWorryCount() const {
        cout << count(peoplesWorry.begin(), peoplesWorry.end(), true) << '\n';
    }

private:
    vector<bool> peoplesWorry{};
};

#endif //INFORMATICS_POPLES_QUEUE_H
