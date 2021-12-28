#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsTextItem>
#include <QLabel>
#include <QPushButton>

#include "gameconfigurations.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    GameConfigurations* gameConfigerations;
    QPushButton* startGame;
private:

};
#endif // MAINWINDOW_H
