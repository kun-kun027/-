#include <iostream>
#include <string>
using namespace std;
void reverse(char*);
int main()
{
    char a[201];
    gets(a);//输入字符串：gets()  getline(cin,str)  getchar()
    reverse(a);
    puts(a);
}
void reverse(char*s)
{
    char *p=s;
    char *q=s;
    while(*q)
    {
        q++;
    }
    q--;
    while(p<q)
    {
        char temp=*q;
        *q=*p;
        *p=temp;
        q--;
        p++;
    }
}