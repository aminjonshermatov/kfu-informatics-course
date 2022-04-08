#include "ship.h"

Ship::Ship(int x_, int y_, int size_, Position position_)
: x{x_}
, y{y_}
, size{size_}
, position{position_} {}

int Ship::getSize() const {
    return size;
}

QPair<int, int> Ship::getStartCoordinate() const {
    return {x, y};
}

QVector<bool> Ship::getShipInfo() const {
    return shipInfo;
}
