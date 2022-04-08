#include "gameconfigurations.h"

GameConfigurations::GameConfigurations()
    : QGroupBox("Game configurations:")
{
    spinBoxLayout = new QVBoxLayout(this);
    setMinimumWidth(200);

    //  dimensions
    QLabel *dimensionLabel = new QLabel("Dimension of grid:");
    dimensionLabel->setFixedWidth(130);
    dimensionComboBox = new QComboBox();
    dimensionComboBox->addItems({"8x8", "10x10", "12x12"});
    connect(dimensionComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(areaChanged(int)));

    QHBoxLayout* dimension = new QHBoxLayout();
    dimension->addWidget(dimensionLabel);
    dimension->addWidget(dimensionComboBox);
    spinBoxLayout->addLayout(dimension);
/*
    // battleship 4
    QLabel *battleShipLabel = new QLabel("Count of battleship(4):");
    battleShipLabel->setFixedWidth(130);
    battleShipSpinBox = new QSpinBox;
    battleShipSpinBox ->setRange(0, 4);
    battleShipSpinBox ->setSingleStep(1);
    battleShipSpinBox ->setValue(1);

    QHBoxLayout* battleShip = new QHBoxLayout();
    battleShip->addWidget(battleShipLabel);
    battleShip->addWidget(battleShipSpinBox);
    spinBoxLayout->addLayout(battleShip);*/
}

int GameConfigurations::getFIeldsSize() const
{
    // 0 -> 8x8
    // 1 -> 10x10
    // 2 -> 12x12
    switch (dimensionComboBox->currentIndex()) {
    case 0:
    default:
        return 8;
    case 1:
        return 10;
    case 2:
        return 12;
    }
}

void GameConfigurations::areaChanged(int idx)
{
    qDebug() << idx << '\n';

    for (auto it = areaToShipsConfig[getFIeldsSize()].begin(); it != areaToShipsConfig[getFIeldsSize()].end(); ++it) {
        qDebug() << it.key() << ' ' << it.value() << '\n';
        int count = it.value();
        while (count--) {
            auto ship = new Ship()
        }
    }
    /*
    for (auto foo : areaToShipsConfig[getFIeldsSize()]) {
        qDebug() << foo << ' ';
    }
    */
}
