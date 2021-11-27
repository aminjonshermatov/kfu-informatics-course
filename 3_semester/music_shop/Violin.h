//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_VIOLIN_H
#define INFORMATICS_VIOLIN_H

#include "Instrument.h"

class Violin : public Instrument {
public:
    Violin(float price, string sound) : Instrument("Violin", price, move(sound)) {};
};

#endif //INFORMATICS_VIOLIN_H
