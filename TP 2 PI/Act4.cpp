/*
Cargar un arreglo con 20 números enteros ingresados por teclado de manera que el arreglo siempre se
encuentre ordenado en forma ascendente. El arreglo se cargará por completo.
Hacer tres variantes, suponiendo que el usuario carga los datos de las siguientes formas:
a) El usuario ingresa los números en orden ascendente.
b) El usuario ingresa los números en orden descendente.
c) El usuario ingresa los números sin un orden en particular.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

    int arreglo[20]; // Arreglo de tamaño 20
    int numero_ingresado, j;
    /*
    j se utiliza para encontrar la posición correcta donde se debe insertar
    el número ingresado en el arreglo para mantenerlo ordenado en forma ascendente
    */

    cout << "Ingrese 20 numeros enteros:" << endl;

    for (int i = 0; i < 20; i++) 
    {
        cin >> numero_ingresado;

        // Encontrar la posición donde se debe insertar el número para mantener el orden ascendente
        j = i - 1; // j comienza en la posición justo antes de la posición actual en el arreglo
        
        while (j >= 0 && arreglo[j] > numero_ingresado) // Mientras j sea mayor o igual a 0 para no salir del límite inferior del arreglo 
        {
            arreglo[j + 1] = arreglo[j]; // Mover el elemento en la posición arreglo[j] una posición hacia adelante en el arreglo, para abrir espacio para el nuevo número ingresado
            j--; // Decrementar j en 1 para verificar la siguiente posición hacia atrás en el arreglo
        }

        arreglo[j + 1] = numero_ingresado; // Insertar el número en la posición correcta
    }

    cout << "El arreglo ordenado es:" << endl;
    
    for (int i = 0; i < 20; i++) 
    {
        cout << arreglo[i] << " "; // Mostrar el arreglo ordenado
    }

    return 0;
}