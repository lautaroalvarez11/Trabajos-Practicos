/*
Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo, el
cual no debe ser procesado. Los números deben ser almacenados en una lista enlazada simple. Se solicita:

A. Leer de teclado un número e informar si existe en la lista.
B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.
C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes.
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

bool buscarNumero(Nodo* inicio, int numeroABuscar)
{
    for(Nodo* auxiliar = inicio; auxiliar != nullptr; auxiliar = auxiliar -> siguiente)
    {
        if(auxiliar -> dato == numeroABuscar)
        {
            return true;
        }
        return false;
    }
}

int contarOcurrencias(Nodo* inicio, int numeroABuscar)
{
    int contador = 0; // Inicio un contador en 0
    Nodo* auxiliar = inicio; // Crear un nodo auxiliar para no perder el inicio

    while (auxiliar != nullptr) // Mientras la lista no esté vacía
    {
        if (auxiliar -> dato == numeroABuscar) // Si el dato del nodo en el que estoy es igual al numero que se quiere buscar en la lista
        {
            contador++; // Se incrementa el contador
        }
        auxiliar = auxiliar -> siguiente; // Paso al otro nodo
    }
    return contador; // Retorna el total de ocurrencias en la lista
}

Nodo* separarParImpar(Nodo* inicio, Nodo* &listaPar, Nodo* &listaImpar)
{
    for(Nodo* auxiliar = inicio; auxiliar != nullptr; auxiliar = auxiliar -> siguiente) // Recorre la lista mientras no esté vacía
    {
        if(auxiliar -> dato % 2 == 0) // Verifica si el dato del nodo en el que estoy es par
        {
            listaPar = insertarOrdenado(listaPar, auxiliar -> dato); // Usa la función de la lista principal pero almacenando los numeros pares en una lista aparte
        }
        else
        {
            listaImpar = insertarOrdenado(listaImpar, auxiliar -> dato); // Usa la función de la lista principal pero almacenando los numeros impares en una lista aparte
        }
    }

    cout << "Lista par: ";
    for(Nodo* temporal = listaPar; temporal != nullptr; temporal = temporal -> siguiente) // Recorre la lista mientras no esté vacía
    {
        cout << temporal -> dato << " "; // Muestra todos los numeros pares
    }
    cout << endl;

    cout << "Lista impar: ";
    for(Nodo* temporal = listaImpar; temporal != nullptr; temporal = temporal -> siguiente) // Recorre la lista mientras no esté vacía
    {
        cout << temporal -> dato << " "; // Muestra todos los numeros impares
    }
    return inicio; // Retorna el inicio de las listas para no perderlo por si se modificó
}


int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    Nodo* listaPar = new Nodo;
    listaPar = nullptr;

    Nodo* listaImpar = new Nodo;
    listaImpar = nullptr;

    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    while(numero > 0)
    {
        inicio = insertarOrdenado(inicio, numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }

    int opcion;

    cout << "1. Informar si un numero existe en la lista" << endl;
    cout << "2. Informar la cantidad de ocurrencias de un numero en la lista" << endl;
    cout << "3. Separar los numeros de la lista en par e impar" << endl;
    cout << "4. Salir" << endl;;
    cin >> opcion;

    switch(opcion)
    {
        case 1:
        {   
            cout << "Ingrese un numero para verificar si existe en la lista: ";
            cin >> numero;

            if(buscarNumero(inicio, numero) == true)
            {
                cout << "El numero se encuentra en la lista." << endl;
            }
            else
            {
                cout << "El numero no se encuentra en la lista" << endl;
            }
            break;
        }
        
        case 2:
        {
            cout << "Ingrese un numero para verificar si existe en la lista: ";
            cin >> numero;

            if(buscarNumero(inicio, numero) == true)
            {
                int cantidad = contarOcurrencias(inicio, numero);
                cout << "El número " << numero << " aparece " << cantidad << " veces en la lista." << endl;
            }
            else
            {
                cout << "El numero no tiene ocurrencias en la lista";
            }
            break;
        }
        
        case 3:
        {
            separarParImpar(inicio, listaPar, listaImpar);
            break;
        }

        case 4:
        {
            break;
        }

        default:
        {
            cout << "Opcion no válida.";
            main();
            break;
        }
    }

    return 0;
}