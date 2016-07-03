#include "stdafx.h"
#include "ajfriendmessage.h"

ajFriendMessage::ajFriendMessage(QString fromUserName, QString toUserName, QString accept)
{
    fromuser = fromUserName;
    touser = toUserName;
    acpt = accept;
    head = "ajFriend";
}

ajFriendMessage::ajFriendMessage()
{
    head = "ajFriend";
}

QString ajFriendMessage::getJsonString()
{
    QJsonObject jsonObject;
    jsonObject.insert("head", head);
    jsonObject.insert("fromusername", fromuser);
    jsonObject.insert("tousername", touser);
    jsonObject.insert("accept", acpt);
    QJsonDocument jsonDocument;
    jsonDocument.setObject(jsonObject);
    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Compact);
    return QString(byteArray);
}

bool ajFriendMessage::loadfromJson(QString textJson)
{
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(textJson.toStdString().c_str(), &jsonParseError);
    if(jsonParseError.error == QJsonParseError::NoError)
    {
        if(jsonDocument.isObject())
        {
            QJsonObject jsonObject = jsonDocument.object();
            if(jsonObject.contains("fromusername"))
            {
                QJsonValue jsonValue = jsonObject.take("fromusername");
                if(jsonValue.isString())
                {
                    fromuser = jsonValue.toString();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            if(jsonObject.contains("tousername"))
            {
                QJsonValue jsonValue = jsonObject.take("tousername");
                if(jsonValue.isString())
                {
                    touser = jsonValue.toString();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            if(jsonObject.contains("accept"))
            {
                QJsonValue jsonValue = jsonObject.take("accept");
                if(jsonValue.isString())
                {
                    acpt = jsonValue.toString();
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

