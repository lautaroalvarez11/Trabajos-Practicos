#include <iostream>
#include <string>
using namespace std;

void intercambiarValores (int &x, int &y)
{
    int cambiado = x;
    x = y;
    y = cambiado;
}

int main()
{
    int a = 10;
    int b = 25;
    intercambiarValores(a,b);
    cout << "Variable a: " << a << endl;
    cout << "Variable b: " << b << endl;
    return 0;
}
