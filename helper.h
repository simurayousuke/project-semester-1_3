#ifndef HELPER_H
#define HELPER_H

#include "stdafx.h"
#include "classes.h"
#include "common/message/base/message.h"

class Helper:public QObject
{
    Q_OBJECT

private:
    explicit Helper();
    static Helper *helper;
    QString status;

private slots:
    void readClient();

public:
    static Helper *getInstance();
    QString getfromJson(QString textJson, QString name);
    void writeClient(Message &message);
    QTcpSocket *client;
    void connectServer();
    void disconnectServer();
    void quit();

};

#endif // HELPER_H
