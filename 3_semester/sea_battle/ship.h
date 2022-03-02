#ifndef SHIP_H
#define SHIP_H

#include <QVector>
#include <QPair>

class Ship
{
public:
    enum Position { VERTICAL, HORIZONTAL };

    Ship(int x_, int y_, int size_, Position position_);

    int getSize() const;
    QPair<int, int> getStartCoordinate() const;
    QVector<bool> getShipInfo() const;

private:
    QVector<bool> shipInfo;
    int x, y, size;
    Position position;
};

#endif // SHIP_H
