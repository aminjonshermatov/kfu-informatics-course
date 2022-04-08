//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_PIANO_H
#define INFORMATICS_PIANO_H

#include <utility>

#include "Instrument.h"

class Piano : public Instrument {
public:
    Piano(float price, string sound) : Instrument("Piano", price, move(sound)) {};
};

#endif //INFORMATICS_PIANO_H
