// 多继承
#include <iostream>
using namespace std;
class Bed
{
public:
    Bed():weight(0){}
    void Sleep(){cout<<"Sleep\n";}
    void SetWeight(int i){weight=i;}
protected:
    int weight;
};
class Sofa
{
public:
    Sofa():weight(0){}
    void WatchTV(){cout<<"watch Tv";}
    void SetWeight(int i){weight=i;}
protected:
    int weight;
};
class SleepSofa:public Bed,public Sofa
{
public:
    SleepSofa(){}
    void FoldOut(){cout<<"Foldout\n";}
};
int main()
{
    SleepSofa a;
    a.FoldOut();
    a.Sleep();
    a.WatchTV();
    return 0;
}