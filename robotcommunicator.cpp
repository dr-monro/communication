#include "robotcommunicator.h"

RobotCommunicator::RobotCommunicator(QObject *parent) : QObject(parent)
{
    port = new QSerialPort();
    /* Use name of ComPort from Combobox */
    port->setBaudRate(QSerialPort::Baud115200);
    port->setFlowControl(QSerialPort::SoftwareControl);
    port->setParity(QSerialPort::NoParity);
    port->setDataBits(QSerialPort::Data8);
    port->setStopBits(QSerialPort::OneStop);
    myStream=new QDataStream(port);
    RobotCommunicator::connect(port, SIGNAL(readyRead()), this, SLOT(readData()),Qt::AutoConnection);
}


void RobotCommunicator::connectToPort(QString portName)
{
    bool temp;
    port->close();
    port->setPortName(portName);
    temp = port->open(QIODevice::ReadWrite);
}



void RobotCommunicator::disconnectPort()
{
    port->close();
}
