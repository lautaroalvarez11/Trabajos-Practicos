/*
Escribir una función recursiva que, dada una lista de enteros, retorne la suma de todos sus elementos.
En caso de que la lista esté vacía, deberá retornar 0.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

int sumaLista(Nodo* nodo)
{
    // Caso base
    if(nodo == nullptr)
    {
        return 0;
    }
    // Caso recursivo
    else
    {
        return nodo -> dato + sumaLista(nodo -> siguiente);
    }
}

Nodo* insertarAlInicio(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    nuevoNodo -> siguiente = inicio; // Que el nuevo nodo apunte al puntero inicio
    inicio = nuevoNodo; // Que el nuevo nodo sea el inicio, osea el primer elemento
    return inicio;
}

int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    while(numero != 0)
    {
        inicio = insertarAlInicio(inicio, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }

    int resultado = sumaLista(inicio);
    cout << "La suma de los elementos de la lista es: " << resultado;

    return 0;
}

/*
Como funciona este programa:
Ejemplo {1,2,3}
1. Como la lista tiene elementos, es decir el nodo apunta a algo distinto a nullptr, entonces entra al caso recursivo
2. Agarra el dato del primer nodo y le suma el dato del siguiente nodo llamando recursivamente a la funcion
3. Agarra el dato del segundo nodo y le suma el dato del siguiente nodo llamando recursivamente a la funcion
4. Agarra el dato del tercer nodo y le suma el dato del siguiente nodo llamando recursivamente a la funcion
5. Como el tercer nodo apunta a nullptr retorna 0 y termina la funcion
6. Finalmente la suma de los 3 nodos da como resultado 6
*/