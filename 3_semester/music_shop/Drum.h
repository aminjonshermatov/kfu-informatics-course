//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_DRUM_H
#define INFORMATICS_DRUM_H

#include "Instrument.h"

class Drum : public Instrument {
public:
    Drum(float price, string sound) : Instrument("Drum", price, move(sound)) {};
};

#endif //INFORMATICS_DRUM_H
