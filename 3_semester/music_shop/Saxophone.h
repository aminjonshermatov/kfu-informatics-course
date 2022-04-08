//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_SAXOPHONE_H
#define INFORMATICS_SAXOPHONE_H

#include "Instrument.h"

class Saxophone : public Instrument {
public:
    Saxophone(float price, string sound) : Instrument("Saxophone", price, move(sound)) {};
};

#endif //INFORMATICS_SAXOPHONE_H
