#include <iostream>
#include <string>
using namespace std;

int min(int a, int b) // Funcion que verifica si el primer numero es menor que el segundo
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int f(int arreglo[], int dl) //
{
    if (dl == 1) // Si la dimension logica es 1
    {
        return arreglo[0]; // Retorna el primer elemento del arreglo
    }
    else // Si la dimension logica es mayor a 1
    {
        return min(arreglo[dl-1], f(arreglo, dl-1));
    }
}

int main()
{
    int a[] = { 6,2,3,7,9,4 };
    int dl = 6;
    cout << f(a, dl);
}

/*
Como funciona este programa:
1. Se llama a la función f(a, dl), donde a es el arreglo y dl es la longitud lógica del arreglo (6 en este caso)
2. Dentro de f():
    Como dl no es igual a 1 entonces pasa al else
    Se compara arreglo[dl-1] (es decir, arreglo[5] que es 4) con el resultado de la llamada recursiva f(arreglo, dl-1)
    Se realiza la llamada recursiva: f(a, 5). La función se llama a sí misma con dl reducido en 1
3. Nueva llamada a f() con dl igual a 5:
    Se compara arreglo[dl-1] (es decir, arreglo[4] que es 9) con el resultado de la llamada recursiva f(arreglo, dl-1)
    Se realiza la llamada recursiva: f(a, 4)
4. Nueva llamada a f() con dl igual a 4:
    Se compara arreglo[dl-1] (es decir, arreglo[3] que es 7) con el resultado de la llamada recursiva f(arreglo, dl-1)
    Se realiza la llamada recursiva: f(a, 3)
5. Nueva llamada a f() con dl igual a 3:
    Se compara arreglo[dl-1] (es decir, arreglo[2] que es 3) con el resultado de la llamada recursiva f(arreglo, dl-1)
    Se realiza la llamada recursiva: f(a, 2)
6. Nueva llamada a f() con dl igual a 2:
    Se compara arreglo[dl-1] (es decir, arreglo[1] que es 2) con el resultado de la llamada recursiva f(arreglo, dl-1)
    Se realiza la llamada recursiva: f(a, 1)
7. Nueva llamada a f() con dl igual a 1:
    Al llegar a dl igual a 1, la función retorna el primer elemento del arreglo, es decir, arreglo[0] que es 6
8. Las llamadas recursivas regresan con sus respectivos valores:
    f(a, 1) retorna 6.
    f(a, 2) compara 2 con 6 y retorna 2 (el mínimo entre ambos).
    f(a, 3) compara 3 con 2 y retorna 2.
    f(a, 4) compara 7 con 2 y retorna 2.
    f(a, 5) compara 9 con 2 y retorna 2.
    La llamada inicial f(a, 6) compara 4 con 2 y retorna 2.
9. Finalmente, f lo que hace es ver cual es el menor numero dentro del arreglo, que es 2
*/