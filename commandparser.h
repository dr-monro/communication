#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QObject>
#include <QString>
#include <QList>
#include "concretecommands.h"

class CommandParser : public QObject
{
    Q_OBJECT
public:
    explicit CommandParser(QObject *parent = 0);
    //virtual void sendCommand(uint8_t cmd,QString parameters);
signals:

public slots:
private:
    //QList<AbstractCommands> listCommands;
};

#endif // COMMANDPARSER_H

