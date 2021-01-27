#include <iostream>//字符串的复制和在一个类中调用其他类的构造函数
#include <cstring>
using namespace std;
class ID
{
private:
    int id;
public:
    friend class student;
    ID(int m)
    {
        id=m;
    }
};
class student
{
private:
    char name[20];
    ID id;
public:
    student(char *p,int b):id(b)
    {
        strncpy(name,p,sizeof(name));
        name[19]='\0';
    }
    void display()
    {
        cout<<name<<" "<<id.id;
    }
};
int main()
{
    student a("zengkun",1);
    a.display();
    return 0;
}