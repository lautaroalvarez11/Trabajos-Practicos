#include <iostream>
#include <string>
using namespace std;

/*
1) Identificar errores de sintaxis y lógicos:

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

PROBLEMAS:
1- La dimension lógica se la declara como constante lo cual no permite modificar su valor a lo largo del programa, deberia ser int dimensionLogica = 0
2- El arreglo declarado como parámetro dentro de la función está mal declarado, no es necesario agregarle &, debería ser int arreglo[]
3- En lugar de usar un for, sería mejor utilizar un while ya que no se sabe la cantidad de elementos que el usuario desee ingresar, entonces deberia ser while(codigo != 0 && dimensionLogica < MAX)
4- El parámetro dl en la función cargar está declarado pero no se utiliza en la función, se puede cambiar por dimensionLogica

EL CODIGO QUEDARÍA:
const int MAX = 20;
int cargar(int arreglo[], int dimensionLogica)
{
    int codigo;
    cout << "Ingresar codigo (0 para finalizar): ";
    cin >> codigo;
    while(codigo != 0 && dimensionLogica < MAX)
    {
        arreglo[dimensionLogica] = codigo;
        dimensionLogica++;
        cout << "Ingresar codigo (0 para finalizar): ";
        cin >> codigo;
    }
    return dimensionLogica;
}

int main()
{
    int codigos[MAX];
    int dimensionLogica = 0;
    cargar(codigos, dimensionLogica);
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2) Analizar que se imprime por pantalla:

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

SE IMPRIME:
FuncionA::ImprimirMensaje: Valor de X = 18
FuncionB::ImprimirMensaje: Valor de X = 8

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

3) Realizar código:

const int MaximoEstudiantes = 1000;

struct Estudiantes
{
	int numeroLegajo;
	string NombreApellido;
	string Curso;
	float Calificacion;
};

double CalcularPromedio(Estudiantes arreglo[MaximoEstudiantes], int dimensionLogica, string cursoBuscado)
{
	double calificacionTotal = 0.0;
	int cantidadEstudiantesDelCurso = 0;
	
	for(int i = 0; i < dimensionLogica; i++)
	{
		if(arreglo[i].Curso == cursoBuscado)
		{
			calificacionTotal += arreglo[i].Calificacion;
			cantidadEstudiantesDelCurso++;
		}
	}
	
	if(cantidadEstudiantesDelCurso == 0)
	{
		cout << "No se encontraron estudiantes en el curso " << cursoBuscado << endl;
        	return 0.0;
	}

	return calificacionTotal / cantidadEstudiantesDelCurso;
}

int main()
{
	int dimensionLogica = 0;
	Estudiantes arreglo[MaximoEstudiantes];
	
	string cursoBuscado;
	cout << "Ingrese un curso: ";
	getline(cin, cursoBuscado);

	double promedioTotal = CalcularPromedio(arreglo, dimensionLogica, cursoBuscado);
	if (promedioTotal > 0)
        {
        	cout << "El promedio de calificaciones para el curso " << cursoBuscado << " es: " << promedioTotal << endl;
    	}
    
    	return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

4) Identificar errores de sintaxis o lógicos:

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

PROBLEMAS:
1- Declara una matriz de 2x2 y luego inicializa como si fuera una matriz de 3x3, deberia ser int matriz[3][3];
2- En la fila 1 columna 2 ingresa un valor flotante cuando deberia ser un entero porque asi se definió la matriz
3- Si fuera una matriz de 2x2 se borrarían 5 elementos y en el bucle for se recorrería hasta i < 2 y j < 2

EL CÓDIGO QUEDARÍA:
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