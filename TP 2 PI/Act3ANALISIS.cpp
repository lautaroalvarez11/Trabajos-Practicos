/*
Suponer que esperamos que los elementos de un arreglo estén ordenados de menor a mayor (de modo que
cada elemento es menor o igual que el siguiente: a[0] <= a[1] <= a[2] ...)
Sin embargo, para estar seguros queremos probar el arreglo usando una función que informe si encuentra que
algún elemento no está en orden (retornando su índice en caso de ser así, o retornando -1 si todo el arreglo
está ordenado). Se supone que el siguiente código realiza esa prueba, pero contiene un error muy usual cuando
se trabaja con arreglos, ¿en qué consiste?
*/

#include <iostream>
#include <string>
using namespace std;

int en_desorden (double arreglo[], int dimension)
{
    for (int indice = 0; indice < dimension; indice++)
    {
        if (arreglo[indice] > arreglo[indice + 1])
        {
            return indice + 1;
        }
        return -1;
    }
}

/*
La función tiene un error de índice y un problema de lógica.
El error principal es que se intenta acceder a "arreglo[indice + 1]"
en la última iteración del bucle, lo que resultará en un acceso
fuera de los límites del arreglo y provocará que la función no
haga lo que debe. Entonces la solución es que en la condición del
bucle for se ponga "indice < dimension - 1"

También, el return -1 está dentro del bucle,
por lo que se ejecutará en la primera iteración si no se encuentra
ningún valor mayor en el arreglo, entonces debe ir afuera del bucle for
*/