// 前增量与后增量 a++返回对象，(int)++a返回引用 
#include <iostream>
using namespace std;
class Increase
{
public:
    Increase(int x):value(x){}
    Increase &operator++();
    Increase operator++(int);
    void display(){cout<<"the value is"<<value<<endl;}
private:
    int value;
};
Increase &Increase::operator++()
{
    value++;
    return *this;
}
Increase Increase::operator++(int)
{
    Increase temp(*this);
    value++;
    return temp;
}
int main()
{
    Increase n(20);
    n.display();
    (n++).display();
    n.display();
}