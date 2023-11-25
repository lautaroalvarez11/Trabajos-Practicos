/*
Realizar un programa que almacene en un arreglo la lista de invitados a una fiesta. El salón donde se realizará
tiene capacidad máxima para 150 personas.
De cada invitado se conoce nombre, apellido, sexo y edad. Se ingresarán datos hasta que el nombre sea igual a
“ZZZ” o hasta que la capacidad del salón esté completa.
Una vez finalizada la carga:
a) Informar la cantidad de invitados que asistirán a la fiesta.
b) Realizar una función que liste los nombres de las mujeres cuya edad sea <= 20.
c) Realizar una función que, dado un apellido y nombre, permita eliminar un invitado en caso de no poder asistir.
*/

#include <iostream>
#include <string>
using namespace std;

struct Fiesta
{
    string NombreApelido;
    char Sexo;
    int Edad;
};

const int MAX_INVITADOS = 150;
int cantidadInvitados = 0;

void CargarInvitados(Fiesta invitados[MAX_INVITADOS])
{
    while(cantidadInvitados < MAX_INVITADOS)
    {
        cout << "Ingrese nombre y apellido de invitado/a (Ingrese ZZZ para finalizar): ";
        getline(cin, invitados[cantidadInvitados].NombreApelido);

        if(invitados[cantidadInvitados].NombreApelido == "ZZZ" || invitados[cantidadInvitados].NombreApelido == "zzz")
        {
            cout << "------------------------" << endl;
            break;
        }

        cout << "Ingrese sexo del invitado/a(F o M): ";
        cin >> invitados[cantidadInvitados].Sexo;

        cout << "Ingrese edad del invitado/a: ";
        cin >> invitados[cantidadInvitados].Edad;
        cin.ignore();

        cantidadInvitados++;
    }
}

void NombreMujeresMenorIgualA20(Fiesta invitados[MAX_INVITADOS])
{
    cout << "Lista de mujeres con edad menor o igual a 20:" << endl;
    for (int i = 0; i < MAX_INVITADOS; ++i)
    {
        if (invitados[i].Sexo == 'F' || invitados[i].Sexo == 'f' && invitados[i].Edad <= 20)
        {
            cout << "Nombre: " << invitados[i].NombreApelido << endl;
        }
    }
    cout << "------------------------" << endl;
}

void EliminarInvitado(Fiesta invitados[MAX_INVITADOS])
{
    string nombreEliminar;
    cout << "Ingrese el nombre del invitado/a a eliminar: ";
    getline(cin, nombreEliminar);

    bool invitadoEncontrado = false;
    for(int i = 0; i < MAX_INVITADOS; ++i)
    {
        if(invitados[i].NombreApelido == nombreEliminar)
        {
            // Eliminar el invitado encontrando moviendo los elementos posteriores hacia atrás
            for (int j = i; j < MAX_INVITADOS - 1; ++j)
            {
                invitados[j] = invitados[j + 1];
            }
            invitadoEncontrado = true;
            cout << "Invitado/a '" << nombreEliminar << "' eliminado/a correctamente." << endl;
            break;
            cout << "------------------------" << endl;
        }
    }

    if (invitadoEncontrado != invitadoEncontrado)
    {
        cout << "No se encontro al invitado/a '" << nombreEliminar << "' en la lista." << endl;
        cout << "------------------------" << endl;
    }
}

void MostrarListaInvitados(Fiesta invitados[MAX_INVITADOS], int cantidadInvitados)
{
    cout << "Lista de invitados total:" << endl;
    for (int i = 0; i < cantidadInvitados; ++i)
    {
        cout << "Invitado/a " << i + 1 << ":" << endl;
        cout << "Nombre: " << invitados[i].NombreApelido << endl;
        cout << "Sexo: " << invitados[i].Sexo << endl;
        cout << "Edad: " << invitados[i].Edad << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    Fiesta listaInvitados[MAX_INVITADOS];

    cout << "Bienvenido al sistema" << endl;
    
    int opciones;

    do
    {
        cout << "Continue en el sistema" << endl;
        cout << "1. Cargar invitados/as a la fiesta." << endl;
        cout << "2. Mostrar lista con mujeres con edad menor o igual a 20." << endl;
        cout << "3. Eliminar un/a invitado/a." << endl;
        cout << "4. Mostrar lista total de invitados/as" << endl;
        cout << "5. Salir." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;
        cin.ignore(); // Limpiar el buffer de nueva línea

        switch (opciones)
        {
            case 1:
            {
                CargarInvitados(listaInvitados);
                break;
            }

            case 2:
            {
                NombreMujeresMenorIgualA20(listaInvitados);
                break;
            }

            case 3:
            {
                EliminarInvitado(listaInvitados);
                break;
            }

            case 4:
            {
                MostrarListaInvitados(listaInvitados, cantidadInvitados);
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