//
// Created by aminjonshermatov on 11/27/2021.
//

#ifndef INFORMATICS_XYLOPHONE_H
#define INFORMATICS_XYLOPHONE_H

#include "Instrument.h"

class Xylophone : public Instrument {
public:
    Xylophone(float price, string sound) : Instrument("Xylophone", price, move(sound)) {};
};

#endif //INFORMATICS_XYLOPHONE_H
