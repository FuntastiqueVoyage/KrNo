#ifndef ECONTROLLER_H
#define ECONTROLLER_H

#include <QDebug>
#include <QThread>
#include <QObject>
#include <QString>
#include <QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

class eController : public QObject
{
    Q_OBJECT
public:
    explicit eController(QObject *parent = 0);



signals:
    void disconnect();
    void reged(bool);

private:
    QString id;
    QString status;
    QString lastRep;
    QNetworkAccessManager *man;
    bool isRunning;
    void Send(QString query);

private slots:
    void repFinish(QNetworkReply*);

public slots:
    void stopRunning();
    void initGame();
};

#endif // ECONTROLLER_H
