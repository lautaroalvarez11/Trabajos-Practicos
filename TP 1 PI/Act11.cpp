#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;
    cout << "Ingrese una frase: ";
    cin >> cadena;

    string cadena_invertida = " ";
    for(int i = cadena.length() - 1; i >= 0; i--)
    {
        cadena_invertida += cadena[i];
    }

    cout << "La frase al reves es: " << cadena_invertida;

    return 0;
}