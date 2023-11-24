/*
Escribir una variante del programa anterior en la que, en lugar de informar la cantidad de veces que apareció
cada dígito, se informe si apareció o no cada dígito en todos los números ingresados. Analizar cómo puede
resolverse este ejercicio evitando contabilizar la cantidad de dígitos.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int NUM_DIGITOS = 10;
    bool digitos_presentes[NUM_DIGITOS] = {false}; // Arreglo para registrar la presencia de los dígitos

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
            digitos_presentes[digito] = true; // Marcar el dígito como presente
            numero /= 10; // Eliminar el último dígito del número
        }
    }

    cout << "Numeros del 0 al 9 que aparecieron:" << endl;
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
        if (digitos_presentes[i]) 
        {
            cout << "El digito " << i << " esta presente." << endl;
        }
        else
        {
            cout << "El digito " << i << " no esta presente." << endl;
        }
    }

    return 0;
}