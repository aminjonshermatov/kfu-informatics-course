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
    connect(dimensionComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));

    QHBoxLayout* dimension = new QHBoxLayout();
    dimension->addWidget(dimensionLabel);
    dimension->addWidget(dimensionComboBox);
    spinBoxLayout->addLayout(dimension);

    // carrier 5
    QLabel *carrierLabel = new QLabel("Count of carrier(5):");
    carrierLabel->setFixedWidth(130);
    carrierSpinBox = new QSpinBox;
    carrierSpinBox ->setRange(0, 4);
    carrierSpinBox ->setSingleStep(1);
    carrierSpinBox ->setValue(1);

    QHBoxLayout* carrier = new QHBoxLayout();
    carrier->addWidget(carrierLabel);
    carrier->addWidget(carrierSpinBox);
    spinBoxLayout->addLayout(carrier);

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
    spinBoxLayout->addLayout(battleShip);

    // cruiser 3
    QLabel *cruiserLabel = new QLabel("Count of cruiser(3):");
    cruiserLabel->setFixedWidth(130);
    cruiserSpinBox = new QSpinBox;
    cruiserSpinBox ->setRange(0, 4);
    cruiserSpinBox ->setSingleStep(1);
    cruiserSpinBox ->setValue(1);

    QHBoxLayout* cruiser = new QHBoxLayout();
    cruiser->addWidget(cruiserLabel);
    cruiser->addWidget(cruiserSpinBox);
    spinBoxLayout->addLayout(cruiser);

    // submarine 2
    QLabel *submarineLabel = new QLabel("Count of submarine(2):");
    submarineLabel->setFixedWidth(130);
    submarineSpinBox = new QSpinBox;
    submarineSpinBox ->setRange(0, 4);
    submarineSpinBox ->setSingleStep(1);
    submarineSpinBox ->setValue(1);

    QHBoxLayout* submarine = new QHBoxLayout();
    submarine->addWidget(submarineLabel);
    submarine->addWidget(submarineSpinBox);
    spinBoxLayout->addLayout(submarine);

    // destroyer 5
    QLabel *destroyerLabel = new QLabel("Count of destroyer(1):");
    destroyerLabel->setFixedWidth(130);
    destroyerSpinBox = new QSpinBox;
    destroyerSpinBox ->setRange(0, 4);
    destroyerSpinBox ->setSingleStep(1);
    destroyerSpinBox ->setValue(1);

    QHBoxLayout* destroyer = new QHBoxLayout();
    destroyer->addWidget(destroyerLabel);
    destroyer->addWidget(destroyerSpinBox);
    spinBoxLayout->addLayout(destroyer);
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

int GameConfigurations::getCarrierCount() const
{
    return carrierSpinBox->value();
}

int GameConfigurations::getBattleshipCount() const
{
    return battleShipSpinBox->value();
}

int GameConfigurations::getCruiserCount() const
{
    return cruiserSpinBox->value();
}

int GameConfigurations::getSubmarineCount() const
{
    return submarineSpinBox->value();
}

int GameConfigurations::getDestroyerCount() const
{
    return destroyerSpinBox->value();
}

void GameConfigurations::indexChanged(int idx)
{
    qDebug() << idx << '\n';
}
