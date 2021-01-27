#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Book
{
public:
    Book();
    void setInfo();
    void show();

private:
    float price;
    char *shelf_id;
};
Book::Book()
{
    price = 0;
    shelf_id = NULL;
}
void Book::setInfo()
{
    shelf_id = new char[100];
    cin.getline(shelf_id, 100);
    float a;
    cin >> a;
    price = a;
    cin.get();
}
void Book::show()
{
    cout << "Shelf_ID:"
         << " " << left << setw(18) << shelf_id << "Price:"
         << " " << price << endl;
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    Book library[n];
    for (int i = 0; i < n; i++)
    {
        library[i].setInfo();
    }
    for (int i = 0; i < n; i++)
    {
        library[i].show();
    }
    return 0;
}