#include <iostream>//创建链表，已经无输入是停止输入
using namespace std;
struct Student
{
    long number;
    float score;
    Student *next;
};
Student *head;
Student *getNode() //创建节点
{
    int num;
    float sc;
    if(cin >> num >> sc)
    {
        Student *p = new Student;
        p->number = num;
        p->score = sc;
        p->next = 0;
        return p;
    }
    else
    {
        return NULL;
    }
    
}
void Creat() //形成链表
{
    if ((head = getNode()) == 0)
    {
        return;
    }
    for (Student *PE = head, *PS; PS = getNode(); PE = PS)//判断条件为PS=getNode();vftg
    {
        PE->next = PS;
    }
}
void ShowList()
{
    for (Student *p = head; p; p = p->next)
    {
        cout << p->number << "  " << p->score << endl;
    }
}
int main()
{
    Creat();
    ShowList();
}