/*
Escribir una función que, dado un arreglo de int y su dimensión lógica, invierta los elementos del arreglo.
*/

#include <iostream>
#include <string>
using namespace std;

void invertirDigitos(int arreglo[], int dl)
{
    int inicio = 0;
    int final = dl - 1;

    while(inicio < final)
    {
        int temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[final];
        arreglo[final] = temporal;

        inicio++;
        final--;
    }
}

int main()
{
    int dim_log;
    cout << "Ingrese la dimension logica del arreglo: ";
    cin >> dim_log;

    if(dim_log <= 0)
    {
        cout << "La dimensión logica debe ser mayor a 0." << endl;
        main();
    }

    int arreglo[dim_log];
    cout << "Ingrese los elementos del arreglo: " << endl;
    for(int i = 0; i < dim_log; i++)
    {
        cout << "Numero " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    invertirDigitos(arreglo, dim_log);

    cout << "Arreglo invertido: ";
    for(int i = 0; i < dim_log; i++)
    {
        cout << arreglo[i] << " - ";
    }

    return 0;
}