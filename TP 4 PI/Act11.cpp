/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica,
y retorne el primer número impar encontrado en el arreglo. En caso de no haber números impares, debe retornar 0.
*/

#include <iostream>
#include <string>
using namespace std;

int primerImpar(int arreglo[], int dl, int indice = 0)
{
    // Caso base
    if (indice >= dl) // Si el indice recorrió todo el arreglo sin encontrar un impar entonces retorna 0
    {
        return 0;
    }
    // Caso recursivo
    if (arreglo[indice] % 2 != 0) // Si se encontró un número impar, se devuelve
    {
        return arreglo[indice]; 
    }
    else
    {
        return primerImpar(arreglo, dl, indice + 1);
    }
}

int main()
{
    int dl;
    cout << "Ingrese la dimension logica del arreglo: ";
    cin >> dl;

    int arreglo[dl];
    cout << "Ingrese los elementos del arreglo: " << endl;
    for (int i = 0; i < dl; ++i)
    {
        cin >> arreglo[i];
    }

    int indice = 0;

    int resultado = primerImpar(arreglo, dl, 0);
    if(resultado != 0)
    {
        cout << "El primer numero impar es: " << resultado;
    }
    else
    {
        cout << "No se encontraron numeros impares";
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo dl = 3 y arreglo = 2 1 4
1. Como el indice es menor a la dl entonces entra al caso recursivo
2. Agarra al primer elemento, es decir, 2, y lo divide por 2, como su resto es igual a 0 entonces no lo devuelve porque es par y entra al else para llamar recursivamente a la funcion para analizar el siguiente elemento
3. Agarra al segundo elemento, es decir, 1, y lo divide por 2, como su resto es distinto de 0, entonces lo devuelve porque es impar y entra al else para llamar recursivamente a la funcion para analizar el siguiente elemento 
4. Agarra al tercer elemento, es decir, 2, y lo divide por 2, como su resto es igual a 0 entonces no lo devuelve porque es par y entra al else para llamar recursivamente a la funcion para analizar el siguiente elemento
5. Como el indice es mayor a la dl retorna 0 porque ya recorrio todo el indice
6. Finalmente el primer numero impar encontrado es 1
*/