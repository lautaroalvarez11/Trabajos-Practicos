#include <iostream>
#include <string>
using namespace std;

int main()
{

    int denominador;

    cout << "Ingrese el denominador deseado: ";
    cin >> denominador;

    double suma = 0.0;

    for(int i = 1; i <= denominador; ++i)
    {
        suma += 1.0 / i;
    }

    cout << "La suma de la serie armonica hasta n igual a " << denominador << " es: " << suma << endl;

    return 0;
}