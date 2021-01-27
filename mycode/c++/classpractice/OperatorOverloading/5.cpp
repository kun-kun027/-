// 文件操作 打开文件 void open(const *filename,int mode,int access)文件名，打开方式，打开属性
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream file("openfile.txt",ios::in);//ifstream file;file.open("openfile,txt",ios::in);
    file.close();
    if(!file.is_open())
    {
        cout<<"没有打开";
    }
    
}