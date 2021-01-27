// 重载赋值运算符 以及赋值运算符与拷贝函数的比较 先析构在构造
#include <iostream>
#include <cstring>
using namespace std;
class Name
{
public:
    Name(){pname=0;}
    Name(char *p){copyName(p);}
    Name(Name &s){copyName(s.pname);}
    ~Name(){deleteName();}
    Name&operator=(Name&s)
    {
        deleteName();
        copyName(s.pname);
        return *this;
    }
    void display()
    {
        cout<<pname<<endl;
    }
protected:
    char *pname;
    void deleteName();
    void copyName(char*p);
};
void Name::copyName(char *p)
{
    pname=new char[strlen(p)+1];
    strncpy(pname,p,sizeof(pname));
}
void Name::deleteName()
{
    if(pname)
    {
        delete pname;
    }
    pname=0;
}

int main()
{
    Name s("jack");
    Name t("rooike");
    t.display();
    t=s;
    t.display();
    

}