//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_ACCORDION_H
#define INFORMATICS_ACCORDION_H

#include "Instrument.h"

class Accordion : public Instrument {
public:
    Accordion(float price, string sound) : Instrument("Accordion", price, move(sound)) {};
};

#endif //INFORMATICS_ACCORDION_H
