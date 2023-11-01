/*
Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso, insertando al
final de la lista y cortando la carga cuando se inserte como nombre "x", ya sea en mayúscula o en minúscula (el
cual no debe insertarse en la lista).
A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
Por último, eliminar al alumno de la lista que el usuario desee (se asume que no se han almacenado nombres
repetidos).
*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    string dato;
    Nodo* siguiente;
};

Nodo* insertarAlumnos(Nodo* inicio, string alumno)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo -> dato = alumno;
    nuevoNodo -> siguiente = nullptr;

    if(inicio == nullptr)
    {
        inicio = nuevoNodo;
    } else
    {
        Nodo* auxiliar = inicio;
        while(auxiliar -> siguiente != nullptr)
        {
            auxiliar = auxiliar -> siguiente;
        }
        auxiliar -> siguiente = nuevoNodo;
    }
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

bool encontrarAlumno(Nodo* inicio, string nombreBuscado)
{
    for(Nodo* auxiliar = inicio; auxiliar != nullptr; auxiliar = auxiliar -> siguiente)
    {
        if(auxiliar -> dato == nombreBuscado)
        {
            return true;
        }
        return false;
    }
}

Nodo* eliminarAlumno(Nodo* inicio, string nombreBorrar)
{
    if(inicio != nullptr)
    {
        Nodo* auxiliar = inicio;
        if(inicio -> dato == nombreBorrar)
        {
            inicio = inicio -> siguiente;
            delete auxiliar;
        }
        else
        {
            while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato != nombreBorrar)
            {
                auxiliar = auxiliar -> siguiente;
            }
            if(auxiliar -> siguiente -> dato == nombreBorrar)
            {
                Nodo * aEliminar = auxiliar -> siguiente;
                auxiliar -> siguiente = aEliminar -> siguiente;
                delete aEliminar;
            }
        }
    }
    return inicio;
}

int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    string alumno;

    cout << "Ingrese nombre y apellido del alumno (x para finalizar): ";
    getline(cin>>ws, alumno);

    while(alumno != "x" && alumno != "X")
    {
        inicio = insertarAlumnos(inicio, alumno);
        cout << "Ingrese otro alumno (x para finalizar): ";
        getline(cin>>ws, alumno);
    }

    int opcion;
    cout << "MENÚ: " << endl;
    cout << "1. Mostrar lista de alumnos." << endl;
    cout << "2. Buscar alumnos en la lista." << endl;
    cout << "3: Eliminar alumnos." << endl;
    cout << "4. Salir." << endl;
    cin >> opcion;

    switch(opcion)
    {
        case 1:
            mostrarLista(inicio);
            cout << endl;
            break;
        
        case 2:
            cout << "Ingrese el nombre de un alumno para verificar si esta en la lista o no: ";
            getline(cin>>ws, alumno);

            if (encontrarAlumno(inicio, alumno) == true)
            {
                cout << "El alumno pertenece a la lista" << endl;
            } else
            {
                cout << "El alumno no pertenece a la lista" << endl;
            }
            break;
        
        case 3:
            cout << "Ingrese un nombre de usuario a eliminar ('Josefina Ortega'): ";
            getline(cin>>ws, alumno);
            inicio = eliminarAlumno(inicio, alumno);
            cout << endl;
            mostrarLista(inicio);
            cout << endl;
            main();
            break;
        
        case 4:
            break;
        
        default:
            cout << "Opción no válida." << endl;
            break;
    }
    
    return 0;
}