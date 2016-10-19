#include "offconnector.h"
#include <QDebug>
#include <QObject>

OffConnector::OffConnector(QObject *parent) : QObject(parent)
{
    whoStep = true;
    for(short i=0;i<9;i++)
    {
        v[i]=0;
    }
    x=0;
    o=0;
}

void OffConnector::step(short i)
{
    qDebug()<<"step"<<i;
    if(whoStep)
    {
        v[i]=1;
        whoStep=false;
    }
    else
    {
        v[i]=-1;
        whoStep=true;
    }
    if(isWin())
    {//qDebug()<<"win connector";

        if(whoStep)
        {
            emit win(false);
            o++;
        }
        else
        {
            emit win(true);
            x++;
        }
        emit score(x,o);
        reset();
    }
    else
    {
        emit youGo(whoStep);
    }
}

void OffConnector::InitGame()
{
    emit youGo(whoStep);
}

bool OffConnector::isWin()
{
    //qDebug()<<"win check:";
    if(v[0]==v[1]&&v[1]==v[2]&&v[0]!=0)
    {return true;}
    if(v[3]==v[4]&&v[4]==v[5]&&v[3]!=0)
    {return true;}
    if(v[6]==v[7]&&v[7]==v[8]&&v[6]!=0)
    {return true;}
    if(v[0]==v[3]&&v[3]==v[6]&&v[0]!=0)
    {return true;}
    if(v[1]==v[4]&&v[4]==v[7]&&v[1]!=0)
    {return true;}
    if(v[2]==v[5]&&v[5]==v[8]&&v[2]!=0)
    {return true;}
    if(v[0]==v[4]&&v[4]==v[8]&&v[0]!=0)
    {return true;}
    if(v[2]==v[4]&&v[4]==v[6]&&v[2]!=0)
    {return true;}
    //qDebug()<<"false";
    return false;
}

void OffConnector::reset()
{
    for (short i=0;i<9;i++)
    {
        v[i]=0;
    }
    whoStep=true;
}


