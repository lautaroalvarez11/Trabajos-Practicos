/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarOrdenado(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo -> dato = numero;
    
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

void mostrarLista(Nodo* inicio)
{
    cout << "Lista: ";
    for(Nodo* temporal = inicio; temporal != nullptr; temporal = temporal -> siguiente)
    {
        cout << temporal -> dato << " ";
    }
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
        inicio = insertarOrdenado(inicio, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }
    
    mostrarLista(inicio);

    return 0;
}