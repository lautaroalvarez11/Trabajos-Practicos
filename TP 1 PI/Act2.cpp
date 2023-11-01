#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    int numero;
    int contadorNegativos = 0;

    do
    {
        cout << "Ingresa un número (0 para terminar): ";
        cin >> numero;

        if (numero < 0)
        {
            contadorNegativos++;
        }
    } while (numero != 0);

    cout << "Cantidad de números negativos leídos: " << contadorNegativos << endl;

    return 0;
}