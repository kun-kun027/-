#include <iostream>//Vector类
using namespace std;
class intMyVector
{
public:
    intMyVector(int count)
    {

        n = count;
        p = new int[count];
        //
    }
    intMyVector(intMyVector &v)
    {
        n = v.n;
        for (int i = 0; i < n; i++)
        {
            p[i] = v.p[i];
        }
    }
    intMyVector &operator+(intMyVector &v);
    intMyVector &operator=(intMyVector &v);
    friend ostream &operator<<(ostream &output, intMyVector &v);
    friend istream &operator>>(istream &input, intMyVector &v);
    ~intMyVector()
    {
        delete[] p;
        cout << "destruct" << endl;
    }

private:
    int n;
    int *p;
};
intMyVector &intMyVector::operator+(intMyVector &v)
{
    intMyVector temp(v.n);
    
    for (int i = 0; i < (v.n); i++)
    {
        temp.p[i] = p[i] + v.p[i];
    }
    return temp;
}
intMyVector &intMyVector::operator=(intMyVector &v)
{
    if (p != NULL)
        delete[] p;
    n = v.n;
    p = new int[v.n];
    int *pt = v.p;
    for (int i = 0; i < n; i++)
    {
        p[i] = pt[i];
    }
    return *this;
}
//*/
ostream &operator<<(ostream &output, intMyVector &v)
{
    output << "[";
    for (int i = 0; i < (v.n - 1); i++)
        output << v.p[i] << ",";
    output << v.p[v.n - 1] << "]" << endl;
    return output;
}
istream &operator>>(istream &input, intMyVector &v)
{
    for (int i = 0; i < (v.n); i++)

        input >> v.p[i];

    return input;
}
int main()
{
    int n;
    cin >> n;
    intMyVector a(n), b(n);
    cin >> a;
    cin >> b;
    cout << (a + b);
    return 0;
}
