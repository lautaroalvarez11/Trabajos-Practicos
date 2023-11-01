#include <iostream>
#include <string>
using namespace std;

struct Estudiante 
{
    string nombreApellido;
    int legajo;
    int inasistencias;
    float calificacion;
};

int main() 
{
    const int MAX_ESTUDIANTES = 1000;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes;

    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;

    if (numEstudiantes <= MAX_ESTUDIANTES && numEstudiantes > 0)
    {
        cin.ignore(); // Limpiar el búfer de entrada

        // Inicializar variables para calcular el promedio de calificaciones
        float sumaCalificaciones = 0.0;
        int numCalificacionesMayorPromedio = 0;
        float promedioTotal;

        // Inicializar variables para almacenar legajos con promedio mayor o igual a 9
        int legajosPromedioNueve[MAX_ESTUDIANTES];
        int numLegajosPromedioNueve = 0;

        // Leer datos de los estudiantes y realizar las tareas solicitadas
        for (int i = 0; i < numEstudiantes; i++)
        {
            cout << "Datos del Estudiante: " << (i + 1) << endl;
            cout << "Nombre y Apellido: ";
            getline(cin, estudiantes[i].nombreApellido);

            cout << "Legajo: ";
            cin >> estudiantes[i].legajo;

            cout << "Inasistencias: ";
            cin >> estudiantes[i].inasistencias;

            cout << "Calificación: ";
            cin >> estudiantes[i].calificacion;

            cin.ignore(); // Limpiar el búfer de entrada

            // Imprimir nombre y apellido de los alumnos con más de 5 inasistencias
            if (estudiantes[i].inasistencias > 5)
            {
                cout << "Alumno con más de 5 inasistencias: " << estudiantes[i].nombreApellido << endl;
            }

            // Calcular el promedio de las calificaciones
            sumaCalificaciones += estudiantes[i].calificacion;

            // Almacenar legajos con promedio mayor o igual a 9
            if (estudiantes[i].calificacion >= 9.0)
            {
                legajosPromedioNueve[numLegajosPromedioNueve] = estudiantes[i].legajo;
                numLegajosPromedioNueve++;
            }
        }

        // Calcular el promedio total de calificaciones
        promedioTotal = sumaCalificaciones / numEstudiantes;

        // Imprimir legajos de estudiantes con calificación mayor o igual al promedio total
        cout << "Legajos con calificación mayor o igual al promedio total (" << promedioTotal << "): ";
        for (int i = 0; i < numEstudiantes; i++)
        {
            if (estudiantes[i].calificacion >= promedioTotal)
            {
                cout << estudiantes[i].legajo << endl;
            }
        }

        // Imprimir legajos de estudiantes con promedio mayor o igual a 9
        cout << "Legajos con promedio mayor o igual a 9:" << endl;
        for (int i = 0; i < numLegajosPromedioNueve; i++)
        {
            cout << legajosPromedioNueve[i] << endl;
        }

        // Eliminar un estudiante dado su legajo (si se desea)
        char opciones;
        cout << "Desea eliminar un alumno del sistema?" << endl;
        cout << "A. Si" << endl;
        cout << "B. No" << endl;
        cin >> opciones;

        switch(opciones)
        {
            case 'a':
            case 'A':
            {
                int legajoAEliminar;
                cout << "Ingrese el legajo del estudiante que desea eliminar: ";
                cin >> legajoAEliminar;
                int indiceAEliminar = -1;

                for (int i = 0; i < numEstudiantes; i++)
                {
                    if (estudiantes[i].legajo == legajoAEliminar)
                    {
                        indiceAEliminar = i;
                        break;
                    }
                }

                if (indiceAEliminar != -1)
                {
                    for (int i = indiceAEliminar; i < numEstudiantes - 1; i++)
                    {
                        estudiantes[i] = estudiantes[i + 1];
                    }
                    numEstudiantes--;

                    cout << "Estudiante con legajo " << legajoAEliminar << " ha sido eliminado." << endl;
                } else
                {
                    cout << "No se encontró ningún estudiante con el legajo " << legajoAEliminar << endl;
                }
            }

            case 'b':
            case 'B':
            {
                cout << "Gracias por utilizar el sistema";
                break;
            }

        }

    } else
    {
        cout << "Número de estudiantes no válido. Debe ser entre 1 y " << MAX_ESTUDIANTES << endl;
    }
    
    return 0;
}