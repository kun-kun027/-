// 继承2.cpp
// 保护和公共在子类中可以直接使用，但是private不可以
// 理解子类对父类数据的访问，外界对自雷数据的访问
  #include <iostream>
#include <cstring>
using namespace std;
class Base
{
private:
    int b1;
protected:
    void fb2()
    {
        b1=1;
    }
public:
    void fb3()
    {
        b1=2;
    }
};
class pub:private Base
{
public:
    void test()
    {
        fb2();
        fb3();
    }

};
int main()
{
    pub a;
    a.test();
    a.fb2
    ();
}
