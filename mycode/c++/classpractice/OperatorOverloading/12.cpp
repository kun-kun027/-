#include <bits/stdc++.h>
using namespace std;
struct Book
{
    int node;
    string name;
    char a;
    int price;
};
bool cmp(Book k, Book b)
{
    if ((k.a == 'E' && b.a == 'M') || (k.a == 'E' && b.a == 'T') || (k.a == 'M' && b.a == 'T'))
    {
        return 1;
    }
    else if ((k.a == 'E' && b.a == 'E') || (k.a == 'M' && b.a == 'M') || (k.a == 'T' && b.a == 'T'))
    {
        if (k.price > b.price)
        {
            return 1;
        }
        else if (k.price == b.price)
        {
            if (k.node < b.node)
            {
                return 1;
            }
        }
        return 0;
    }
}
int main()
{
    Book x[100];
    int l[3];
    l[0] = 0;
    l[1] = 0;
    l[2] = 0;
    int i = 0;
    while (cin >> x[i].node >> x[i].name >> x[i].a >> x[i].price) //个数i
    {
        i++;
    }
    Book y[i];
    for (int t = 0; t < i; t++)
    {
        y[t].node = x[t].node;
        y[t].name = x[t].name;
        y[t].a = x[t].a;
        y[t].price = x[t].price;
    }
    sort(y, y + i, cmp);
    for (int t = 0; t < i ; t++)
    {
        if (y[t].a == 'E')
        {1
            l[0]++;
        }
        if (y[t].a == 'M')
        {
            l[1]++;
        }
        if (y[t].a == 'T')
        {
            l[2]++;
        }
    }
    cout << "E:" << l[0] << endl;
    for (int t = 0; t < i; t++)
    {
        if (y[t].a == 'E')
        {
            cout << y[t].node << " " << y[t].name << " " << y[t].a << " " << y[t].price << endl;
        }
    }
    cout << "M:" << l[1] << endl;
    for (int t = 0; t < i; t++)
    {
        if (y[t].a == 'M')
        {
            cout << y[t].node << " " << y[t].name << " " << y[t].a << " " << y[t].price << endl;
        }
    }
    cout << "T:" << l[2] << endl;
    for (int t = 0; t < i; t++)
    {
        if (y[t].a == 'T')
        {
            cout << y[t].node << " " << y[t].name << " " << y[t].a << " " << y[t].price << endl;
        }
    }
}
