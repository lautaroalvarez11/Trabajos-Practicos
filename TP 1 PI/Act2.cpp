#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    int numero;
    int contadorNegativos = 0;

    do
    {
        cout << "Ingresa un numero (0 para terminar): ";
        cin >> numero;

        if (numero < 0)
        {
            contadorNegativos++;
        }
    } while (numero != 0);

    cout << "Cantidad de numeros negativos leidos: " << contadorNegativos << endl;

    return 0;
}