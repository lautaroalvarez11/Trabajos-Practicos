/*
El rey de un reino está organizando festejos por su cumpleaños y desea ofrecer un banquete en
cada una de las ciudades principales de su reino: Tuwin, Forella, Doriath y Aerilon. Los banquetes durarán 3 días
en cada ciudad y se necesita contabilizar la cantidad de invitados que habrá cada día, para organizar todo.
a) Almacenar estos datos en una matriz, cargada por el usuario.
b) Informar cuántos invitados se esperan en total en cada ciudad (imprimiendo nombre de la ciudad y
cantidad de invitados en el total de días).
c) Desde la ciudad Aerilon informan que habrá que restar 50 invitados que ya no asistirán el primer día.
d) Dado el nombre de una ciudad ingresada por teclado, informar la cantidad de personas que asistirán en
cada uno de los tres días.
*/

#include <iostream>
#include <string>
using namespace std;

const int NUM_CIUDADES = 4;
const int DIAS_BANQUETE = 3;

void cargarInvitados(int invitados[NUM_CIUDADES][DIAS_BANQUETE], string ciudades[NUM_CIUDADES])
{
    for (int i = 0; i < NUM_CIUDADES; ++i)
    {
        cout << "Ingrese la cantidad de invitados para " << ciudades[i] << " durante 3 días:" << endl;
        for (int j = 0; j < DIAS_BANQUETE; ++j)
        {
            cout << "Día " << j + 1 << ": ";
            cin >> invitados[i][j];
        }
    }
}

void mostrarTotalInvitados(int invitados[NUM_CIUDADES][DIAS_BANQUETE], string ciudades[NUM_CIUDADES])
{
    cout << "Total de invitados por ciudad:" << endl;
    for (int i = 0; i < NUM_CIUDADES; ++i) {
        int totalInvitados = 0;
        for (int j = 0; j < DIAS_BANQUETE; ++j)
        {
            totalInvitados += invitados[i][j];
        }
        cout << ciudades[i] << ": " << totalInvitados << " invitados en total." << endl;
    }
}

void restarInvitadosAerilon(int invitados[NUM_CIUDADES][DIAS_BANQUETE], string ciudades[NUM_CIUDADES])
{
    for (int i = 0; i < NUM_CIUDADES; ++i)
    {
        if (ciudades[i] == "Aerilon")
        {
            invitados[i][0] -= 50;
            break;
        }
    }
}

void mostrarInvitadosPorDia(int invitados[NUM_CIUDADES][DIAS_BANQUETE], string ciudades[NUM_CIUDADES])
{
    string ciudadIngresada;
    cout << "Ingrese el nombre de una ciudad para ver la cantidad de invitados por día: ";
    cin >> ciudadIngresada;

    bool ciudadEncontrada = false;
    for (int i = 0; i < NUM_CIUDADES; ++i)
    {
        if (ciudades[i] == ciudadIngresada)
        {
            ciudadEncontrada = true;
            cout << "Cantidad de invitados en " << ciudadIngresada << " por día:" << endl;
            for (int j = 0; j < DIAS_BANQUETE; ++j)
            {
                cout << "Día " << j + 1 << ": " << invitados[i][j] << " invitados." << endl;
            }
            break;
        }
    }

    if (!ciudadEncontrada)
    {
        cout << "La ciudad ingresada no se encuentra en la lista." << endl;
    }
}

int main()
{
    string ciudades[NUM_CIUDADES] = {"Tuwin", "Forella", "Doriath", "Aerilon"};
    int invitados[NUM_CIUDADES][DIAS_BANQUETE] = {0};

    cargarInvitados(invitados, ciudades);
    mostrarTotalInvitados(invitados, ciudades);
    restarInvitadosAerilon(invitados, ciudades);
    mostrarInvitadosPorDia(invitados, ciudades);

    return 0;
}