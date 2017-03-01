#ifndef CONCRETECOMMANDS_H
#define CONCRETECOMMANDS_H
#include <QString>
#include <stdint.h>
#include <QByteArray>
//#include <QList>
#include <vector>
#include <allocators>
#include <list>
#include <QDataStream>


template <
    typename T,
    template <typename ELEM, typename ALLOC = std::allocator<ELEM> >
    class Cont = std::vector>
class MyClass {
public:
    MyClass(uint16_t size):obj(size,0){}
    QByteArray parseData(void)
    {
        QByteArray temp;
        QDataStream tDStream(&temp,QIODevice::ReadWrite);
        for (std::list<T>::iterator it=obj.begin(); it != obj.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        return temp;
    }

private:
    Cont<T> obj;
};

//MyClass<int> v1;
//MyClass<int, deque> v2;



#endif // CONCRETECOMMANDS_H
