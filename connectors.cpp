#include "connectors.h"

connectors::connectors(QObject *parent) : QObject(parent)
{
    for(short i=0;i<9;i++)
    {
        v[i]=0;
    }
    x=0;
    o=0;
}
