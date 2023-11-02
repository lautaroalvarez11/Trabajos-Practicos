/*
Implementar una función que reciba dos listas enlazadas simples con datos de tipo string ordenadas según el
alfabeto y retorne una tercera lista ordenada por el mismo criterio, conformada por todos los elementos de las
listas originales (merge).
Agregar las funciones auxiliares que sean necesarias para cumplir con este propósito.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    string dato;
    Nodo* siguiente;
};

Nodo* insertarOrdenado(Nodo* inicio, string palabra)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo -> dato = palabra;
    
    if(inicio == nullptr || nuevoNodo -> dato < inicio -> dato) // Si la lista está vacía o el nuevo nodo debe ir al principio porque es menor que el primer elemento.
    {
        nuevoNodo -> siguiente = inicio; // El nuevo nodo apunta al nodo actual en el inicio.
        inicio = nuevoNodo; // Se actualiza el inicio de la lista para que sea el nuevo nodo.
    } else
    {
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que empieza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato < nuevoNodo -> dato) // Si la lista no está vacía y el nuevo nodo no va al principio.
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor menor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el nuevo nodo.
        nuevoNodo -> siguiente = auxiliar -> siguiente; // El nuevo nodo apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevoNodo; // El anterior (auxiliar) apuntará al nuevo nodo;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nuevo nodo se insertó al inicio
}

Nodo* unirListas(Nodo* lista1, Nodo* lista2, Nodo* lista3)
{
    Nodo* auxiliar1 = lista1; // Se utiliza un puntero auxiliar1 para recorrer la lista1
    Nodo* auxiliar2 = lista2; // Se utiliza un puntero auxiliar2 para recorrer la lista2
    Nodo* auxiliar3 = lista3; // Se utiliza un puntero auxiliar3 para ir guardando los datos en la lista3

    while(auxiliar1 != nullptr) // Mientras la lista1 no se termine
    {
        auxiliar3 = insertarOrdenado(auxiliar3, auxiliar1 -> dato); // Insertar los datos de la lista1 en la lista3
        auxiliar1 = auxiliar1 -> siguiente; // Ir recorriendo los nodos
    }
    while(auxiliar2 != nullptr) // Mientras la lista2 no se termine
    {
        auxiliar3 = insertarOrdenado(auxiliar3, auxiliar2 -> dato); // Insertar los datos de la lista2 en la lista3
        auxiliar2 = auxiliar2 -> siguiente; // Ir recorriendo los nodos
    }
    return auxiliar3; // Retornar la lista3
}

void mostrarLista(Nodo* inicio)
{
    cout << "Lista: ";
    for (Nodo* auxiliar = inicio ; auxiliar != nullptr ; auxiliar = auxiliar -> siguiente)
    {
        cout << auxiliar -> dato << " ";
    }
    cout << endl;
}

int main()
{
    Nodo* inicio1 = new Nodo;
    inicio1 = nullptr;

    Nodo* inicio2 = new Nodo;
    inicio2 = nullptr;

    Nodo* inicio3 = new Nodo;
    inicio3 = nullptr;

    string palabra1;
    cout << "Ingrese una palabra para la primer lista: ";
    cin >> palabra1;

    while(palabra1 != "x")
    {
        inicio1 = insertarOrdenado(inicio1, palabra1);
        cout << "Ingrese otra palabra para la primer lista (x para finalizar): ";
        cin >> palabra1;
    }

    string palabra2;
    cout << "Ingrese una palabra para la segunda lista: ";
    cin >> palabra2;

    while(palabra2 != "x")
    {
        inicio2 = insertarOrdenado(inicio2, palabra2);
        cout << "Ingrese otra palabra para la segunda lista (x para finalizar): ";
        cin >> palabra2;
    }

    mostrarLista(inicio1);
    mostrarLista(inicio2);
    cout << endl;
    
    inicio3 = unirListas(inicio1, inicio2, inicio3);
    cout << "Lista 3 " << endl;
    mostrarLista(inicio3); 
    
    return 0;
}