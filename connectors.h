#ifndef CONNECTORS_H
#define CONNECTORS_H

#include <QObject>

class connectors : public QObject
{
    Q_OBJECT

private:
    short x;
    short o;

    bool whoStep;
    short v[9];
    bool isWin();
    void reset();
public:
    explicit connectors(QObject *parent = 0);
    void initGame();
signals:
    void win();
    void lose();
    void youGo(bool);
    void enemyGo(short,bool);
    void score(short,short);

public slots:
    void step(short);
};

#endif // CONNECTORS_H
