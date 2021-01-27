#include <iostream>
using namespace std;
class silly
{
    silly(int &i):ten(10),refi(i){};
    protected:
    const int ten;
    int &refi;
}
int main()
{

}