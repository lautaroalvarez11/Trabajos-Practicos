#include <iostream>
#include <string>
using namespace std;

struct Ciudadano
{
    string nombreApellido;
    long nacimiento;
    string direccion;
    int DNI;
    int tipoDocumento;
    char sexo;
};

// Función para cargar los datos de los ciudadanos
void cargarCiudadano(Ciudadano persona[], int &numCiudadanos)
{
    cout << "Ingrese los datos de los ciudadanos (o escriba '0' en la fecha de nacimiento para finalizar):" << endl;
    while (numCiudadanos < 1000) 
    {
        cout << "Nombre y Apellido: ";
        getline(cin, persona[numCiudadanos].nombreApellido);

        cout << "Fecha de Nacimiento (AAAAMMDD): ";
        cin >> persona[numCiudadanos].nacimiento;

        if (persona[numCiudadanos].nacimiento == 0)
        {
            break; // Finalizar la carga si se ingresa '0' en la fecha de nacimiento
        }

        cin.ignore(); // Limpiar el búfer de entrada

        cout << "Direccion: ";
        getline(cin, persona[numCiudadanos].direccion);

        // Validar el tipo de documento
        do 
        {
            cout << "Tipo de Documento (1 - DNI, 2 - Pasaporte, 3 - Otro): ";
            cin >> persona[numCiudadanos].tipoDocumento;
        } while (persona[numCiudadanos].tipoDocumento < 1 || persona[numCiudadanos].tipoDocumento > 3);

        cout << "Numero de Documento: ";
        cin >> persona[numCiudadanos].DNI;

        cin.ignore(); // Limpiar el búfer de entrada

        cout << "Sexo (M - Masculino, F - Femenino): ";
        cin >> persona[numCiudadanos].sexo;

        cin.ignore(); // Limpiar el búfer de entrada

        numCiudadanos++;
    }
}

// Función para imprimir los datos de los ciudadanos
void imprimirCiudadano(const Ciudadano& persona) 
{
    cout << "Nombre y Apellido: " << persona.nombreApellido << endl;
    cout << "Direccion: " << persona.direccion << endl;
    
    // Formatear la fecha de nacimiento en formato dd/mm/aa
    int dia = (persona.nacimiento % 100);
    int mes = ((persona.nacimiento / 100) % 100);
    int anio = persona.nacimiento / 10000;
    cout << "Fecha de Nacimiento: " << dia << "/" << mes << "/" << anio << endl;
    
    cout << "Tipo de Documento: ";
    switch (persona.tipoDocumento) {
        case 1:
            cout << "DNI";
            break;
        case 2:
            cout << "Pasaporte";
            break;
        case 3:
            cout << "Otro";
            break;
    }
    cout << endl;
    
    cout << "Numero de Documento: " << persona.DNI << endl;
    cout << "Sexo: ";
    if (persona.sexo == 'M' || persona.sexo == 'm')
    {
        cout << "Masculino";
    } else if (persona.sexo == 'F' || persona.sexo == 'f')
    {
        cout << "Femenino";
    }
    cout << endl;
}

// Función para filtrar ciudadanos por sexo
void filtrarPorSexo(const Ciudadano persona[], int numCiudadanos, char sexoFiltrar, Ciudadano ciudadanosFiltrados[], int& numCiudadanosFiltrados)
{
    numCiudadanosFiltrados = 0;
    for (int i = 0; i < numCiudadanos; i++)
    {
        if (persona[i].sexo == sexoFiltrar)
        {
            ciudadanosFiltrados[numCiudadanosFiltrados] = persona[i];
            numCiudadanosFiltrados++;
        }
    }
}

int main()
{
    Ciudadano persona[1000];
    int numCiudadanos = 0;
    
    cargarCiudadano(persona, numCiudadanos);

    cout << "------------------------" << endl;
    cout << "Listado de Ciudadanos:" << endl;
    for (int i = 0; i < numCiudadanos; i++)
    {
        imprimirCiudadano(persona[i]);
        cout << "------------------------" << endl;
    }

    // Filtrar y mostrar ciudadanos masculinos
    Ciudadano ciudadanosMasculinos[1000];
    int numCiudadanosMasculinos = 0;
    filtrarPorSexo(persona, numCiudadanos, 'M', ciudadanosMasculinos, numCiudadanosMasculinos);

    cout << "Listado de Ciudadanos Masculinos:" << endl;
    for (int i = 0; i < numCiudadanosMasculinos; i++)
    {
        imprimirCiudadano(ciudadanosMasculinos[i]);
        cout << "------------------------" << endl;
    }

    // Filtrar y mostrar ciudadanos femeninos
    Ciudadano ciudadanosFemeninos[1000];
    int numCiudadanosFemeninos = 0;
    filtrarPorSexo(persona, numCiudadanos, 'F', ciudadanosFemeninos, numCiudadanosFemeninos);

    cout << "Listado de Ciudadanos Femeninos:" << endl;
    for (int i = 0; i < numCiudadanosFemeninos; i++)
    {
        imprimirCiudadano(ciudadanosFemeninos[i]);
        cout << "------------------------" << endl;
    }


    return 0;
}