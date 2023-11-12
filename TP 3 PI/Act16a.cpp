#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarAlPrincipio(Nodo* fin, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nodo para almacenar el valor
    nuevoNodo -> dato = numero; // El dato que va a contener el nuevo nodo es el que ingrese el usuario

    if (fin == nullptr) // Si la lista esta vacía
    {
      nuevoNodo -> siguiente = nuevoNodo; // El nuevo nodo va a apuntarse a sí mismo, es decir va a ser el primer elemento
      fin = nuevoNodo; // El final es el inicio, es decir el nuevo nodo va a ser el primero y el ultimo
    }
    else // Si la lista no está vacía
    {
      nuevoNodo -> siguiente = fin -> siguiente; // El nuevo nodo va a apuntar al nodo que apunte el puntero fin
      fin -> siguiente = nuevoNodo; // Y el puntero fin va a apuntar al nuevo nodo porque es el primer elemento
    }

    return fin; // Retorna el puntero fin porque apunta al primer elemento de la lista
}

void mostrarLista(Nodo* fin)
{
    cout << "Lista: " << endl;
    if(fin != nullptr)
    {
        Nodo* auxiliar = fin -> siguiente;
        do
        {
            cout << auxiliar -> dato << " ";
            auxiliar = auxiliar -> siguiente; 
        } while (auxiliar != fin -> siguiente);
    }
}



int main()
{
    Nodo* fin = new Nodo;
    fin = nullptr; // Declarar lista vacía

    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    while(numero != 0)
    {
        fin = insertarAlPrincipio(fin, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }
    
    mostrarLista(fin);

    return 0;
}