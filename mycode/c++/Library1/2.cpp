#include <iostream>//自己没看书打的
using namespace std;
struct Student
{
    long number;
    float score;
    Student* next;
};
Student *head;
Student* getNode()
{
    long num;
    float sc;
    if(cin>>num>>sc)
    {
        Student *p=new Student;
        p->number=num;
        p->score=sc;
        p->next=NULL;
        return p;
    }
    else
    {
        return NULL;
    }
}
void Creat()
{
    if((head=getNode())==NULL)
    {
        return;
    }
    for(Student*PE=head,*PS;PS=getNode();PE=PS)
    {
        PE->next=PS;
    }
}
void ShowList()
{
    for(Student *P=head;P;P=P->next)
    {
        cout<<P->number<<"  "<<P->score<<endl;
    }
}
int main()
{
    Creat();
    ShowList();
}