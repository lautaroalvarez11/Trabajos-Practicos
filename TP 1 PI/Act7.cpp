#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cout << "Ingrese la cantidad de numeros a trabajar: ";
    cin >> N;

    int numero;
    int minimo;
    int maximo;

    for(int i = 0; i < N; ++i)
    {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero;

        if(numero < minimo)
        {
            minimo = numero;
        }
        if(numero > maximo)
        {
            maximo = numero;
        }
    }   

    cout << "El numero mas grande es: " << maximo << endl;
    cout << "El numero mas pequeño es: " << minimo << endl;

    return 0;
}