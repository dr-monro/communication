#ifndef ROBOTCOMMUNICATOR_H
#define ROBOTCOMMUNICATOR_H

#include <QObject>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QDataStream>
class RobotCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit RobotCommunicator(QObject *parent = 0);
    void connectToPort(QString portName);
    void disconnectPort();
signals:

public slots:
private:
    QSerialPort *port;
    QDataStream *myStream;
};

#endif // ROBOTCOMMUNICATOR_H
