#include <iostream>
#include <string>
using namespace std;

int en_desorden (double arreglo[], int dimension)
{
    for (int indice = 0; indice < dimension; indice++)
    {
        if (a[indice] > a[indice + 1])
        {
            return indice + 1;
        }
        return -1;
    }
}

/*
La función tiene un error de índice y un problema de lógica.
El error principal es que se intenta acceder a "a[indice + 1]"
en la última iteración del bucle, lo que resultará en un acceso
fuera de los límites del arreglo y provocará que la función no
haga lo que debe. Entonces la solución es que en la condición del
bucle for se ponga "indice < dimension - 1"

También, el return -1 está dentro del bucle,
por lo que se ejecutará en la primera iteración si no se encuentra
ningún valor mayor en el arreglo, entonces debe ir afuera del bucle for
*/