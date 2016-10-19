#include "econtroller.h"

eController::eController(QObject *parent) : QObject(parent)
{
    status="0";
    id="";
    isRunning=true;
    lastRep="";
    man = new QNetworkAccessManager(this);
    connect(man, SIGNAL(finished(QNetworkReply*)),this, SLOT(repFinish(QNetworkReply*)));
}

void eController::initGame()
{
    if(isRunning)
    {
        if(id=="")
        {
            qDebug()<<"id";
            if(lastRep=="")
            {
                Send("http://localhost/ttt/regGame.php");
            }
            else
            {
                id=lastRep;
                lastRep="";
                initGame();
            }

        }
        else
        {
            if(status=="0")
            {   qDebug()<<"id";
                if(lastRep=="")
                {
                    QString str = "http://localhost/ttt/startGame.php?id=";
                    str+=id;
                    Send(str);
                }
                else
                {
                    status=lastRep;
                    lastRep="";
                    initGame();
                }

            }
            else
            {
                if(status=="1")
                {
                    emit reged(true);
                }
                else
                if(status=="2")
                {
                    emit reged(false);
                }
                else
                if(status=="2")
                {
                    emit disconnect();
                }
            }

        }
    }
}

void eController::Send(QString query)
{
    QNetworkRequest PostRequest;
    PostRequest.setUrl((QUrl)query);
    man->get(PostRequest);
    qDebug() << "Send";

}

void eController::repFinish(QNetworkReply* reply)
{
    qDebug() << "reply";
    QString otvet;
    switch (reply->error())
    {
    case 0: otvet = QString::fromUtf8(reply->readAll());
           //isRunning=false;
           lastRep = otvet;
           qDebug()<<otvet;
        break;
    default: emit disconnect();
        break;
    }
    reply->deleteLater();
    QThread::sleep(1);
    initGame();
}

void eController::stopRunning()
{
    isRunning = false;
}
