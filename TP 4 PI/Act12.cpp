/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica,
y retorne la suma de los elementos pares almacenados en el arreglo.En caso de no haber números pares, debe retornar 0.
*/

#include <iostream>
#include <string>
using namespace std;

int sumarPares(int arreglo[], int dl, int indice = 0)
{
    // Caso base
    if (indice >= dl) // Si el indice recorrió todo el arreglo sin encontrar un par entonces retorna 0
    {
        return 0;
    }
    // Caso recursivo
    if(arreglo[indice] % 2 == 0)
    {
        return arreglo[indice] + sumarPares(arreglo, dl, indice + 1);
    }
    else
    {
        return sumarPares(arreglo, dl, indice + 1);
    }
}

int main()
{
    int dl;
    cout << "Ingrese la dl del arreglo: ";
    cin >> dl;

    int arreglo[dl];
    cout << "Ingrese los elementos del arreglo: " << endl;
    for (int i = 0; i < dl; ++i)
    {
        cin >> arreglo[i];
    }

    int indice = 0;

    int resultado = sumarPares(arreglo, dl, 0);
    if(resultado != 0)
    {
        cout << "La suma de los pares es: " << resultado;
    }
    else
    {
        cout << "No se encontraron numeros pares";
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo dl = 3 y arreglo = 1 2 4
1. Como el indice es menor a la dl entonces entra al caso recursivo
2. Agarra al primer elemento y lo divide por 2, es decir, 1, como su resto es distinto de 0 entonces entra al else llamando recursivamente a la funcion para analizar el siguiente elemento
3. Agarra el segundo elemento y lo divide por 2, es decir, 2, como su resto es igual a 0 entonces entra al if llamando recursivamente a la funcion para ver si el siguiente elemento es par para poder sumarlo
3. Agarra el tercer elemento y lo divide por 2, es decir, 4, como su resto es igual a 0 entonces entra al if y se le suma el elemento anterior que tambien era par
4. Como el indice es mayor a la dl retorna 0 porque ya recorrio todo el arreglo
5. Finalmente los numeros pares del arreglo son 2 y 4 que sumados dan 6
*/