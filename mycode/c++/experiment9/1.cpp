#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    void setPoint();
    int getX() const;
    int getY() const;
};
void Point::setPoint()
{
    int a, b;
    cin >> a >> b;
    x = a;
    y = b;
}
int Point::getX() const
{
    return x;
}
int Point::getY() const
{
    return y;
}
double myDistance(int xVal, int yVal)
{
    return sqrt(xVal * xVal + yVal * yVal);
}
int main()
{
    Point A, B;
    A.setPoint();
    B.setPoint();
    cout << myDistance(A.getX() - B.getX(), A.getY() - B.getY());
    return 0;
}