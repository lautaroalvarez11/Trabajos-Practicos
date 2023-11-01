/*
Desarrollar un programa que realice las siguientes operaciones en listas enlazadas simples de números enteros:

A. Cargar una lista insertando los elementos ordenados en forma descendente. Finaliza luego de ingresar
el cero, que también se debe agregar a la lista.

B. Eliminar las ocurrencias de los números que son múltiplos de 3.

C. Imprimir la lista antes y después de la eliminación.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarOrdenadoDescendente(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo -> dato = numero;
    
    if(inicio == nullptr || nuevoNodo -> dato > inicio -> dato) // Si la lista está vacía o el nuevo nodo debe ir al principio porque es mayor al primer elemento.
    {
        nuevoNodo -> siguiente = inicio; // El nuevo nodo apunta al nodo actual en el inicio.
        inicio = nuevoNodo; // Se actualiza el inicio de la lista para que sea el nuevo nodo.
    }
    else
    {
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que empieza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato > nuevoNodo -> dato) // Si la lista no está vacía y el nuevo nodo no va al principio.
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor mayor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el nuevo nodo.
        nuevoNodo -> siguiente = auxiliar -> siguiente; // El nuevo nodo apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevoNodo; // El anterior (auxiliar) apuntará al nuevo nodo;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nuevo nodo se insertó al inicio
}

Nodo* eliminarMultiploDe3(Nodo* inicio)
{
    int contador = 0; // Inicializar un contador para saber cuántas ocurrencias se eliminan.
    Nodo* anterior = nullptr; // Inicializar un puntero anterior para ubicar el nodo anterior al nodo actual.
    Nodo* auxiliar = inicio; // Inicializar un puntero auxiliar que comienza en el inicio de la lista.

    while (auxiliar != nullptr) // Mientras el puntero auxiliar no llegue al final de la lista.
    {
        if (auxiliar -> dato % 3 == 0) // Comprobar si el dato del nodo actual es multiplo de 3.
        {
            contador++; // Incrementar el contador porque se encontró una ocurrencia del número a borrar.
            
            if (anterior == nullptr) // Comprobar si el nodo actual es el primer nodo de la lista.
            {
                inicio = auxiliar -> siguiente; // Actualizar el inicio de la lista para que sea el siguiente nodo.
                delete auxiliar; // Eliminar el nodo actual.
                auxiliar = inicio; // Mover el puntero auxiliar al nuevo inicio de la lista.
            }
            else
            {
                anterior -> siguiente = auxiliar -> siguiente; // Actualizar el puntero siguiente del nodo anterior para saltear el nodo actual.
                delete auxiliar; // Eliminar el nodo actual.
                auxiliar = anterior -> siguiente; // Mover el puntero auxiliar al siguiente nodo después del nodo actual.
            }
        }
        else
        {
            anterior = auxiliar; // Actualizar el puntero anterior para que apunte al nodo actual.
            auxiliar = auxiliar -> siguiente; // Mover el puntero auxiliar al siguiente nodo en la lista.
        }
    }
    
    return inicio; // Retornar el puntero al inicio de la lista porque se modificó al eliminar los múltiplos de 3.
}

void mostrarLista(Nodo* inicio)
{
    for(Nodo* temporal = inicio; temporal != nullptr; temporal = temporal -> siguiente)
    {
        cout << temporal -> dato << " ";
    }
}

int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    int numero = 0;

    do
    {
        cout << "Ingrese un numero: ";
        cin >> numero;
        inicio = insertarOrdenadoDescendente(inicio, numero);
    } while(numero != 0); // Usar el do while para que se pueda agregar el 0

    cout << "Lista antes de eliminar los multiplos de 3: ";
    mostrarLista(inicio);
    cout << endl;

    inicio = eliminarMultiploDe3(inicio);
    cout << "Lista despues de eliminar los multiplos de 3: ";
    mostrarLista(inicio);
    cout << endl;
    
    return 0;
}