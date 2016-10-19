#include "game.h"


Game::Game(QObject *parent) : QObject(parent)
{
    mainWindow = new MainWindow();

    offlineConnector = new OffConnector();

    onlineConnector = new OnConnector();

    newGame = new NewGame();

    connect(newGame, SIGNAL(pressed(bool)), this, SLOT(startGame(bool)));

    InitMenu();

}

void Game::startGame(bool b)
{
    if(b)
    {
        qDebug()<<"offline";
        connect(mainWindow , SIGNAL(goTiMenu()), this, SLOT(InitMenu()));
        connect(offlineConnector, SIGNAL(win(bool)), mainWindow , SLOT(youWin(bool)));
        connect(offlineConnector, SIGNAL(lose()), mainWindow , SLOT(youLose()));
        connect(offlineConnector, SIGNAL(youGo(bool)), mainWindow , SLOT(youGo(bool)));
        connect(mainWindow , SIGNAL(step(short)), offlineConnector, SLOT(step(short)));
        connect(offlineConnector, SIGNAL(score(short,short)), mainWindow , SLOT(setScore(short,short)));
        mainWindow->newGame();
        offlineConnector->InitGame();
    }else
    {
        qDebug()<<"online";
        connect(mainWindow , SIGNAL(goTiMenu()), this, SLOT(InitMenu()));
        connect(onlineConnector, SIGNAL(win()), mainWindow , SLOT(youWin()));
        connect(onlineConnector, SIGNAL(lose()), mainWindow , SLOT(youLose()));
        connect(onlineConnector, SIGNAL(youGo(bool)), mainWindow , SLOT(youGo(bool)));
        connect(mainWindow , SIGNAL(step(short)), onlineConnector, SLOT(step(short)));
        connect(onlineConnector, SIGNAL(score(short,short)), mainWindow , SLOT(setScore(short,short)));
        mainWindow->newGame();
        onlineConnector->InitGame();
    }
}

void Game::InitMenu()
{
    mainWindow = new MainWindow();
    offlineConnector = new OffConnector();
    onlineConnector = new OnConnector();
    newGame->show();
}
