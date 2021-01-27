#include <iostream>
#include <fstream>
using namespace std;
struct Person
{
    char m_Name[64];
    int n_Age;
};
int main()
{
    ifstream ifs;
    ifs.open("openfile.txt",ios::binary|ios::in);
    if(!ifs)
    {
        cout<<"文件打开失败";
    }
    Person p;
    ifs.read((char*)&p,sizeof(Person));
    cout<<p.m_Name<<" "<<p.n_Age;


}