// 矩阵计算
#include <iostream>
#include <cstdlib>
using namespace std;
class matrix
{
private: //成员就只有行列和数组
    int rows, cols;
    int **p;

public:
    matrix();                           //默认构造函数但不用
    matrix(int &M, int &N);             //构造函数（输入行列）构造框架
    matrix(matrix &A, int &&m, int &n); //右值引用&&；删去第m行第n列
    ~matrix();
    matrix multi(int x);               //数乘
    int det();                         //计算行列式
    void out();                        //输出
    void input();                      //输入矩阵
    matrix operator+(matrix &another); //矩阵加法
    matrix operator*(matrix &another); //矩阵乘法
};
matrix::matrix(int &M, int &N)
{
    rows = M, cols = N; //构建框架
    p = new int *[rows];
    for (int i = 0; i < M; i++)
    {
        p[i] = new int[cols];
    }
}
matrix::matrix(matrix &A, int &&m, int &n) //删除原矩阵中第m行第n列的新矩阵//复制构造函数
{
    int w=0,e=0;
    rows=A.rows-1;
    cols=A.cols-1;
    p=new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[cols];
    }
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j <A.cols; j++)
        {
            if (i == m || j == n)
            {
                continue;
            }
            else
            {
                p[w][e]= A.p[i][j];
                e++;
                if (e > cols - 1)
                {
                    e = 0;
                    w++;
                }
            }
        }
    }

}
matrix::~matrix() //析构函数
{
    for (int i = 0; i < rows; i++)
        delete[] p[i];
    delete[] p;
}
matrix matrix::multi(int x) //数乘
{
    matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.p[i][j] = p[i][j] * x;
    return tmp;
}
void matrix::out() //输出矩阵
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}
void matrix::input() //输入矩阵
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> p[i][j];
}
matrix matrix::operator+(matrix &another)
{
    matrix tmp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tmp.p[i][j] = p[i][j] + another.p[i][j];
    return tmp;
}
matrix matrix::operator*(matrix &another) //矩阵乘法
{
    matrix tmp(rows, another.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < another.cols; j++)
        {
            tmp.p[i][j] = 0;
            for (int a = 0; a < cols; a++)
                tmp.p[i][j] += p[i][a] * another.p[a][j];
        }
    }
    return tmp;
}
int matrix::det()
{
    if (rows == 1)
        return p[0][0];
    else
    {
        int result = 0, flag;
        for (int i = 0; i < cols; i++)
        {
            flag = (i % 2) ? -1 : 1;
            matrix tmp(*this, 0, i);
            result = result + flag * p[0][i] * tmp.det();
        }
        return result;
    }
}
int main()
{
    int M, N;
    cin >> M >> N;
    matrix mA(M, N);
    mA.input();
    int x;
    cin >> x;
    matrix mm1 = mA.multi(x);
    mm1.out();
    int K, L;
    cin >> K >> L;
    matrix mB(K, L);
    mB.input();
    if (M == K && N == L)
    {
        matrix mm2 = mA + mB;
        mm2.out();
    }
    if (N == K)
    {
        matrix mm3 = (mA * mB);
        mm3.out();
    }
    if (M == N)
        cout << mA.det() << endl;
    if (K == L)
        cout << mB.det() << endl;
    return 0;
}
