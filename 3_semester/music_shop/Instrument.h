//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_INSTRUMENT_H
#define INFORMATICS_INSTRUMENT_H

#include <utility>

#include "bits/stdc++.h"

using namespace std;

class Instrument {
public:
    Instrument(string _name, float _price, string _sound)
        : name(move(_name))
        , price(_price)
        , sound(move(_sound))
        , uuid(_name + to_string((1 << 16) + price)) { };

    virtual string getName() const {
        return name;
    };

    virtual float getPrice() const {
        return price;
    };

    virtual string getSound() const {
        return sound;
    };

    friend ostream& operator<<(ostream& out, const Instrument& ins) {
        return out << '\t' << "Name: " << ins.getName() << '\n'
                   << '\t' << "Price: " << ins.getPrice() << '$' << '\n'
                   << '\t' << "Sound: " << ins.getSound() << '\n';
    }

    virtual ~Instrument() = 0;

protected:
    string name{};
    float price{};
    string sound{};
    string uuid{};
};


#endif //INFORMATICS_INSTRUMENT_H
