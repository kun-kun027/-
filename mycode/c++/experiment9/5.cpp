#include <iostream>
using namespace std;
class person
{
private:
    int no;
    person *next;

public:
    person(int num) //构造小孩
    {
        no = num;
        next = NULL;
    }
    void setNext(person *p)
    {
        next = p;
    }
    int getNo()
    {
        return no;
    }
    person *getNext()
    {
        return next;
    }
};
class cycle
{
private:
    person *start;
    int out;
    int inQueue;

public:
    cycle(int num, int from, int whoOut) //构造函数
    {
        inQueue = num, out = whoOut;
        person *prv = NULL, *first = NULL;
        for (int i = 1; i <= num; i++)
        {
            person *p = new person(i); //构建链表
            if (i == 1)
                first = p;
            if (i == from)
                start = p;
            if (i > 1)
                prv->setNext(p);
            prv = p;
        }
        prv->setNext(first);
    }
    int getInQueue()
    {
        return inQueue;
    }
    void cnt()
    {
        person *pivot;
        if (out > 1)
        {
            for (int i = out; i > 2; i--)
            {
                start = start->getNext();
            }
            pivot = start->getNext();
            start->setNext(pivot->getNext());
            start = start->getNext();
            inQueue--;
        }
        else
        {
            person *pivot;
            for(int i=1;i<inQueue;i++)
            {
                start=start->getNext();
            }
            pivot=start->getNext();
            start->setNext(pivot->getNext());
            start = start->getNext();
            inQueue--;
        }
        
    }
    person *getStart()
    {
        return start;
    }
    ~cycle()
    {
        delete start;
    }
};
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    cycle *p = new cycle(n, k, m);
    while (p->getInQueue() > 1)
        p->cnt();
    person *winner = p->getStart();
    cout << winner->getNo() << endl;
    delete p;
    return 0;
}
