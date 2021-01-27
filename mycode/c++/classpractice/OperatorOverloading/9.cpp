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
    ofstream ofs;
    ofs.open("openfile.txt",ios::in|ios::out|ios::binary|ios::app);
    Person p={"曹操",23};
    ofs.write((const char *)&p,sizeof(Person));
    ofs.close();
}
