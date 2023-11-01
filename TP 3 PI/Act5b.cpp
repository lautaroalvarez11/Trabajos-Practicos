/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
b) Al final de la lista.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo // Crear nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarAlFinal(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    nuevoNodo -> siguiente = nullptr; // Que el nuevo nodo apunte al nullptr

    if(inicio == nullptr) // Si la lista está vacía (inicio apunta a nullptr), el nuevo nodo se convierte en el primer y único nodo.
    {
        inicio = nuevoNodo;
    }
    else
    {
        // Si la lista no está vacía. Hay encontrar el último nodo para enlazarlo al nuevo nodo.
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que comienza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr) // Se recorre la lista hasta encontrar el último nodo, que se caracteriza por apuntar a nullptr.
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista.
        }
        auxiliar -> siguiente = nuevoNodo; // Una vez que se encontró el último nodo, se enlaza al nuevo nodo para que sea el nuevo último nodo.
    }
    return inicio; // Se retorna el puntero al inicio de la lista, porque pudo haber cambiado si el nuevo nodo se convirtió en el último.
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
        inicio = insertarAlFinal(inicio, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }
    
    mostrarLista(inicio);
    
    return 0;
}