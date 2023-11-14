#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarAlFinal(Nodo* fin, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nodo para almacenar el valor
    nuevoNodo -> dato = numero; // El dato que va a contener el nuevo nodo es el que ingrese el usuario

    if (fin == nullptr) // Si la lista está vacía
    {
        nuevoNodo -> siguiente = nuevoNodo; // El nuevo nodo debe apuntarse a sí mismo
    }
    else // Si la lista no está vacía
    {
        nuevoNodo -> siguiente = fin -> siguiente; // El nuevo nodo va a apuntar al nodo que apunte el puntero fin
        fin -> siguiente = nuevoNodo; // // El puntero fin va a apuntar al nuevo nodo porque es el primer elemento
    }
    return nuevoNodo; // Retorna el ultimo numero insertado en la lista
}

void mostrarLista(Nodo* fin)
{
    cout << "Lista:" << endl;
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
        fin = insertarAlFinal(fin, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }
    
    mostrarLista(fin);

    return 0;
}