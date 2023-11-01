#include <iostream>
#include <string>
using namespace std;

int main()
{

    int arreglo[20]; // arreglo de tamaño 20
    int numero_ingresado, i, j;
    // j es una variable que se utiliza para encontrar la posición correcta donde se debe insertar
    // el número ingresado en el arreglo para mantenerlo ordenado en forma ascendente.

    cout << "Ingrese 20 numeros enteros:" << endl;

    for (i = 0; i < 20; i++) 
    {
        cin >> numero_ingresado;

        // Encontrar la posición donde se debe insertar el número para mantener el orden ascendente
        j = i - 1;
        // j comienza en la posición justo antes de la posición actual en el arreglo.
        
        while (j >= 0 && arreglo[j] > numero_ingresado) // j es mayor o igual a 0 para que no salgamos del límite inferior del arreglo 
        {
            arreglo[j + 1] = arreglo[j]; // mover el elemento en la posición arreglo[j] una posición hacia adelante en el arreglo, para abrir espacio para el nuevo número ingresado
            j--; // decrementar j en 1 para verificar la siguiente posición hacia atrás en el arreglo.
        }

        // Insertar el número en la posición correcta
        arreglo[j + 1] = numero_ingresado;
    }

    cout << "El arreglo ordenado es:" << endl;
    
    for (i = 0; i < 20; i++) 
    {
        cout << arreglo[i] << " "; // Mostrar el arreglo ordenado
    }

    return 0;
}