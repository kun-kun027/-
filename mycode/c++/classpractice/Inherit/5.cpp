#include <iostream>
#include <string>
using namespace std;
class student
{
private:
    string name;
    int id;
public:
   void set()
   {
       string b;int c;
       cin>>b>>c;
       name=b;id=c;

   }
    void display()
    {
        cout<<name<<" "<<id;
    }
};
int main()
{
    student a[3];
    for(int i=0;i<3;i++)
    {
        a[i].set();
    }
     for(int i=0;i<3;i++)
    {
        a[i].display();
    }
}
