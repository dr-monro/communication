#include "mainwindow.h"
#include <QApplication>
#include "concretecommands.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::vector<int> test(3,1);
    Command1<int> v1(3,test);
    Command2<int,int> v2(3,test,test);
    Command3<int,int,int> v3(4,test,test,test);
    //Command3<float,double,float> v4(4,test,test,test);
    QByteArray temp=v3.parseData();

    return a.exec();
}
