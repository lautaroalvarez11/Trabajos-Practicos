/*
Analizar el siguiente código e indicar cómo queda la lista luego de la ejecución
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* e(Nodo* inicio, int k)
{
    if (k < 1)
    {
        return inicio;
    }

    if (inicio == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
    Nodo *auxiliar = inicio -> siguiente;
    delete(inicio);
    return auxiliar;
    }

    else
    {
    inicio -> siguiente = e(inicio -> siguiente, k - 1);
    return inicio;
    }
}

Nodo* a(Nodo* inicio, int d)
{
    if (inicio == nullptr)
    {
        Nodo* nuevo = new Nodo;
        nuevo -> dato = d;
        nuevo -> siguiente = nullptr;
        return nuevo;
    }

    else
    {
        inicio -> siguiente = a(inicio -> siguiente, d);
    }

    return inicio;
}

int main()
{
    Nodo* inicio = nullptr;
    inicio = a(inicio, 9);
    inicio = a(inicio, 6);
    inicio = a(inicio, 4);
    inicio = a(inicio, 7);
    inicio = e(inicio, 2);
}

/*
Como funciona este programa:
1. Se definen dos funciones e y a. La función e elimina el nodo en la posición k (si existe), y la función a añade un nuevo nodo con el dato d al final de la lista
2. En la función main(), se crea la lista enlazada inicio y se agregan cuatro nodos con los datos 9, 6, 4 y 7, respectivamente, usando la función a. Luego, se llama a la función e para eliminar el nodo en la posición 2 de la lista inicio
3. Se agrega el nodo con dato 9 al principio de la lista
   Se agrega el nodo con dato 6 después del nodo 9
   Se agrega el nodo con dato 4 después del nodo 6
   Se agrega el nodo con dato 7 después del nodo 4
4. Se llama a la función e(inicio, 2), que elimina el nodo en la posición 2 (contando desde 1) de la lista inicio. En este caso, se elimina el nodo con dato 6
    Después de la eliminación, la lista inicio queda con los nodos: 9 -> 4 -> 7
5. Luego de todas las operaciones, la lista inicio queda con los nodos con datos 9, 4 y 7 en ese orden
*/