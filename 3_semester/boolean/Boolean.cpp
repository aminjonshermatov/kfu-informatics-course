//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Boolean.h"

Boolean::Boolean() {
    for (int i = 0; i < 4; ++i)
        this->setData(i, 0);
}

Boolean::Boolean(bool arr[4]) {
    for (int i = 0; i < 4; ++i)
        this->setData(i, arr[i]);
}

Boolean::Boolean(const Boolean &b) {
    for (int i = 0; i < 4; ++i)
        this->setData(i, b.getData(i));
}

void Boolean::setData(int idx, bool val) {
    if (idx > 3)
        throw std::exception("Out of range");

    if (val != 0 && val != 1)
        throw std::exception("Value can be either '0' or '1'");

    this->data[idx] = val;
};

bool Boolean::getData(int idx) const {
    if (idx > 3)
        throw std::exception("Out of range");

    return this->data[idx];
};

Boolean* Boolean::conjunction(const Boolean* mb) {
    auto* res = new Boolean();

    for (int i = 0; i < 4; ++i)
        if (this->getData(i) + mb->getData(i) == 2)
            res->setData(i, 1);
        else
            res->setData(i, 0);

    return res;
};

Boolean* Boolean::disjunction(const Boolean* mb) {
    auto* res = new Boolean();

    for (int i = 0; i < 4; ++i)
        if (this->getData(i) + mb->getData(i) == 0)
            res->setData(i, 0);
        else
            res->setData(i, 1);

    return res;
};

std::ostream& operator<<(std::ostream& os, const Boolean& b) {
    os << "\n";
    for (int i = 0; i < 4; ++i)
        os << i + 1 << ":\t" << b.getData(i) << "\n";

    return os;
};
