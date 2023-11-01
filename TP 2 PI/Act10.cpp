#include <iostream>
#include <string>
using namespace std;

const int maxSocios = 1000;
int socios[maxSocios]; // Arreglo
int numeroDeSocios = 0;

void agregarSocio(int dni)
{
    if (numeroDeSocios < maxSocios)
    {
        socios[numeroDeSocios] = dni;
        numeroDeSocios++;
        cout << "DNI ingresado correctamente." << endl;
    } else
    {
        cout << "El sistema tiene el máximo de socios permitidos.";
    }
}



bool buscarSocio(int dni)
{
    for(int i = 0; i < numeroDeSocios; i++)
    {
        if(socios[i] == dni)
        {
            cout << "Cuota al dia." << endl;
            return true;
        }
    }
    cout << "Socio en deuda." << endl;
    return false;
}



void eliminarSocio(int dni)
{
    for(int i = 0; i < numeroDeSocios; i++)
    {
        if(socios[i] == dni)
        {
            for(int j = i; j < numeroDeSocios - 1; j++)
            {
                socios[j] = socios[j+1];
            }
            numeroDeSocios--;
            cout << "DNI eliminado correctamente." << endl;
            return;
        }
    }
    cout << "El DNI no se encontro en el sistema." << endl;
}



void mostrarSocios()
{
    cout << "Lista de socios:" << endl;
    for(int i = 0; i < numeroDeSocios; i++)
    {
        cout << socios[i] << endl;
    }
}



int main()
{
    char opciones;

    cout << "Bienvenido al sistema" << endl;

    cout << "A. Agregar un DNI de socio que pago." << endl;
    cout << "B. Verificar estado de cuota." << endl;
    cout << "C. Eliminar un DNI del sistema." << endl;
    cout << "D. Mostrar todos los socios." << endl;
    cout << "E. Salir del programa." << endl;
    
    cout << "Elija una opcion: " << endl;
    cin >> opciones;
    
    switch(opciones)
    {
        case 'a':
        case 'A':
        {
            int dni;
            cout << "Ingrese el DNI del socio que pago: ";
            cin >> dni;
            
            agregarSocio(dni);
            main();
        }

        case 'b':
        case 'B':
        {
            int dni;
            cout << "Ingrese el DNI a buscar para verificar estado de cuota: ";
            cin >> dni;
            
            buscarSocio(dni);
            main();
        }

        case 'c':
        case 'C':
        {
            int dni;
            cout << "Ingrese el DNI a eliminar: ";
            cin >> dni;
            
            eliminarSocio(dni);
            main();
        }

        case 'd':
        case 'D':
        {
            mostrarSocios();
            break;
        }

        case 'e':
        case 'E':
        {
            break;
        }

        default:
        cout << "Ingrese una opcion valida." << endl;
        main();
        
    }

    return 0;
}