// 继承3.cpp
// 私有继承 私有继承里面有父类的数据但是不能直接使用，可以使用函数在成员函数里使用父类的函数
#include <iostream>
using namespace std;
class Animal
{
public:
    Animal(){}
    void eat()
    {
        cout<<"eat"<<endl;
    }
};
class Giraffe:private Animal
{
public:
    Giraffe(){}
    void StrechNeck(double)
    {
        cout<<"strech neck"<<endl;
    }
    void take()
    {
        eat();
    }
};
class cat:public Animal
{
public:
    cat(){}
    void Meaw()
    {
        cout<<"Meaw"<<endl;
    }
};
void Func(Animal &a)
{
    a.eat();
}
int main()
{
    cat dao;
    Giraffe gir;
    gir.take();
    Func(dao);
    
}
