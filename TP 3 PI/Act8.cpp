/*
Implementar una función que reciba dos parámetros: una lista enlazada simple de números enteros y un
número entero. La función debe eliminar todas las ocurrencias del número indicado en el segundo parámetro.
Retornar la cantidad de ocurrencias eliminadas. Nota: se debe pasar una sola vez por cada uno de los
elementos de la lista.
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
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato < nuevoNodo -> dato) // Si a lista no está vacía y el nuevo nodo no va al principio.
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor menor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el nuevo nodo.
        nuevoNodo -> siguiente = auxiliar -> siguiente; // El nuevo nodo apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevoNodo; // El anterior (auxiliar) apuntará al nuevo nodo;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nuevo nodo se insertó al inicio
}

int eliminarNumero(Nodo* inicio, int numeroABorrar)
{
    int contador = 0; // Inicializar un contador para saber cuántas ocurrencias se eliminan.
    Nodo* anterior = nullptr; // Inicializar un puntero anterior para ubicar el nodo anterior al nodo actual.
    Nodo* auxiliar = inicio; // Inicializar un puntero auxiliar que comienza en el inicio de la lista.

    while (auxiliar != nullptr) // Mientras el puntero auxiliar no llegue al final de la lista.
    {
        if (auxiliar -> dato == numeroABorrar) // Comprobar si el dato del nodo actual es igual al número que se quiere borrar.
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
    
    return contador; // Retornar la cantidad total de ocurrencias eliminadas.
}

int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    int numero;
    cout << "Ingrese un numero (0 para finalizar): ";
    cin >> numero;

    while(numero != 0)
    {
        inicio = insertarOrdenado(inicio, numero);
        cout << "Ingrese otro numero (0 para finalizar): ";
        cin >> numero;
    }

    int opcion;
    cout << "Elija una opción:" << endl;
    cout << "1. Eliminar ocurrencias de un número." << endl;
    cout << "2. Salir" << endl;
    cin >> opcion;

    switch(opcion)
    {
        case 1:
        {  
            cout << "Ingrese el numero a eliminar: ";
            cin >> numero;

            int contador = eliminarNumero(inicio, numero);
            cout << "La cantidad de ocurrencias eliminadas es: " << contador;
            break;
        }
        
        case 2:
        {
            break;
        }
    }
    return 0;
}