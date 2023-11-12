#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    string dato;
    Nodo* siguiente;
};

Nodo* insertarAlFinal(Nodo* fin, string charla)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nodo para almacenar el valor
    nuevoNodo -> dato = charla; // El dato que va a contener el nuevo nodo es el que ingrese el usuario

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

string modificarTitulo(string titulo)
{
    for (int i = 0; i < titulo.length(); i++) // Recorre cada letra del string con la funcion length
    {
        if (i == 0) // La primer letra
            titulo[i] = toupper(titulo[i]); // Convierte a mayuscula la primer letra               
        else                              
            titulo[i] = tolower(titulo[i]); // Convierte a minuscula el resto de letras
    }
    return titulo;
}

void buscarTitulo(Nodo* fin, string titulo)
{
    Nodo* auxiliar = fin -> siguiente;
    bool tituloEncontrado = false;

    if (fin -> siguiente != nullptr)
    {
        do
        {
            if(auxiliar -> dato == titulo)
            {
                tituloEncontrado = true;
            }
            auxiliar = auxiliar -> siguiente;
        } while (auxiliar != fin -> siguiente && tituloEncontrado == false);
        if (tituloEncontrado == true)
        {
            cout << "El titulo ingresado se encuentra en la lista" << endl;
        }
        else
        {
            cout << "El titulo ingresado no se encuentra en la lista" << endl;
        }
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
}

void mostrarLista(Nodo* fin)
{
    cout << "Lista:" << endl;
    if(fin != nullptr)
    {
        Nodo* auxiliar = fin -> siguiente;
        do
        {
            cout << auxiliar -> dato << " - ";
            auxiliar = auxiliar -> siguiente; 
        } while (auxiliar != fin -> siguiente);
    }
}

int main()
{
    Nodo* fin = new Nodo;
    fin = nullptr; // Declarar lista vacía

    int opcion;
    string tituloCharla;    

    cout << "MENU" << endl;
    cout << "1. Agregar titulo de charla" << endl;
    cout << "2. Buscar titulo de charla" << endl;
    cout << "3. Salir" << endl;
    cout << "Elija opcion: ";
    cin >> opcion;

    switch(opcion)
    {
        case 1:
        {
            cout << "Ingrese el titulo de una charla: ";
            cin.ignore();
            getline(cin, tituloCharla);

            while(tituloCharla != "x" && tituloCharla != "X")
            {
                tituloCharla = modificarTitulo(tituloCharla);
                fin = insertarAlFinal(fin, tituloCharla);
                cout << "Ingrese otro titulo de charla (x para finalizar): ";
                getline(cin, tituloCharla);
            }

            mostrarLista(fin);
            cout << endl;
            main();
            break;
        }

        case 2:
        {
            cout << "Ingrese el titulo de una charla a buscar: ";
            cin.ignore();
            getline(cin, tituloCharla);

            while(tituloCharla != "x" && tituloCharla != "X")
            {
                tituloCharla = modificarTitulo(tituloCharla);
                buscarTitulo(fin, tituloCharla);
                cout << "Ingrese el titulo de una charla a buscar (x para finalizar): ";
                getline(cin, tituloCharla);
            }
            break;
        }

        case 3:
        {
            break;
        }

        default:
        {
            cout << "Opcion no valida, ingrese nuevamente" << endl;
            main();
            break;
        }
    }

    return 0;
}