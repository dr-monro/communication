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

class AbstractCommand
{

public:
    AbstractCommand(uint8_t id){this->id=id;}
    uint8_t getId(){return id;}
    virtual QByteArray parseData()=0;
private:
    uint8_t id;
};

template <
    typename T,
    template <typename ELEM, typename ALLOC = std::allocator<ELEM> >
    class Cont = std::vector>
class Command1: AbstractCommand {
public:
    Command1(uint8_t id,Cont<T> params):obj(params),AbstractCommand(id){}
    QByteArray parseData()
    {
        QByteArray temp;
        QDataStream tDStream(&temp,QIODevice::ReadWrite);
        tDStream<<(uint8_t)(obj.size()*sizeof(T)+1);
        tDStream<<getId();
        for (Cont<T>::iterator it=obj.begin(); it != obj.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        return temp;
    }
    void setParameters(Cont<T> params)
    {
        obj=params;
    }

private:
    Cont<T> obj;
};

template <
    typename T,
    typename T1,
    template <typename ELEM, typename ALLOC = std::allocator<ELEM> > class Cont = std::vector,
    template <typename ELEM1, typename ALLOC1 = std::allocator<ELEM1> > class Cont1 = std::vector>

class Command2:AbstractCommand
{
public:
    Command2(uint8_t id,Cont<T> params,Cont1<T1> params1):obj(params),obj1(params1),AbstractCommand(id){}
    QByteArray parseData(void)
    {
        QByteArray temp;
        QDataStream tDStream(&temp,QIODevice::ReadWrite);
        for (Cont<T>::iterator it=obj.begin(); it != obj.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        for (Cont1<T>::iterator it=obj1.begin(); it != obj1.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        return temp;
    }
    void setParameters(Cont<T> params,Cont1<T1> params1)
    {
        obj=params;
        obj1=params1;
    }
private:
    Cont<T> obj;
    Cont1<T1> obj1;
};

template <
    typename T,
    typename T1,    
    typename T2,
    template <typename ELEM1, typename ALLOC1 = std::allocator<ELEM1> > class Cont1 = std::vector,
    template <typename ELEM, typename ALLOC = std::allocator<ELEM> > class Cont = std::vector,
    template <typename ELEM2, typename ALLOC2 = std::allocator<ELEM2> > class Cont2 = std::vector
    >


class Command3:AbstractCommand
{
public:
    Command3(uint8_t id,Cont<T> params,Cont1<T1> params1,Cont2<T1> params2):obj(params),obj1(params1),obj2(params2),AbstractCommand(id){}
    QByteArray parseData(void)
    {
        QByteArray temp;
        QDataStream tDStream(&temp,QIODevice::ReadWrite);
        for (Cont<T>::iterator it=obj.begin(); it != obj.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        for (Cont1<T>::iterator it=obj1.begin(); it != obj1.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        for (Cont2<T>::iterator it=obj1.begin(); it != obj1.end(); ++it)
        {
            T t=*it;
            tDStream<< t;
        }
        return temp;
    }
    void setParameters(Cont<T> params,Cont1<T1> params1,Cont2<T1> params2)
    {
        obj=params;
        obj1=params1;
        obj1=params2;
    }
private:
    Cont<T> obj;
    Cont1<T1> obj1;
    Cont2<T1> obj2;
};
//MyClass<int> v1;
//MyClass<int, deque> v2;



#endif // CONCRETECOMMANDS_H
