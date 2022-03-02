#ifndef SHIPSGRID_H
#define SHIPSGRID_H

#include <QListView>

#include "ship.h"

class ShipsGrid : public QListView {
    Q_OBJECT
public:
    ShipsGrid();

    void addShip(const Ship& ship);

private:
    static constexpr int GAP = 1;
};

#endif // SHIPSGRID_H
