#include <iostream>
#include <algorithm>
using namespace std;
struct movie //建立结构体(音频 字幕 非常满意的人数  一般的人数)
{
    int i;
    int sound;
    int character;
    int num1 = 0;
    int num2 = 0;
};
bool cmp(movie a, movie b) //排序规则
{
    if (a.num1 < b.num1)
    {
        return 1;
    }
    else if (a.num1 == b.num1)
    {
        if (a.num2 < b.num2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
bool rule(movie a, movie b)
{
    if (a.i < b.i)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; //输入科学家的语言
    }
    cin >> m;
    movie x[m];
    for (int i = 0; i < m; i++)
    {
        x[i].i = i + 1;
        cin >> x[i].sound;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x[i].character;
    }
    for (int i = 0; i < m; i++) //每个电影遍历所以科学家确定num1与num2
    {
        for (int t = 0; t < n; t++)
        {
            if (a[t] == x[i].sound)
            {
                x[i].num1++;
            }
            if (a[t] == x[i].character)
            {
                x[i].num2++;
            }
        }
    }
    bool flag = 0; //如果没有令人满意的电影就输出"unsatisfied";

    for (int i = 0; i < m; i++)
    {
        if (x[i].num1 != 0)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "unsatisfied";
    }
    else
    {
        sort(x, x + m, cmp); //排序
        int g = x[m - 1].num1;
        int k = x[m - 1].num2;
        sort(x, x + m, rule);
        for (int i = 0; i < m; i++)
        {
            if (x[i].num1 == g && x[i].num2 == k)
            {
                cout << x[i].i << " ";
            }
        }
    }
}