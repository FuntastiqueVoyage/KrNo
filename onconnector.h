#ifndef ONCONNECTOR_H
#define ONCONNECTOR_H

#include <QObject>
#include <econtroller.h>
#include <search.h>
#include <QThread>

class OnConnector : public QObject
{
    Q_OBJECT
private:
    short x;
    short o;

    QThread *thread;
    eController *controller;
    Search *search;

    bool whoStep;
    short v[9];
    bool isWin();
    void reset();
public:
    explicit OnConnector(QObject *parent = 0);
    void InitGame();
signals:
    void win();
    void lose();
    void youGo(bool);
    void enemyGo(short,bool);
    void score(short,short);

private slots:
    void firstStep(bool);
public slots:
    void step(short);
};

#endif // ONCONNECTOR_H
