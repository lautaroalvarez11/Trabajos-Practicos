/*
Escribir una función recursiva que, dadas dos listas enlazadas simples,
retorne true si ambas listas tienen la misma longitud (cantidad de nodos), false en caso contrario.
Optimizar la función para que, en caso de que una lista sea más corta que la otra,
por ejemplo, la lista A tiene 10000 nodos y la lista B tiene 5 nodos,
no se continúe contabilizando la cantidad de nodos de la lista más larga.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

bool contarLongitudListas(Nodo* nodoA, Nodo* nodoB)
{
    // Casos base:
    // Si ambos nodos son nulos (fin de ambas listas), retorna true
    if (nodoA == nullptr && nodoB == nullptr) {
        return true;
    }
    // Si uno de los nodos es nulo (una lista es más corta), retorna false
    if (nodoA == nullptr || nodoB == nullptr) {
        return false;
    }
    // Caso recursivo
    else
    {
        return contarLongitudListas(nodoA->siguiente, nodoB->siguiente);
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
    Nodo* inicio1 = new Nodo;
    inicio1 = nullptr;

    int numerosLista1;

    cout << "Ingrese un numero de la lista 1: ";
    cin >> numerosLista1;

    while(numerosLista1 != 0)
    {
        inicio1 = insertarAlInicio(inicio1, numerosLista1);
        cout << "Ingrese otro numero de la lista 1 (0 para finalizar): ";
        cin >> numerosLista1;
    }

    Nodo* inicio2 = new Nodo;
    inicio2 = nullptr;

    int numerosLista2;

    cout << "Ingrese un numero de la lista 2: ";
    cin >> numerosLista2;

    while(numerosLista2 != 0)
    {
        inicio2 = insertarAlInicio(inicio2, numerosLista2);
        cout << "Ingrese otro numero de la lista 2 (0 para finalizar): ";
        cin >> numerosLista2;
    }

    bool mismaLongitud = contarLongitudListas(inicio1, inicio2);

    if(mismaLongitud)
    {
        cout << "Las listas tienen la misma longitud";
    }
    else
    {
        cout << "Las listas tienen diferentes longitudes";
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo listas de igual longitud con elementos
1. Se llama a la función contarLongitudListas con los inicios de ambas listas (inicio1 e inicio2)
2. En la primera llamada, se comprueba si ambos nodos (inicio1 e inicio2) son nulos. Como ninguno es nulo, se pasa al siguiente if
3. Se verifica si alguno de los nodos es nulo. En este caso, ninguno es nulo
4. Se avanza al siguiente nodo (nodoA -> siguiente y nodoB -> siguiente) en ambas listas y se llama recursivamente a contarLongitudListas
5. En la segunda llamada, se repiten los pasos 1-4 pero con los nodos siguientes de inicio1 e inicio2
6. Este proceso continúa hasta que se alcanza el final de ambas listas (donde ambos nodos son nullptr)
7. Cuando ambos nodos son nulos (fin de ambas listas), la función retorna true indicando que ambas listas tienen la misma longitud

Ejemplo listas de distintas longitudes con elementos, lista A con 4 nodos y lista B con 3 nodos
1. Se llama a la función contarLongitudListas con los inicios de ambas listas (inicio1 e inicio2)
2. En la primera llamada, se comprueba si ambos nodos (inicio1 e inicio2) son nulos. Como ninguno es nulo, se pasa al siguiente if
3. Se verifica si alguno de los nodos es nulo. En este caso, ninguno es nulo
4. Se avanza al siguiente nodo (nodoA -> siguiente y nodoB -> siguiente) en ambas listas y se llama recursivamente a contarLongitudListas
5. En la segunda llamada, se repiten los pasos 1-4 pero con los nodos siguientes de inicio1 e inicio2
6. El proceso continúa hasta que se alcanza el final de una de las listas, mientras que la otra lista aún tiene nodos
En este caso, la lista A tiene más nodos que lista B.
7. Cuando se alcanza el final de una lista (uno de los nodos es nullptr mientras el otro no lo es), la función retorna false, indicando que las listas tienen diferentes longitudes y no es necesario continuar verificando
*/