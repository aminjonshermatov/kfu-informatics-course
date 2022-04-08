//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_TRUMPET_H
#define INFORMATICS_TRUMPET_H

#include "Instrument.h"

class Trumpet : public Instrument {
public:
    Trumpet(float price, string sound) : Instrument("Trumpet", price, move(sound)) {};
};

#endif //INFORMATICS_TRUMPET_H
