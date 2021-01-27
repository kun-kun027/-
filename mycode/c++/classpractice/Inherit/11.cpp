// 继承与组合(继承点类来写圆)
#include <iostream>
using namespace std;
class Point
{
protected:
    double x, y;

public:
    Point(double a = 0, double b = 0) : x(a), y(b) {}//构造函数这种赋值很好
    double xoffset() const { return x; }
    double yoffset() const { return y; }
    void moveTo(double a, double b)
    {
        x = a;
        y = b;
    }
    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
class Circle : public Point
{
    double radius;


public:
    Circle(const Point &p, double r) : Point(p), radius(r) {}
    double getRadius() const { return radius; }
    Point getPoint() const { return *(Point *)this; }
    double getarea() const { return radius * radius*3.14; }
    double getCircum() const { return 2 * radius * 3.14; }
    void moveTo(double a, double b)
    {
        x = a;
        y = b;
    }
    void modifyRadius(double r)
    {
        radius = r;
    }
};
int main()
{
    Point a(3,4);
    a.print();
    Circle b(a,3);
    cout<<b.getarea();
    return 0;
}