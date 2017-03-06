#include "robotcommunicator.h"
#include "crc32calc.h"
#include <stdint.h>
#include <QDataStream>

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
    //RobotCommunicator::connect(port, SIGNAL(readyRead()), this, SLOT(readData()),Qt::AutoConnection);

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

void RobotCommunicator::portWrite(QByteArray data)
{
    QByteArray out;
//    out.append(0xfa);
//    out.append(0xaf);
//    out.append(data);
    QDataStream temp(&out,QIODevice::WriteOnly);

    uint8_t adrByte=0xfa;
    uint8_t synByte=0xaf;
    temp.writeRawData((char*)&adrByte,1);
    temp.writeRawData((char*)&synByte,1);
    temp.writeRawData(data.data(),data.size());
    uint32_t crc=crc32buf(out.data(),out.size());
    temp<<crc;
    port->write(out);
}
