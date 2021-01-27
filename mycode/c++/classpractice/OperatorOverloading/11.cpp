#include <iostream>
using namespace std;
//整型向量类
class intMyVector
{
public:
    //构造函数
    intMyVector(int count)
    {
        n = count;
        p = new int[count];
    }
    //复制构造函数
    intMyVector(const intMyVector &v)
    {
        n = v.n;
        p = new int[v.n];
        for (int i = 0; i < n; i++)
            p[i] = (v.p)[i];
    }

    friend istream &operator>>(istream &, const intMyVector &);
    friend ostream &operator<<(ostream &, const intMyVector &);
    intMyVector& operator+(intMyVector );

    ~intMyVector()
    {
        delete[] p;
        cout << "destruct" << endl;
    }

private:
    int n;
    int *p;
};

//请分析程序补充内容

int main()
{
    int n;
    cin >> n;
    intMyVector a(n), c(n + 1);
    cin >> a;
    c = a;
    intMyVector b(a);
    cout << a + b + c;
    return 0;
}


ostream &operator<<(ostream &output, const intMyVector &v)
{
    output << "[";
    for (int i = 0; i < (v.n - 1); i++)
        output << v.p[i] << ",";
    output << v.p[v.n - 1] << "]" << endl;
    return output;
}

istream &operator>>(istream &input, const intMyVector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        input >> v.p[i];
    }
    return input;
}
intMyVector &intMyVector:: operator+(intMyVector v)//intMyVector intMyVector::operator +
{

    for (int i = 0; i < v.n; i++)
    {
        p[i] = p[i] + v.p[i];
    }

    return *this;
}