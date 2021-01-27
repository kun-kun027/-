// 人民币  注意返回类型
#include <iostream>
using namespace std;
class RMB
{
public:
    RMB(double d){yuan=d,jf=(d-yuan)*100;}
    RMB interest(double rate);
    RMB add(RMB d);
    void display(){cout<<(yuan+jf/100)<<endl;}
    RMB operator+(RMB d){return RMB(yuan+d.yuan+(jf+d.jf)/100);}//operator +
    RMB operator*(double rate){return RMB((yuan+jf/100)*rate);}
private:
    int yuan;
    int jf;
};
RMB RMB::add(RMB d)
{
    return RMB(yuan+d.yuan+(jf+d.jf)/100);
}
RMB RMB::interest(double rate)
{
   return RMB((yuan+jf/100)*rate);
};
RMB expense1(RMB principle,double rate)
{
    RMB interest=principle.interest(rate);
    return principle.add(interest);
}
RMB expense2(RMB principle,double rate)
{
    RMB interest=principle*rate;
    return principle+interest;
}
int main()
{
    RMB x=10000.0;
    double yrate=0.035;
    expense1(x,yrate).display();
    expense2(x,yrate).display();

}