/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo // Crear nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarAlInicio(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    nuevoNodo -> siguiente = inicio; // Que el nuevo nodo apunte al puntero inicio
    inicio = nuevoNodo; // Que el nuevo nodo sea el inicio, osea el primer elemento
    return inicio;
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
    inicio = nullptr; // Declarar lista vacía

    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    while(numero != 0)
    {
        inicio = insertarAlInicio(inicio, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }
    
    mostrarLista(inicio);
    return 0;
}