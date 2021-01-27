#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Student
{
private:
    string id;
    double gpa;

public:
    Student()
    {
        string a;
        double x;
        cin >> a;
        cin >> x;
        id = a;
        gpa = x;
    }
    string getid()
    {
        return id;
    }
    double getgpa()
    {
        return gpa;
    }
};
void pass(Student *pStu, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (pStu[i].getgpa() >= 60)
        {
            cout << left << setw(12) << pStu[i].getid() << fixed << setprecision(1) << pStu[i].getgpa() << endl;
        }
    }
    for (i = 0; i < size; i++)
    {
        if (pStu[i].getgpa() >= 60)
            break;
    }
    if (i == size)
    {
        cout << "not exist";
    }
}
int main()
{
    int n;
    cin >> n;
    Student *stu = new Student[n];
    pass(stu, n);
    delete[] stu;
    return 0;
}