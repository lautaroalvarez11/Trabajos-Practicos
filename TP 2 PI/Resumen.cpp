// ARREGLOS

/*
Inicialización de un arreglo:
    float R[10] = {2, 32, 4.6, 2, 1, 0.5, 3, 8, 0, 12};
    float S[] = {2, 32, 4.6, 2, 1, 0.5, 3, 8, 0, 12};
    int N[] = {1, 2, 3, 6};
    int Matriz[2][3] = {{1, 3, 5}, {5, 10, 2}};
    int J[][3] = {213, 32, 32, 32, 43, 32, 3, 43, 21};
*/

/*
Iteración en un arreglo:
    for (int i = 0; i < dimension_logica; i++)
    {
        cout << arreglo[i] << endl;
    }
*/

/*
Insertar un elemento en un arreglo al final:
    const int dimension_fisica = algun valor;

    int InsertarAlFinal(int arreglo[], int dimension_logica)
    {
        int numero;
        cout << "Ingrese un numero: (0 para cortar) ";
        cin >> numero;
        while (numero != 0 && dimension_logica < dimension_fisica)
        {
            arreglo[dimension_logica] = numero;
            dimension_logica++;
            cout << "Ingrese un numero: (0 para cortar) ";
            cin >> numero;
        }
        return dimension_logica;
    }

    int main()
    {
        int arreglo[dimension_fisica];
        int dimension_logica = 0;
        dimension_logica = InsertarAlFinal(arreglo, dimension_logica);
        return 0;
    }
*/

/*
Insertar un elemento en un arreglo de forma ordenada:
    const int dimension_fisica = algun valor;

    int InsertarOrdenado(int arreglo[], int dimension_logica, int nuevoDato)
    {
        int i = 0;
        while (i < dimension_logica && arreglo[i] < nuevoDato)
        {
            i++;
        }
        for (int j = dimension_logica; j > i; j--)
        {
            arreglo[j] = arreglo[j-1];
        }
        arreglo[i] = nuevoDato;
        return dimension_logica + 1;
    }

    int InsertarAlFinal(int arreglo[], int dimension_logica)
    {
        int numero;
        cout << "Ingrese un numero: (0 para cortar) ";
        cin >> numero;
        while (numero != 0 && dimension_logica < dimension_fisica)
        {
            dimension_logica = InsertarOrdenado(arreglo, dimension_logica, numero);
            cout << "Numero: (0 para cortar) ";
            cin >> numero;
        }
        return dimension_logica;
    }

    int main()
    {
        int arreglo[dimension_fisica];
        int dimension_logica = 0;
        dimension_logica = InsertarAlFinal(arreglo, dimension_logica);
        return 0;
    }
*/

/*
Eliminar un elemento de un arreglo:
    int i = 0;
    while (i < dimension_logica && arreglo[i] != elementoAEliminar)
    {
        i++;
    }
    if (arreglo[i] == elementoAEliminar)
    {
        for (int j = i; j < dimension_logica - 1; j++)
        {
        arreglo[j] = arreglo[j+1];
        }
        dimension_logica--;
    }
*/

/*
Eliminar varios elementos de un arreglo:
    int i = 0;
    while (i < dimension_logica)
    {
    if (arreglo[i] == elementoAEliminar)
    {
        for (int j = i; j < dl-1; j++)
        {
            arreglo[j] = arreglo[j+1];
        }
        dl--;
    }
    else
    {
        i++;
    }
*/



// STRUCTS

/*
Definición y asignacion de un struct:
    struct NombreDelStruct
    {
        tipo NombreCampo1;
        tipo NombreCampo2;
        ...
    };

    NombreDelStruct ahora es un nuevo tipo de variable, ejemplo NombreDelStruct variable1
    Para referenciar a cada campo del struct se utiliza el nombre de la variable y el nombre del campo, separados por un punto, ejemplo variable1.NombreCampo1 = algun valor;
    
    Ejemplo struct y asignacion:
        struct Persona
        {
            string Nombre;
            int DNI;
            string Direccion;
        };
        Persona una_persona;
        Persona otra_persona;

        Asignación campo a campo:
            una_persona.Direccion = "Direccion 123";
            una_persona.DNI = 12345678;
            una_persona.Nombre = "Nombre";

        Asignación en una misma línea:
            una_persona = {"Nombre", 12345678, "Direccion 123"};

        Asignación de un struct a otro:
            otra_persona = una_persona;

    Las operaciones de comparación solo se permiten de campo a campo, no de struct a struct ni de variable a variable:
        if(una_persona.DNI < otra_persona.DNI) SI
        if(una_persona < otra_persona) NO        
*/

/*
Imprimir los datos de un struct:
    Solo se pueden imprimir uno a uno los campos del struct, no se puede imprimir una struct completa
*/

/*
Operaciones con los campos de un struct:
    Como cada campo de una struct tiene un tipo de dato asociado
    Sobre cada campo podrán aplicarse las operaciones definidas para el tipo de dato del mismo
*/

/*
Arreglos con elementos de tipo Struct:
    Para referenciar a un campo determinado de una struct almacenada en un arreglo, se debe acceder al elemento correspondiente (mediante su índice) y utilizar el punto para individualizar el campo
    
    Ejemplo:
        Persona alumnos[5000];
        int dimension_logica = 0;
        alumnos[0].Direccion = "Direccion 123";
        alumnos[0].Nombre = "Nombre";
        alumnos[0].DNI = 12345678;
    alumnos[0] es un dato de tipo Persona al igual que en la declaración

    En un arreglo de structs, cada elemento es una struct. Por ende, si se accede a un elemento del arreglo, se estará obteniendo una struct
    Y, obtenida la struct, se puede acceder a sus campos
        alumnos[0] -> Se obtiene una struct de tipo Persona
        alumnnos[0].DNI -> Se obtiene un número de tipo int

    Podría pasarse una struct contenida en el arreglo como argumento en una llamada a una función que reciba una struct del mismo tipo
    Ejemplo:    
        int digitosDNI(Persona alumno)
        {
            int digitos = 0;
            while (alumno.DNI != 0) 
            {
                digitos++;
                alumno.DNI = alumno.DNI/10;
            }
            return digitos;
        }
        int main()
        {
            Persona alumnos[5000];
            int dimension_logica = 0;
            dimension_logica = InsertarAlFinal(alumnos, dimension_logica);
            cout << "Cantidad de dígitos del DNI: " << digitosDNI(alumnos[3]);
            return 0;
        }

    Debido a que cada campo puede accederse de forma individual, también podría pasarse únicamente uno de los campos de la struct contenida en el arreglo (y en este caso sería lo óptimo, ya que la función sólo trabaja con un número)
    Ejemplo:
        int cantDigitos(int n)
        {
            int digitos = 0;
            while (n != 0)
            {
                n = n/10;
                digitos++;
            }
            return digitos;
        }
        int main()
        {
            Persona alumnos[100];
            int dimension_logica = 0;
            dimension_logica = InsertarAlFinal(alumnos, dimL);
            cout << "Cantidad de dígitos del DNI: " << cantDigitos(alumnos[3].dni);
            return 0;
        }

    No es posible imprimir una struct completa. Entonces, si queremos imprimir las structs contenidas en el arreglo, deberemos iterar por él, imprimiendo campo a campo
    Ejemplo:
        void imprimir(Persona arreglo[], int dimension_logica)
        {
            for (int i = 0; i != dimension_logica; i++)
            {
                cout << arreglo[i].nombre << endl;
                cout << arreglo[i].dni << endl;
                cout << arreglo[i].direccion << endl;
            }
        }

    Los algoritmos de carga son los mismos que se usan para cargar cualquier arreglo, sólo que ahora se indica cada campo de la struct donde se quiere almacenar algo
    Ejemplo:
        int InsertarAlFinal(Persona arreglo[], int dimension_logica)
        {
            Persona auxiliar;
            cout << "Nombre: (x para cortar) ";
            getline(cin>>ws, auxiliar.Nombre);
            while (auxiliar.Nombre != "x" && dimension_logica < dimension_fisica)
            {
                cout << "DNI: ";
                cin >> auxiliar.DNI;
                cout << "Dirección: ";
                getline(cin>>ws, auxiliar.Direccion);
                arreglo[dimension_logica] = auxiliar;
                dimension_logica++;
                cout << "Nombre: (x para cortar) ";
                getline(cin>>ws, auxiliar.Nombre);
            }
            return dimension_logica;
        }

    Ejemplo práctico:
        struct Persona
        {
            string Nombre;
            int Edad;
        };

        int main()
        {
            const int NumeroDePersonas = 3; // Dimensión física
            Persona personas[NumeroDePersonas]; // Declarar un arreglo de tipo Persona que utiliza la dimension fisica NumeroDePersonas

            personas[0] = {"Antonio", 8}; // El primer elemento del arreglo utiliza los campos Nombre y Edad del struct Persona
            personas[1] = {"Pilar", 16}; // El segundo elemento del arreglo utiliza los campos Nombre y Edad del struct Persona
            personas[2] = {"Sara", 21}; // El tercer elemento del arreglo utiliza los campos Nombre y Edad del struc Persona
            
            for(int i = 0; i < NumeroDePersonas; ++i) // Acceder a los datos y mostrar información
            {
                cout << "Persona: " << i + 1 << endl;
                cout << "Nombre: " << personas[i].Nombre << endl;
                cout << "Edad: " << personas[i].Edad << endl;
            } 
        }
*/







#include <iostream>
#include <string>
using namespace std;

