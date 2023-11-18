// Escribir una función recursiva que, dado un número entero, retorne la cantidad de dígitos que tiene

#include <iostream>
#include <string>
using namespace std;

int mostrarDigitos(int a)
{
    int contador = 0;
    // Caso base: Si el número es 0, retorna 0, indicando que no hay dígitos
    if(a == 0)
    {
        return 0;
    }
    // Caso recursivo
    else
    {
        a = a / 10; // Elimina el último dígito del número al dividirlo por 10
        contador++;
        return 1 + mostrarDigitos(a); // Retorna 1 más el resultado de llamar recursivamente la función con el número modificado
    }
}

int main()
{
    int numero, cantDigitos;
    cout << "Ingrese un numero: ";
    cin >> numero;

    cantDigitos = mostrarDigitos(numero);
    cout << "La cantidad de digitos del numero es: " << cantDigitos;
    return 0;
}

/*
Como funciona este programa:
Ejemplo a = 300
1. a es distinto de 0 entonces entra al caso recursivo
2. A a lo divide entre 10, es decir, le elimina el ultimo digito
3. Se incrementa el contador porque existio un digito a eliminar, es decir, a tiene por lo menos un digito
4. Llama recursivamente a la funcion pero ahora a vale 30

1. a es distinto de 0 entonces entra al caso recursivo
2. A a lo divide entre 10, es decir, le elimina el ultimo digito
3. Se incrementa el contador porque existio un digito a eliminar, es decir, a tiene por lo menos un digito
4. LLama recursivamente a la función pero ahora a vale 3

1. a es distinto de 0 entonces entra al caso recursivo
2. A a lo divide entre 10, es decir, le elimina el ultimo digito
3. Se incrementa el contador porque existio un digito a eliminar, es decir, a tiene por lo menos un digito
4. LLama recursivamente a la función pero ahora a vale 0
5. Como a es igual a 0 entonces sale de la funcion
*/