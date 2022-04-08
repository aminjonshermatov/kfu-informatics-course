#ifndef GAMECONFIGURATIONS_H
#define GAMECONFIGURATIONS_H

#include <QHash>
#include <QMap>
#include <QString>

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <unordered_map>

class GameConfigurations : public QGroupBox
{
    Q_OBJECT
public:
    GameConfigurations();

    QVBoxLayout *spinBoxLayout;

    int getFIeldsSize() const;

    // {shipSize -> shipName}
    QHash<int, QString> shipsName = {
        {5, QString("Carrier")},
        {4, QString("Battle Ship")},
        {3, QString("Cruiser")},
        {2, QString("Submarine")},
        {1, QString("Destroyer")}
    };

private slots:
    void areaChanged(int);

private:
    QComboBox *dimensionComboBox;


    // {areaSize -> {shipSize -> shipCount}}
    QHash<int, QMap<int, int>> areaToShipsConfig = {
        {
            8,
            {
                {3, 1},
                {2, 2},
                {1, 3}
            }
        },
        {
            10,
            {
                {4, 1},
                {3, 2},
                {2, 3},
                {1, 4}
            }
        },
        {
            12,
            {
                {5, 1},
                {4, 2},
                {1, 5}
            }
        }
    };
};
#endif // GAMECONFIGURATIONS_H
