// 重载插入运算符
#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(){real=0;image=0;}
    Complex(int r,int i):real(r),image(i){}
    Complex operator+(Complex&c);
    Complex(int r){real=r;}
    friend ostream&operator<<(ostream&,Complex&);
    friend istream&operator>>(istream&,Complex&);
private:
    int real;
    int image;
};
Complex Complex::operator+(Complex&c)
{
    Complex x(c.real+real,c.image+image);
    return x;
}
ostream&operator<<(ostream& output,Complex& c)
{
    output<<"("<<c.real<<"+"<<c.image<<"i"<<")";
    return output;
}
istream&operator>>(istream&input,Complex&c)
{
    input>>c.real>>c.image;
    return input;
}
int main()
{
    Complex c1,c2;
    Complex c3(1);
    cin>>c1>>c2;
    c3=c1+c2;
    // cout<<c1+c2;//cout<<c1+c2;就会报错
    cout<<c3;
}
/* 
    friend ostream& operator<<(ostream&,Complex& a);
    ostream& operator<<(ostream&output,Complex&a)
    {
        output<<"";
        return output;
    }
    friend istream& operator>>(istream&a,Complex&c);
    istream& operator>>(istream&input,Complex&c)
    {
        input>>;
        return input;
    }
 */