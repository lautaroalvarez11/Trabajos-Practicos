#include <iostream>
#include <string>
using namespace std;

void dos(int a[], int cuantos) 
{
    for (int indice = 0; indice < cuantos; indice++) 
    {
        a[indice] = 2;
    }
}

/*
int mi_arreglo[29];
dos(mi_arreglo, 29); Si
dos(mi_arreglo[], 29); No
dos(mi_arreglo, 10); Si
dos(mi_arreglo, 55); Si
int tu_arreglo[100]; 
dos(tu_arreglo, 100); Si
dos(mi_arreglo[3], 29); No porque se pasa una parte del arreglo, hay que pasarlo completo
*/