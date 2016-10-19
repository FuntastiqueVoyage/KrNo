#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "mainwindow.h"
#include "offconnector.h"
#include "onconnector.h"
#include "newgame.h"

class Game : public QObject
{
    Q_OBJECT
private:
    bool online;
    MainWindow *mainWindow;
    OffConnector *offlineConnector;
    OnConnector *onlineConnector;
    NewGame *newGame;
public:
    explicit Game(QObject *parent = 0);

signals:

public slots:
    void InitMenu();
private slots:
    void startGame(bool);
};

#endif // GAME_H
