//Escribir una función recursiva que reciba un string y lo retorne con sus caracteres invertidos

#include <iostream>
#include <string>
using namespace std;

string invertirCadena(string cadena)
{
    // Caso base: Si la longitud de la cadena es menor o igual a 1, devuelve la cadena original
    if (cadena.length() <= 1)
    {
        return cadena;
    }
    // Caso recursivo
    else
    {
        char auxiliar = cadena[0]; // Almacena el primer carácter en una variable auxiliar
        cadena[0] = cadena[cadena.length() - 1]; // Asigna el último carácter al primer índice
        cadena[cadena.length() - 1] = auxiliar; // Asigna el carácter almacenado en auxiliar al último índice

        // Llama recursivamente a la función con la cadena sin el primer y último carácter, invirtiendo gradualmente la cadena desde los extremos hacia adentro
        return cadena[0] + invertirCadena(cadena.substr(1, cadena.length() - 2)) + cadena[cadena.length() - 1];
    }
}

int main()
{
    string cadena, cadenaInvertida;
    
    cout << "Ingrese una cadena: ";
    cin >> cadena;

    cadenaInvertida = invertirCadena(cadena);
    cout << "La cadena invertida es: " << cadenaInvertida;

    return 0;
}

/*
Como funciona este programa:
Ejemplo "hola"
1. La longitud de "hola" es mayor a 1 entonces entra al caso recursivo
2. Define una variable auxiliar donde almacena el primer caracter de "hola"
3. Luego asigna el ultimo caracter de "hola" al primer indice
4. Luego asigna el caracter almacenado en la variable auxiliar, es decir, h, en el ultimo indice, es decir, la cadena quedó "aolh"
5. Luego llama recursivamente a la funcion con la cadena sin el primer y ultimo caracter, es decir, sin a ni h

1. La longitud de "ol" es mayor a 1 entonces entra al caso recursivo
2. Define una variable auxiliar donde almacena el primer caracter de "ol"
3. Luego asigna el ultimo caracter de "ol" al primer indice
4. Luego asigna el caracter almacenado en la variable auxiliar, es decir, o, en el ultimo indice, es decir, la cadena quedó "lo"
5. Luego llama recursivamente a la función con la cadena sin el primer y ultimo caracter, es decir, sin o ni l
6. Como la longitud de la cadena es menor a 1 entonces entra al caso base y sale de la funcion;
7. A medida que las llamadas recursivas regresan, se van concatenando los caracteres invertidos, el resultado es "aloh"
*/