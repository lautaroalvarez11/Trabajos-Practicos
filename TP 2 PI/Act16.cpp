#include <iostream>
#include <string>
using namespace std;

const int NUM_FILAS = 5;
const int ASIENTOS_POR_FILA = 10;

// Función para inicializar todos los asientos como libres
void inicializarAsientos(bool asientos[][ASIENTOS_POR_FILA])
{
    for (int fila = 0; fila < NUM_FILAS; ++fila)
    {
        for (int asiento = 0; asiento < ASIENTOS_POR_FILA; ++asiento)
        {
            asientos[fila][asiento] = false; // false indica asiento libre
        }
    }
}

// Función para mostrar el estado de los asientos
void mostrarEstadoAsientos(const bool asientos[][ASIENTOS_POR_FILA])
{
    cout << "Estado de los asientos:" << endl;
    for (int fila = 0; fila < NUM_FILAS; ++fila)
    {
        cout << "Fila " << fila << ": ";
        for (int asiento = 0; asiento < ASIENTOS_POR_FILA; ++asiento)
        {
            if (asientos[fila][asiento])
            {
                cout << "O "; // O indica asiento ocupado
            } else 
            {
                cout << "L "; // L indica asiento libre
            }
        }
        cout << endl;
    }
}

int main()
{
    bool asientos[NUM_FILAS][ASIENTOS_POR_FILA];
    inicializarAsientos(asientos);

    int totalEntradas = NUM_FILAS * ASIENTOS_POR_FILA;
    int entradasVendidas = 0;
    char opciones;
    char eleccion;

    cout << "Bienvenido al teatro" << endl;
    cout << "A. Reservar asientos." << endl;
    cout << "B. Salir del programa." << endl;
    cout << "Elija la opcion que desee:" << endl;
    cin >> opciones;

    switch(opciones)
    {
        case 'a':
        case 'A':
        {
            do
            {
                mostrarEstadoAsientos(asientos);

                int fila, asiento;
                cout << "Seleccione su lugar" << endl;
                cout << "Numero de fila: ";
                cin >> fila;
                cout << "Numero de asiento: ";
                cin >> asiento;

                if (fila < 0 || fila >= NUM_FILAS || asiento < 1 || asiento > ASIENTOS_POR_FILA)
                {
                    cout << "Asiento invalido. Por favor, elija un asiento valido." << endl;
                    continue; //Saltear el siguiente bloque y vuelve a mostrar el estado de los asientos
                }

                if (asientos[fila][asiento - 1])
                {
                    cout << "Este asiento ya esta ocupado. Por favor, elija otro si desea." << endl;
                } else
                {
                    asientos[fila][asiento - 1] = true;
                    cout << "Asiento vendido correctamente." << endl;
                    entradasVendidas++;
                }

                if (asientos[fila][asiento - 1] = true) 
                {
                    cout << "Desea reservar otro asiento? (S para si, cualquier otra tecla para salir): ";
                    cin >> eleccion;
                } else
                {
                    cout << "Todas las entradas han sido vendidas. El teatro esta lleno." << endl;
                    eleccion = 'N'; // Forzar la salida del bucle si ya no hay más asientos disponibles
                }
            } while (eleccion == 'S' || eleccion == 's' && entradasVendidas < totalEntradas);
        } 

        case 'b':
        case 'B':
        {
            break;
        }
    }

    return 0;
}