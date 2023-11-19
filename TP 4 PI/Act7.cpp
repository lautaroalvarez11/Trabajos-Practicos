// Escribir una función recursiva para calcular la potencia de un número. La función recibirá como parámetros al número y un exponente (ambos enteros positivos), y retornará la potencia

#include <iostream>
#include <string>
using namespace std;

int potencia(int numero, int exponente)
{
    // Caso base
    if(numero == 0)
    {
        return 0;
    }
    if (exponente == 0)
    {
        return 1;
    }
    
    // Caso recursivo
    else
    {
        return numero * potencia(numero, exponente - 1);
    }
}

int main()
{
    int numero, exponente, resultado;
    
    cout << "Ingrese un numero: ";
    cin >> numero;

    cout << "Ingrese un exponente: ";
    cin >> exponente;

    resultado = potencia(numero, exponente);
    cout << "El numero y su exponente da como resultado: " << resultado;


    return 0;
}

/*
Como funciona este programa:
Ejemplo numero = 2 y exponente = 3
1. Como numero y exponente son distintos de 0 entonces entra al caso recursivo
2. Se multiplica el numero, es decir, 2 y se llama recursivamente a potencia(numero, exponente - 1), es decir, potencia(2, 2)
3. Dentro de la siguiente llamada recursiva, exponente es 2, por lo que se multiplica nuevamente a 2 y se llama a potencias(2, 1)
4. Dentro de la siguiente llamada recursiva, exponente es 1, por lo que se multiplica nuevamente a 2 y se llama a potencias(2, 0)
5. Dentro de la siguiente llamada recursiva, exponente es 0, entonces sale del caso recursivo
6. Luego se multiplican todos los valores de numero almacenados en cada llamada recursiva (2*2*2) = 8
*/