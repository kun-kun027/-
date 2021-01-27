#include <iostream>//构造函数是引用其他函数，那个函数最好是成员函数，设为友元也ok
using namespace std;
class Date
{
public:
    Date()
    {
        setdate();
    }
    Date(int d)
    {
        setdate(d);
    }
    Date(int d,int m)
    {
        setdate(d,m);
    }
    Date(int d,int m ,int y)
    {
        setdate(d,m,y);
    }
    void display()
    {
        cout<<month<<"/"<<day<<"/"<<year<<endl;
    }
private:
    int day;
    int month;
    int year;
    void setdate(int d=7 ,int m=2 ,int y=2003 );
};
void Date:: setdate(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}
int main()
{
    Date a1(14,11,1994);
    a1.display();
    Date a2(24,2,2002);
    a2.display();
    Date a3(25,2,1999);
    a3.display();
    Date a4(7,2,2003);
    a4.display();
    


    return 0;
}