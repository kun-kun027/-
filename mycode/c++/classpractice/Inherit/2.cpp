#include <iostream>//构建链表
using namespace std;//结构体一个类 结构体的操作又是一个类
struct Node
{
    int a;
    Node *next;
};
class que
{
private:
    Node *pfirst;
    Node *pcurrent;
    Node *pivot;

public:
    que()
    {
        pfirst=NULL;
    }
    void put(int m)
    {
        Node *b=new Node;
        b->a=m;
        b->next=pfirst;
        pfirst=b;
    }
    void get(int m)
    {
        pcurrent=pfirst,pivot=pcurrent->next;
        for(pcurrent;;pcurrent=pcurrent->next,pivot=pcurrent->next)
        {
            if(pfirst->a==m)
            {
                pivot=pfirst->next;
                pfirst=pivot;
                break;
            }
            else if(pivot->a==m)
            {
                pcurrent->next=pivot->next;
                break;
            }
            
        }
    }
    void display()
    {
        pcurrent=pfirst;
        for(pcurrent;;pcurrent=pcurrent->next)
        {
            if(pfirst==NULL)
            {
                cout<<"数据已全部删除";
                break;
            }
            if(pcurrent==NULL)
            {
                break;
            }
             cout<<pcurrent->a<<" ";
        }
    }
    ~que()
    {
        delete pfirst;
        delete pivot;
        delete pcurrent;
    }
};

int main()
{
    que s;
    s.put(25);
    s.display();
    s.put(24);
    s.display();
    s.put(7);
    s.display();
    s.get(7);
    s.display();
    s.get(24);
    s.display();
    s.get(25);
    s.display();
    return 0;
}