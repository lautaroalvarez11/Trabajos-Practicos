#include <iostream>
#include <string>
using namespace std;

void funcion(const int &x, int &y, int z)
{
    x++;
    y = 12;
    z = 20;
}

int main()
{
    int a = 0;
    int b = 9;
    funcion(a, 17, b);
    cout << "Variable a: " << a << endl;
    cout << "Variable b: " << b << endl;
    return 0;
}

/*
El primer error que presenta este código es que se intenta modificar
el valor de x que es una constante, lo cual no se puede

El segundo error que presenta este código es que se intenta pasar el valor 17 como
argumento para el parametro y que es una referencia a un entero. Esto no se puede
ya que no se puede pasar un valor literal como argumento a una referencia no constante,
se debe pasar como argumento una variable o una expresión que sea modificable
*/