/*
Escribir un programa que permita al usuario ingresar números enteros positivos,
los números ingresados no deben almacenarse.
Al finalizar, informar la cantidad de veces que apareció cada dígito (del 0 al 9) en todos los números.
*/

#include <iostream>
#include <string>
using namespace std;

const int NUM_DIGITOS = 10; // Número de dígitos (del 0 al 9)

int main()
{ 
    int contadores[NUM_DIGITOS] = {0}; // Inicializamos todos los contadores a 0

    int numero;
    
    cout << "Ingrese numeros enteros positivos (ingrese un numero negativo para finalizar):" << endl;

    while (true)
    {
        cin >> numero;

        if (numero < 0)
        {
            break; // Salir del bucle si se ingresa un número negativo
        }

        // Procesar cada dígito del número
        while (numero > 0)
        {
            int digito = numero % 10; // Obtener el último dígito del número
            contadores[digito]++; // Incrementar el contador correspondiente al dígito
            numero /= 10; // Eliminar el último dígito del número
        }
    }

    cout << "Cantidad de veces que apareció cada dígito:" << endl;
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
        cout << "Digito " << i << ": " << contadores[i] << " veces" << endl;
    }

    return 0;
}