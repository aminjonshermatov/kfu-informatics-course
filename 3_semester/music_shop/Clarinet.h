//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_CLARINET_H
#define INFORMATICS_CLARINET_H

#include "Instrument.h"

class Clarinet : public Instrument {
public:
    Clarinet(float price, string sound) : Instrument("Clarinet", price, move(sound)) {};
};

#endif //INFORMATICS_CLARINET_H
