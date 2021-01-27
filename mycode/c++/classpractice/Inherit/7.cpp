// 继承1.cpp
#include <iostream>
#include <cstring>//复制字符串strncpy
using namespace std;
class Advisor
{
private:
    int noOfmeeting;
};//注意分号
class student//传参的时候研究生可以当做大学生传
{
private:
    char name[40];
    int somehour;
    float average;
public:
    student(char *pname="no name")
    {
        strncpy(name,pname,sizeof(name));
        average=somehour=0;
    }
    void addCourse(int hours,float grade)
    {
        average=(somehour*average+grade);
        somehour+=hours;
        average/=somehour;
    }
    int gethours()
    {
        return somehour;
    }
    float getAverage()
    {
        return average;
    }
    void display()
    {
        cout<<"name=\""<<name<<"\",hours="<<somehour<<",average="<<average<<""<<endl;
    };
};
class GraduateStudent:public student
{
private:
    Advisor advisor;
    int qualifierGrade;
public:
    GraduateStudent(char *pname,Advisor &adv):student(pname),advisor(adv)
    {
        qualifierGrade=0;
    }
    int getQulifierGrade()
    {
        return qualifierGrade;
    }
};
void fn(student& a)
{
    a.display();
}
int main()
{
    Advisor ad;
    student ds("LO lee undergrade");
    GraduateStudent gs("zengkun",ad);
    ds.addCourse(3,2.5);
    fn(ds);
    gs.addCourse(3,3.0);
    fn(gs);
}