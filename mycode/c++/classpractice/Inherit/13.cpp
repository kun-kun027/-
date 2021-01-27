// 虚拟继承 virtual
#include <iostream>
using namespace std;
class Furniture
{
public:
    Furniture(){}
    void SetWeight(int i){weight=i;}
    int GetWeight(){return weight;}
protected:
    int weight;
};
class Bed:virtual public Furniture
{
public:
    Bed(){}
    void sleep()
    {
        cout<<"Sleeping\n";
    }
};
class Sofa:virtual public Furniture
{
public:
    Sofa(){}
    void WatchTV()
    {
        cout<<"Watch TV";
    }
};
class SleepSofa:public Bed,public Sofa
{
public:
    SleepSofa():Sofa(),Bed(){}
    void FoldOut()
    {
        cout<<"FoldOut\n";
    }
};
int main()
{
    SleepSofa ss;
    ss.SetWeight(27);
    cout<<ss.GetWeight()<<endl;
}