#ifndef OFFLINECONNECTOR_H
#define OFFLINECONNECTOR_H

#include <QObject>

class myOfflineConnector : public QObject
{
    Q_OBJECT
public:
    explicit myOfflineConnector(QObject *parent = 0);


};

#endif // OFFLINECONNECTOR_H
