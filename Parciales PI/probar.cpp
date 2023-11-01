#include <iostream>
#include <string>
using namespace std;

void hacer_calculo(int &x, int y, int &z)
{
    cout << x << " " << y << " " << z << endl;
    x = 1;
    y = 2;
    z = 3;
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;
    hacer_calculo(a, b, c);
    cout << a << " " << b << " " << c;
    return 0;
}