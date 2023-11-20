// Escribir una función recursiva que reciba una palabra y retorne true si es palíndromo, false si no lo es (diferenciando mayúsculas y minúsculas)

#include <iostream>
#include <string>
using namespace std;

bool palindromo(string palabra)
{
    // Caso base: si la longitud de la palabra es 0 o 1, es un palíndromo
    if (palabra.length() <= 1)
    {
        return true;
    }
    // Caso recursivo: 
    else
    {
        if(palabra[0] != palabra[palabra.length() - 1]) // Compara el primer y último carácter para ver si son distintos
        {
            return false; // Si los caracteres no coinciden, no es un palíndromo
        }
        else
        {
            // Llama recursivamente a la función con la subcadena excluyendo el primer y último carácter
            return palindromo(palabra.substr(1, palabra.length() - 2));
        }
    }
}

int main()
{
    string palabra;

    cout << "Ingrese una palabra: ";
    cin >> palabra;

    if (palindromo(palabra))
    {
        cout << "La palabra es un palindromo." << endl;
    }
    else
    {
        cout << "La palabra no es un palindromo." << endl;
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo "radar"
1. La longitud de "radar" es mayor a 1 entonces entra al caso recursivo
2. Compara el primer y ultimo caracter, como son iguales entra al else y llama recursivamente a la funcion pero esta vez sin el primer y ultimo caracter, es decir, palindromo("ada")
3. La longitud de "ada" es mayor a 1 entonces entra al caso recursivo
4. Compara el primer y ultimo caracter, como son iguales entra al else y llama recursivamente a la funcion pero esta vez sin el primer y ultimo caracter, es decir, palindromo("d")
5. Como la longitud de "d" es igual a 1 entonces entra al caso base y sale de la funcion
6. En todas las llamadas de recursion el primer y ultimo caracter son iguales, entonces "radar" es un palindromo
*/