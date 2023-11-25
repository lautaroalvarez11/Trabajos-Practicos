/*
Realizar un algoritmo que almacene información de, como máximo, 500 libros en un arreglo estático. Un libro
se define como un struct con los siguientes campos: titulo, autor, ISBN, editorial, cantidadHojas.
El algoritmo finaliza luego de cargar el libro "El hobbit", el cual debe procesarse o cuando ya no quede espacio en el arreglo
(lo que suceda primero). Finalmente, imprimir el arreglo resultante mostrando todos los datos de cada libro.
*/

#include <iostream>
#include <string>
using namespace std;

struct Libro
{
    string titulo;
    string autor;
    string ISBN;
    string editorial;
    int cantidadHojas;
};

int main()
{
    const int MAX_LIBROS = 500;
    Libro biblioteca[MAX_LIBROS];
    int numLibros = 0;

    cout << "Ingrese información de libros (o escriba 'El hobbit' para finalizar): " << endl;

    while (numLibros < MAX_LIBROS)
    {
        cout << "Libro numero: " << (numLibros + 1) << endl;

        cout << "Titulo: ";
        getline(cin, biblioteca[numLibros].titulo);

        if (biblioteca[numLibros].titulo == "El hobbit") 
        {
            cout << "------------------------" << endl;
            break; // Finalizar si se ingresa "El hobbit"
        }

        cout << "Autor: ";
        getline(cin, biblioteca[numLibros].autor);

        cout << "ISBN: ";
        getline(cin, biblioteca[numLibros].ISBN);

        cout << "Editorial: ";
        getline(cin, biblioteca[numLibros].editorial);

        cout << "Cantidad de Hojas: ";
        cin >> biblioteca[numLibros].cantidadHojas;
        cin.ignore(); // Limpiar el búfer del salto de línea

        numLibros++;
    }

    cout << "Listado de Libros:" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < numLibros; i++)
    {
        cout << "Libro numero: " << (i + 1) << endl;
        cout << "Titulo: " << biblioteca[i].titulo << endl;
        cout << "Autor: " << biblioteca[i].autor << endl;
        cout << "ISBN: " << biblioteca[i].ISBN << endl;
        cout << "Editorial: " << biblioteca[i].editorial << endl;
        cout << "Cantidad de Hojas: " << biblioteca[i].cantidadHojas << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}