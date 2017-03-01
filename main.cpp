#include "mainwindow.h"
#include <QApplication>
#include "concretecommands.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyClass<int16_t, std::list> v3(3);
    QByteArray temp=v3.parseData();

    return a.exec();
}
