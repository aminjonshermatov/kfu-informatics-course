#ifndef GAMECONFIGURATIONS_H
#define GAMECONFIGURATIONS_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

class GameConfigurations : public QGroupBox
{
    Q_OBJECT
public:
    GameConfigurations();

    QVBoxLayout *spinBoxLayout;

    int getFIeldsSize() const;
    int getCarrierCount() const;
    int getBattleshipCount() const;
    int getCruiserCount() const;
    int getSubmarineCount() const;
    int getDestroyerCount() const;

private slots:
    void indexChanged(int);

private:
    QComboBox *dimensionComboBox;
    QSpinBox *carrierSpinBox;
    QSpinBox *battleShipSpinBox;
    QSpinBox *cruiserSpinBox;
    QSpinBox *submarineSpinBox;
    QSpinBox *destroyerSpinBox;
};

#endif // GAMECONFIGURATIONS_H
