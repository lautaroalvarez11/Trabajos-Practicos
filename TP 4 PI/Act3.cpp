// Escribir una función recursiva que, dado un número entero, lo imprima en orden inverso.

#include <iostream>
#include <string>
using namespace std;

int invertir(int a)
{
    // Caso base
    if(a == 0)
    {
        return 0;
    }
    // Caso recursivo
    else
    {
        int b = a % 10; // b contiene el ultimo digito del numero a invertir
        cout << b; // Imprime el ultimo digito
        return invertir(a / 10); // Se llama a la funcion recursivamente con el numero sin el ultimo digito
    }
}

int main()
{
    int numero, numeroInvertido;
    cout << "Ingrese un numero a invertir: ";
    cin >> numero;

    cout << "El numero invertido es: ";
    numeroInvertido = invertir(numero);
    return 0;
}

/*
Como funciona este programa:
Ejemplo a = 150
1. a es distinto de 0 entonces entra al caso recursivo
2. Se declara una variable b que contiene el ultimo digito de a, es decir, 0
3. Se imprime el 0
4. Luego se llama a la funcion recursivamente pero esta vez a vale 15

1. a es distinto de 0 entonces entra al caso recursivo
2. b contiene el ultimo digito de a, es decir, 5
3. Se imprime el 5, es decir, se imprime 05
4. Luego se llama a la funcion recursivamente pero esta vez vale 1

1. a es distinto de 0 entonces entra al caso recursivo
2. b contiene el ultimo digito de a, es decir, 1
3. Se imprime el 1, es decir, se imprime 051
4. Luego se llama a la funcion recursivamente pero esta vez vale 0
5. Como a es igual a 0 entonces sale del caso recursivo y termina la funcion
*/