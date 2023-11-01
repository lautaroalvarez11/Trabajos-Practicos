#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
    string Nombre;
    float calificaciones[3];
};

string AprobadoDesaprobado(float calificaciones[], int numTrimestres)
{
    for (int i = 0; i < numTrimestres; i++)
    {
        if (calificaciones[i] < 5.0)
        {
            return "NO APTO";
        }
    }
    return "APTO";
}

int main()
{
    const int MAX_ALUMNOS = 5000;
    Alumno escuela[MAX_ALUMNOS];
    int num_alumnos;

    cout << "Ingrese el numero de alumnos a calificar: ";
    cin >> num_alumnos;

    if (num_alumnos <= MAX_ALUMNOS && num_alumnos > 0)
    {
        cin.ignore(); // Limpiar el búfer de entrada

        for (int i = 0; i < num_alumnos; i++)
        {
            cout << "Datos del Alumno: " << (i + 1) << endl;
            cout << "Nombre: ";
            getline(cin, escuela[i].Nombre);

            for (int j = 0; j < 3; j++)
            {
                cout << "Calificacion Trimestre: " << (j + 1);
                cin >> escuela[i].calificaciones[j];
            }

            cin.ignore(); // Limpiar el búfer de entrada

            cout << "Estado: " << AprobadoDesaprobado(escuela[i].calificaciones, 3) << endl;
            cout << "-----------------------------------" << endl;
        }

        // Imprimir el listado de nombres de alumnos
        cout << "Listado de Nombres de Alumnos:" << endl;
        for (int i = 0; i < num_alumnos; i++)
        {
            cout << escuela[i].Nombre << " - " << AprobadoDesaprobado(escuela[i].calificaciones, 3) << endl;
        }
    } else
    {
        cout << "Número de alumnos no válido. Debe ser entre 1 y " << MAX_ALUMNOS << ".\n";
    }

    return 0;
}