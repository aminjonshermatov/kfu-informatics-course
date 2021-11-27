//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_GUITAR_H
#define INFORMATICS_GUITAR_H

#include "Instrument.h"

class Guitar : public Instrument {
public:
    Guitar(float price, string sound) : Instrument("Guitar", price, move(sound)) {};
};

#endif //INFORMATICS_GUITAR_H
