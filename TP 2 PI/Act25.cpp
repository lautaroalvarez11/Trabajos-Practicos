/*
Implementar un sistema que permita administrar datos de clientes de un comercio para enviarles promociones.
De cada cliente se tiene: nombre y apellido, DNI, e-mail, fecha de cumpleaños en formato DDMM, monto total
de compras en el último año:
a) Realizar el módulo de carga. La misma finaliza con el nombre "z". Los clientes deben almacenarse
ordenados por número de DNI.
b) Informar cuántos clientes cumplen años en cada uno de los 12 meses del año. Utilizar un arreglo
auxiliar para contabilizarlos.
c) Informar el nombre del cliente con el mayor monto de compras.
*/

#include <iostream>
#include <string>
using namespace std;

struct Comercio
{
    string NombreApellido;
    long DNI;
    string Email;
    string Cumpleanios;
    int ComprasUltimoAnio;
};

struct Fecha
{
    int fechaAAAAMMDD;
    
};

// Función para cambiar el formato de fecha AAAAMMDD a DD/MM/AAAA
string cambiarFormatoFecha(const string &fechaAAAAMMDD) {
    if (fechaAAAAMMDD.size() != 8) {
        return "Formato de fecha inválido";
    }

    string anio = fechaAAAAMMDD.substr(0, 4);
    string mes = fechaAAAAMMDD.substr(4, 2);
    string dia = fechaAAAAMMDD.substr(6, 2);

    return dia + "/" + mes + "/" + anio;
}

const int MAX_CLIENTES = 1000;
int ClientesActuales = 0;

void CargarDatos(Comercio clientes[MAX_CLIENTES])
{
    while (ClientesActuales < MAX_CLIENTES)
    {
        cout << "Ingrese nombre y apellido del cliente (z para finalizar): ";
        getline(cin, clientes[ClientesActuales].NombreApellido);

        if (clientes[ClientesActuales].NombreApellido == "z" || clientes[ClientesActuales].NombreApellido == "Z")
        {
            cout << "------------------------" << endl;
            break;
        }

        cout << "Ingrese DNI del cliente: ";
        cin >> clientes[ClientesActuales].DNI;
        cin.ignore(); // Ignorar el salto de línea pendiente en el buffer

        cout << "Ingrese Email del cliente: ";
         getline(cin, clientes[ClientesActuales].Email);

        cout << "Ingrese su cumpleanios sin espacios (formato AAAAMMDD): ";
        cin >> clientes[ClientesActuales].Cumpleanios;

        // Llamada a la función para cambiar el formato de fecha
        clientes[ClientesActuales].Cumpleanios = cambiarFormatoFecha(clientes[ClientesActuales].Cumpleanios);

        cout << "Ingrese el monto total de compras en el ultimo anio: ";
        cin >> clientes[ClientesActuales].ComprasUltimoAnio;

        cin.ignore();

        ClientesActuales++;
    }
}

void OrdenarClientes(Comercio clientes[MAX_CLIENTES], int ClientesActuales)
{
    for(int i = 0; i < ClientesActuales - 1; ++i)
    {
        for (int j = 0; j < ClientesActuales - i - 1; ++j)
        {
            if (clientes[j].DNI > clientes[j + 1].DNI)
            {
                // Intercambio de posiciones si el DNI actual es mayor al siguiente
                Comercio auxiliar = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = auxiliar;
            }
        }
    }
}

void ContarCumpleaniosPorMes(Comercio clientes[MAX_CLIENTES], int ClientesActuales)
{
    int cumpleaniosPorMes[12] = {0}; // Inicializamos el arreglo con 12 posiciones, una por cada mes

    for (int i = 0; i < ClientesActuales; ++i)
    {
        // Extraer el mes del cumpleaños
        string cumpleanios = clientes[i].Cumpleanios;
        int mes = stoi(cumpleanios.substr(4, 2)); // Se asume que el mes está en los caracteres 5 y 6 de la cadena
        // stoi es una función que toma una cadena que contiene un número y devuelve su equivalente en formato entero


        // Aumentar el contador del mes correspondiente
        if (mes >= 1 && mes <= 12)
        {
            cumpleaniosPorMes[mes - 1]++; // Restamos 1 para ajustar el índice del arreglo al mes
        }
    }

    // Mostrar la cantidad de cumpleaños por mes
    for (int i = 0; i < 12; ++i)
    {
        cout << "Clientes que cumplen anios en el mes " << i + 1 << ": " << cumpleaniosPorMes[i] << endl;
    }
    cout << "------------------------" << endl;
}

void MostrarClienteConMayoresCompras(Comercio clientes[MAX_CLIENTES], int ClientesActuales)
{
    int indiceClienteMayorCompra = 0; // Índice del cliente con la mayor cantidad de compras
    int mayorCantidadCompras = clientes[0].ComprasUltimoAnio; // Inicializamos con la primera cantidad de compras

    for(int i = 1; i < ClientesActuales; ++i)
    {
        if(clientes[i].ComprasUltimoAnio > mayorCantidadCompras)
        {
            mayorCantidadCompras = clientes[i].ComprasUltimoAnio;
            indiceClienteMayorCompra = i;
        }
    }

    // Mostrar el cliente con la mayor cantidad de compras
    cout << "El cliente con mayores compras en el ultimo anio es: " << clientes[indiceClienteMayorCompra].NombreApellido << endl;
    cout << "------------------------" << endl;
}


void MostrarListaClientes(Comercio clientes[MAX_CLIENTES], int ClientesActuales)
{
    cout << "Lista de clientes total:" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < ClientesActuales; ++i)
    {
        cout << "Cliente: " << i + 1 << ":" << endl;
        cout << "Nombre: " << clientes[i].NombreApellido << endl;
        cout << "DNI: " << clientes[i].DNI << endl;
        cout << "Email: " << clientes[i].Email << endl;
        cout << "Fecha de cumpleanios: " << clientes[i].Cumpleanios << endl;
        cout << "Total de compras en el ultimo anio: " << clientes[i].ComprasUltimoAnio << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    Comercio Clientes[MAX_CLIENTES];

    cout << "Bienvenido al sistema" << endl;

    int opciones;

    do
    {
        cout << "Continue en el sistema" << endl;
        cout << "1. Cargar un cliente al sistema" << endl;
        cout << "2. Ver cuantos clientes cumplen anios en cada uno de los 12 meses del anio" << endl;
        cout << "3. Ver el cliente con el mayor monto de compras" << endl;
        cout << "4. Mostrar lista total de clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;
        cin.ignore(); // Limpiar el buffer de nueva línea

        switch(opciones)
        {
            case 1:
            {
                CargarDatos(Clientes);
                OrdenarClientes(Clientes, ClientesActuales);
                break;
            }

            case 2:
            {
                ContarCumpleaniosPorMes(Clientes, ClientesActuales);
                break;
            }

            case 3:
            {
                MostrarClienteConMayoresCompras(Clientes, ClientesActuales);
                break;
            }

            case 4:
            {
                MostrarListaClientes(Clientes, ClientesActuales);
                break;
            }

            case 5:
            {
                cout << "Saliendo del programa." << endl;
                break;
            }

            default:
            {
                cout << "Ingrese una opcion correcta." << endl;
                break;
            }
        }
    } while (opciones != 5);
    
    return 0;
}