#include <iostream>
#include <string>
using namespace std;

// ACT 1 Identificar errores
const int MAX = 20;
int cargar(int &arreglo[], int dl)
{
    int codigo;
    cout << "Ingresar codigo: (0 para finalizar)";
    cin >> codigo;
    for(codigo >= 1; codigo != 0; codigo++)
    {
        arreglo[dimensionLogica] = codigo;
        dimensionLogica++;
        cout << "Ingresar codigo: (0 para finalizar)";
        cin >> codigo;
    }
    return dimensionLogica;
}

int main()
{
    int codigos[MAX];
    const int dimensionLogica = 0;
    cargar(codigos, dimensionLogica);
    return 0;
}

/*
PROBLEMAS:
1. El parámetro arreglo[] en la función cargar está mal declarado.
Debería ser int arreglo[] en lugar de int &arreglo[].
En este caso no es necesario pasar el parámetro por referencia.

2. El parámetro dl en la función cargar está declarado pero no se utiliza en la función.
Se puede cambiar por dimensionLogica.

3. En el bucle for dentro de la función cargar, la condición codigo >= 1 debería ser codigo > 0.
Además, en la expresión de incremento, se debería usar codigo-- en lugar de codigo++
para disminuir el valor de codigo.

4. La variable dimensionLogica se declara como const int dimensionLogica = 0; en la función main,
lo que hace que no se pueda modificar. Se debe declarar como una variable normal
y luego pasarla por referencia a la función cargar para que pueda actualizarse dentro de la función.

SOLUCIÓN:
const int MAX = 20;
int cargar(int arreglo[], int &dimensionLogica)
{
    int codigo;
    cout << "Ingresar codigo: (0 para finalizar)";
    cin >> codigo;
    for(codigo > 0; codigo != 0; codigo--)
    {
        arreglo[dimensionLogica] = codigo;
        dimensionLogica++;
        cout << "Ingresar codigo: (0 para finalizar)";
        cin >> codigo;
    }
    return dimensionLogica;
}

int main()
{
    int codigos[MAX];
    int dimensionLogica;
    cargar(codigos, dimensionLogica);
    return 0;
}
*/

// -----------------------------------------------------------------------------------------------

// ACT 2 Indicar que valores se imprimen
void funcionA(int x)
{
    x = x + 10;
    cout << "FuncionA::ImprimirMensaje: Valor de X = " << x << endl;
}

void funcionB(int &x)
{
    x = x + 3;
    funcionA(x);
    cout << "FuncionB::ImprimirMensaje: Valor de X = " << x << endl;
}

int main()
{
    int x = 5;
    funcionB(x);
    return 0;
}

/*
FuncionA::ImprimirMensaje: Valor de X = 18

FuncionB::ImprimirMensaje: Valor de X = 8
*/

// -----------------------------------------------------------------------------------------------

// ACT 3 Escribir código

struct Estudiantes
{
    int legajo;
    string nombreApellido;
    string curso;
    float calificacion;
};

const int MaxEstudiantes = 1000; // DIMENSION FÍSICA
double PromedioEstudiantes(Estudiantes estudiante[MaxEstudiantes], int numEstudiantes, string cursoBuscado)
{
    double sumaCalificaciones = 0.0;
    int cantidadEstudiantes = 0;

    for (int i = 0; i < numEstudiantes; i++)
    {
        if (estudiante[i].curso == cursoBuscado)
        {
            sumaCalificaciones += estudiante[i].calificacion;
            cantidadEstudiantes++;
        }
    }

    if (cantidadEstudiantes == 0)
    {
        cout << "No se encontraron estudiantes en el curso " << cursoBuscado << endl;
        return 0.0;
    }

        return sumaCalificaciones / cantidadEstudiantes;
}

int main()
{
    const int MAX_ESTUDIANTES = 100; // Máximo número de estudiantes que se pueden registrar
    Estudiantes estudiante[MAX_ESTUDIANTES];
    int numEstudiantes = 0;

    string cursoBuscado;
    cout << "Ingrese el nombre del curso para calcular el promedio de calificaciones: ";
    cin >> cursoBuscado;

    double promedioTotal = PromedioEstudiantes(estudiante, numEstudiantes, cursoBuscado);
    if (promedioTotal > 0)
    {
        cout << "El promedio de calificaciones para el curso " << cursoBuscado << " es: " << promedioTotal << endl;
    }
    
    return 0;
}

// -----------------------------------------------------------------------------------------------

// ACT 4  Identificar errores

int main()
{
    int matriz[2][2];

    matriz[0][0] = 1;
    matriz[0][1] = 2.5;
    matriz[0][2] = 3;

    matriz[1][0] = 4;
    matriz[1][1] = 5;
    matriz[1][2] = 6;

    matriz[2][0] = 7;
    matriz[2][1] = 8;
    matriz[2][2] = 9;

    cout << "Matriz:" << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << matriz[i][j] << "";
        }
        cout << endl;
    }
    return 0;
}

/*
PROBLEMAS:
1. Se define una matriz de 2x2 y luego se inicializan 9 valores, es decir,
se quiere definir una matriz de 3x3

2. Tiene un valor de tipo float en la posicion 0 - 1, cuando la matriz se definio
de tipo int

SOLUCIÓN:
int main()
{
    int matriz[3][3];

    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[0][2] = 3;

    matriz[1][0] = 4;
    matriz[1][1] = 5;
    matriz[1][2] = 6;

    matriz[2][0] = 7;
    matriz[2][1] = 8;
    matriz[2][2] = 9;

    cout << "Matriz:" << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << matriz[i][j] << "";
        }
        cout << endl;
    }
    return 0;
}
*/