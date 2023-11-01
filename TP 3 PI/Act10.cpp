/*
Cargar una lista enlazada simple con palabras ingresadas por el usuario, las cuales deben almacenarse en
minúsculas independientemente de cómo las ingrese. Luego, a partir de esa lista, generar una nueva lista con
las palabras que se encuentran repetidas. Finalmente, imprimir ambas listas.
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    string dato;
    Nodo* siguiente;
};

Nodo* insertarAlFinal(Nodo* inicio, string palabra)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = palabra; // Agregar numero al nodo
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

int contarOcurrencias(Nodo* inicio, string palabraABuscar)
{
    int contador = 0; // Inicio un contador en 0
    Nodo* auxiliar = inicio; // Crear un nodo auxiliar para no perder el inicio

    while (auxiliar != nullptr) // Mientras la lista no esté vacía
    {
        if (auxiliar -> dato == palabraABuscar) // Si el dato del nodo en el que estoy es igual a la palabra que se quiere buscar en la lista
        {
            contador++; // Se incrementa el contador
        }
        auxiliar = auxiliar -> siguiente; // Paso al otro nodo
    }
    return contador; // Retorna el total de ocurrencias en la lista
}

bool encontrarPalabra(Nodo* inicio, string palabra)
{
    for(Nodo* auxiliar = inicio; auxiliar != nullptr; auxiliar = auxiliar -> siguiente)
    {
        if(auxiliar -> dato == palabra)
        {
            return true;
        }
        return false;
    }
}

Nodo* ListaPalabrasRepetidas(Nodo* inicio, Nodo* palabrasRepetidas)
{
    Nodo* auxiliar1 = inicio; // Inicializar un puntero auxiliar1 para recorrer la lista original
    Nodo* auxiliar2 = inicio; // Inicializar un puntero auxiliar2 para ir comparando con el auxiliar1 para encontrar la palabra repetida
    Nodo* auxiliar3 = palabrasRepetidas; // Inicializar un puntero auxiliar3 para recorrer la lista de palabras repetidas

    while(auxiliar1 != nullptr) // Mientras la lista original no se termine
    {
        while(auxiliar2 != nullptr) // Para comparar con todos los nodos de la lista original
        {
            if(auxiliar1 -> dato == auxiliar2 -> dato && auxiliar1 != auxiliar2) // Si la palabras de auxiliar1 y auxiliar2 son iguales pero diferentes nodos
            {
                if(encontrarPalabra(palabrasRepetidas, auxiliar1 -> dato) == false) // Utiliza la función encontrarPalabra para verificar si la palabra no existe en la lista de palabras repetidas
                {
                    palabrasRepetidas = insertarAlFinal(palabrasRepetidas, auxiliar1 -> dato); // Se almacena la palabra en la lista de palabras repetidas
                }
            }
            auxiliar2 = auxiliar2 -> siguiente; // Avanza al siguiente nodo de la lista original
        }
        auxiliar1 = auxiliar1 -> siguiente; // Avanza al siguiente nodo de la lista original
        auxiliar2 = inicio; // Volver a inicializar el puntero de auxiliar2 al inicio de la lista original
    }
    return palabrasRepetidas; // Retorna la lista de palabras repetidas
}



int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    Nodo* palabrasRepetidas = new Nodo;
    palabrasRepetidas = nullptr;

    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    while(palabra != "x")
    {
        for (int i = 0 ; i < palabra.length() ; i++) // Recorrer cada letra de una palabra
        {
            palabra[i] = tolower(palabra[i]); // Pasar a minuscula todas las letras
        }
        inicio = insertarAlFinal(inicio, palabra);
        cout << "Ingrese otra palabra (x para finalizar): ";
        cin >> palabra;
    }

    palabrasRepetidas = ListaPalabrasRepetidas(inicio, palabrasRepetidas);
    cout << "Lista de palabras repetidas: ";

    while(palabrasRepetidas != nullptr)
    {
        cout << palabrasRepetidas -> dato << " ";
        palabrasRepetidas = palabrasRepetidas->siguiente;
    }

    return 0;
}