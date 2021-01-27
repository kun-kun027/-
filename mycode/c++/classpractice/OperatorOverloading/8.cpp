#include <iostream>//文本类的读取  按单词读取 按行数读取  按字符读取
#include <fstream>
using namespace std;
int main()
{
    ifstream in;
    in.open("openfile.txt",ios::in);
    if(!in)
    {
        cout<<"文件打开失败";
    }
    char buf2[1024];
    /*while(in>>buf2)//方法一
        cout<<buf2<<endl;*/
    in.clear();
    in.seekg(ios::beg);
   /* while(in.getline(buf2,sizeof(buf2)))//一行一行的读取
        cout<<buf2<<endl;
    in.clear();
    in.seekg(ios::beg);*/
    char ch;
    while((ch=in.get())!=EOF)
        cout<<ch;
    in.close();
    string buf1;
    while(getline(in,buf1))
    {
        cout<<buf1<<endl;
    }
    

}