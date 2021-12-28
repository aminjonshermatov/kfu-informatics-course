#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , gameConfigerations{new GameConfigurations()}
{
    QGridLayout *grid = new QGridLayout;

    QLabel* titleText = new QLabel(QString("Sea Battle"));
    QFont titleFont("Helvetica [Cronyx]", 50);
    titleFont.setBold(true);
    titleText->setFont(titleFont);

    grid->addWidget(titleText, 0, 0, 1, 3, Qt::AlignHCenter);

    grid->addWidget(gameConfigerations, 1, 0, 4, 1);
    GameConfigurations* GameConfigurations1 = new GameConfigurations();
    GameConfigurations* GameConfigurations2 = new GameConfigurations();
    grid->addWidget(GameConfigurations1, 1, 1, 4, 1);
    grid->addWidget(GameConfigurations2, 1, 2, 4, 1);

    QPushButton* startGame = new QPushButton("Start Game");
    grid->addWidget(startGame, 5, 0, 1, 3, Qt::AlignHCenter);

    setLayout(grid);

    setWindowTitle(tr("Sea Battle"));
}

MainWindow::~MainWindow()
{
}

