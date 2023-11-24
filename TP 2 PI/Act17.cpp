/*
Se debe lanzar una encuesta para lanzar un nuevo producto al mercado en 20 localidades de la provincia de
Buenos Aires. El producto se presenta en 5 formas diferentes, dándose a elegir a cada encuestado solo una de
ellas. Además de las 5 opciones se incluye la posibilidad de elegir ninguna.
Se pide realizar un programa que permite resolver las siguientes opciones:
a. Informar la presentación más elegida por localidad.
b. Informar la localidad con mayor porcentaje de encuestados que no eligieron ninguna de las
presentaciones.
*/

#include <iostream>
#include <string>
using namespace std;


const int NUM_LOCALIDADES = 20;
const int NUM_PRESENTACIONES = 6; // 5 formas diferentes + ninguna

void ingresarEncuestas(int encuestas[NUM_LOCALIDADES][NUM_PRESENTACIONES])
{
    cout << "Ingrese los datos de las encuestas:" << endl;

    for (int i = 0; i < NUM_LOCALIDADES; ++i)
    {
        cout << "Localidad " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_PRESENTACIONES; ++j)
        {
            cout << "Cantidad de votos para presentación " << j + 1 << ": ";
            cin >> encuestas[i][j];
        }
    }
}

void presentacionMasElegidaPorLocalidad(int encuestas[NUM_LOCALIDADES][NUM_PRESENTACIONES])
{
    cout << "Presentación más elegida por localidad:" << endl;
    for (int i = 0; i < NUM_LOCALIDADES; ++i)
    {
        int maximo = 0;
        int presentacionMasElegida = 0;
        for (int j = 0; j < NUM_PRESENTACIONES; ++j)
        {
            if (encuestas[i][j] > maximo)
            {
                maximo = encuestas[i][j];
                presentacionMasElegida = j;
            }
        }
        if (presentacionMasElegida == 5)
        {
            cout << "Localidad " << i + 1 << ": Ninguna (" << maximo << " votos)" << endl;
        }
        else
        {
            cout << "Localidad " << i + 1 << ": Presentación " << presentacionMasElegida + 1 << " (" << maximo << " votos)" << endl;
        }
    }
}

void localidadMayorPorcentajeNinguna(int encuestas[NUM_LOCALIDADES][NUM_PRESENTACIONES])
{
    int localidadMayorPorcentajeNinguna = 0;
    double porcentajeMayor = 0.0;

    for (int i = 0; i < NUM_LOCALIDADES; ++i)
    {
        double porcentajeNinguna = (double)encuestas[i][5] / 100.0; // Supongamos que se encuestaron 100 personas por localidad
        if (porcentajeNinguna > porcentajeMayor)
        {
            porcentajeMayor = porcentajeNinguna;
            localidadMayorPorcentajeNinguna = i + 1;
        }
    }

    cout << "Localidad con mayor porcentaje de encuestados que no eligieron ninguna presentación: " << endl;
    cout << "Localidad " << localidadMayorPorcentajeNinguna << " (" << (porcentajeMayor * 100) << "%)" << endl;
}

int main()
{
    int encuestas[NUM_LOCALIDADES][NUM_PRESENTACIONES];

    ingresarEncuestas(encuestas);
    presentacionMasElegidaPorLocalidad(encuestas);
    localidadMayorPorcentajeNinguna(encuestas);

    return 0;
}