#include <iostream>//字符串的复制  char*用<cstring>里的strncpy  string直接相等
#include <cstring>
#include <string>
using namespace std;
class student
{
private:
    // char name[20];
    string name;
public:
    student(string b)
    {
       /*   strncpy(name,a,20);
        name[19]='\0'; */
        /* for(int i=0;i<20;i++)
        {
            name[i]=a[i];
        }
        name[19]='\0'; */
        name=b;
    }
    void display()
    {
        cout<<name;
    }
};
int main()
{
    student a("jack");
    a.display();
    return 0;
}