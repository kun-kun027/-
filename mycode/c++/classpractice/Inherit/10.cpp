// 调整访问控制
// 格式为public：using Base：：但前提是必须可见，也就不能是private
#include <iostream>
using namespace std;
class Base
{
private:
    int b1;

protected:
    int b2;
    void fb2()
    {
        b1 = 1;
    }

public:
    int b3;
    void fb3()
    {
        b1 = 1;
    }
};
class Pri : private Base
{
public:
    using Base::b3;
    using Base::b2;
} ;
int main()
{
}