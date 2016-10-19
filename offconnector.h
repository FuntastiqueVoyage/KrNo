#ifndef OFFCONNECTOR_H
#define OFFCONNECTOR_H

#include <QObject>

class OffConnector : public QObject
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
    explicit OffConnector(QObject *parent = 0);
    void InitGame();
signals:
    void win(bool);
    void lose();
    void youGo(bool);
    void enemyGo(short,bool);
    void score(short,short);

public slots:
    void step(short);
};

#endif // OFFCONNECTOR_H
