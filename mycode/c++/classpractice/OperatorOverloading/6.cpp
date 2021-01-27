#include <iostream>//写文件
#include <fstream>
using namespace std;
int main()
{
    fstream out("openfile.txt");
    if(!out)
    {
        cout<<"no open";
        
    }
    else
    {
        out<<"This is a line.\n";
        out<<"This is another line.\n";
        out.close();
    }
    cout<<1;
    if(out)
    {
        cout<<"no open";
        
    }
    return 0;
    
}