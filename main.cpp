#include "mainwindow.h"
#include <QApplication>
#include "concretecommands.h"
#include "robotcommunicator.h"
RobotCommunicator comm;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::vector<uint8_t> test(3,1);
    Command1<uint8_t> v1(3,test);
    Command2<uint8_t,uint8_t> v2(3,test,test);
    Command3<uint8_t,uint8_t,uint8_t> v3(4,test,test,test);
    std::vector<uint8_t> test2(3,1);
    v3.setParameters(test2,test2,test2);
    //Command3<float,double,float> v4(4,test,test,test);
    comm.portWrite(v1.parseData());

    return a.exec();
}
