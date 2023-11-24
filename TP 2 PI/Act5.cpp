/*
Implementar una función llamada mas_uno que tiene como parámetro un arreglo estático de enteros y que
incrementa en uno el valor de cada elemento de dicho arreglo. Añadir otros parámetros que se necesiten.
*/

#include <iostream>
#include <string>
using namespace std;

const int dimension_logica = 5;

void mas_uno(int arreglo[], int dl)
{
    for(int i = 0; i < dl; i++)
    {
        arreglo[i]++;
    }
}

int main()
{
    int mi_arreglo[dimension_logica] = {1, 2, 3, 4, 5};

    mas_uno(mi_arreglo, dimension_logica);

    for (int i = 0; i < dimension_logica; i++)
    {
        cout << mi_arreglo[i] << " ";
    }

    return 0;
}