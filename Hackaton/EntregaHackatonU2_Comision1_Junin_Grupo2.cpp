/*
Escribir un programa en C++ que permita a un usuario llevar un registro de las series y películas que ha visto.
De cada serie o película se requiere contemplar la siguiente información: ID, Título, Género, Año de lanzamiento y Calificación (escala de 1 a 5, donde 1 es la peor calificación y 5 es la mejor).
El programa debe ser capaz de realizar las siguientes operaciones:

Alta: realizar el módulo de carga de series y películas. La carga de datos finaliza con el ID = 0 (cero). 
Las películas o series deben almacenarse en un arreglo ordenadas de menor a mayor por ID.

Baja: eliminar una serie o película a través de su ID ingresado por teclado.
Informar en pantalla si la operación fue o no realizada con éxito.

Reporte 1: informar cuántas series y películas fueron lanzadas en 2023.

Reporte 2: dado el arreglo original, cargar en otro arreglo las películas y series con calificación = 5.
Imprimir este nuevo arreglo mostrando todos los datos de las películas y series.
*/

#include <iostream>
#include <string>
using namespace std;

// Estructura para representar una serie o película
struct Pelicula
{
    int id;
    string titulo;
    string genero;
    int anioLanzamiento;
    int calificacion;
};

const int MAX_CATALOGO = 1000;

/* FUNCION DADA POR INTELIGENCIA ARTIFICIAL
// Función para cargar una serie o película en el vector ordenadamente por ID
void alta(vector<Media>& catalogo) {
    Media media;
    cout << "Ingrese el ID (0 para finalizar): ";
    cin >> media.id;
    
    if (media.id == 0) {
        return;
    }

    cout << "Ingrese el Título: ";
    cin.ignore();
    getline(cin, media.titulo);

    cout << "Ingrese el Género: ";
    getline(cin, media.genero);

    cout << "Ingrese el Año de Lanzamiento: ";
    cin >> media.annoLanzamiento;

    cout << "Ingrese la Calificación (1-5): ";
    cin >> media.calificacion;

    // Insertar en el vector ordenadamente por ID
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if (media.id < it->id) {
            catalogo.insert(it, media);
            return;
        }
    }

    // Si llegamos aquí, el ID es mayor que todos los elementos existentes, por lo que lo agregamos al final.
    catalogo.push_back(media);
}

*/
int AltaCatalogo(Pelicula SeriesPeliculas[], int &TamanioCatalogo)
{
    cout << "Ingrese el ID (0 para finalizar): ";
    cin >> SeriesPeliculas[TamanioCatalogo].id;

    if (SeriesPeliculas[TamanioCatalogo].id == 0)
    {
        return 0; // Salir de la función
    }

    for (int i = 0; i < TamanioCatalogo; i++)
    {
        if (SeriesPeliculas[i].id == SeriesPeliculas[TamanioCatalogo].id)
        {
            cout << "El ID ya existe, ingrese otro: ";
            cin >> SeriesPeliculas[TamanioCatalogo].id;
            i = -1; // Reiniciar el ciclo de búsqueda
        }
    }

    cout << "Ingrese el titulo de la serie/pelicula: ";
    cin.ignore();
    getline(cin, SeriesPeliculas[TamanioCatalogo].titulo);

    cout << "Ingrese el genero de la pelicula: ";
    getline(cin, SeriesPeliculas[TamanioCatalogo].genero);

    cout << "Ingrese el año de lanzamiento: ";
    cin >> SeriesPeliculas[TamanioCatalogo].anioLanzamiento;

    cout << "Ingrese la calificacion (1-5): ";
    cin >> SeriesPeliculas[TamanioCatalogo].calificacion;
    while (SeriesPeliculas[TamanioCatalogo].calificacion < 1 || SeriesPeliculas[TamanioCatalogo].calificacion > 5)
    {
        cout << "Ingrese una calificacion valida (1-5): ";
        cin >> SeriesPeliculas[TamanioCatalogo].calificacion;
    }

    int j = TamanioCatalogo;
    while (j > 0 && SeriesPeliculas[j - 1].id > SeriesPeliculas[j].id)
    {
        Pelicula temporal = SeriesPeliculas[j];
        SeriesPeliculas[j] = SeriesPeliculas[j - 1];
        SeriesPeliculas[j - 1] = temporal;
        j--;
    }

    TamanioCatalogo++; // Incrementar el tamaño lógico del catálogo
    return 1;
}

/* FUNCION DADA POR INTELIGENCIA ARTIFICIAL
// Función para eliminar una serie o película por ID
void baja(vector<Media>& catalogo) {
    int idABorrar;
    cout << "Ingrese el ID a eliminar: ";
    cin >> idABorrar;

    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if (it->id == idABorrar) {
            catalogo.erase(it);
            cout << "La serie/película con ID " << idABorrar << " ha sido eliminada." << endl;
            return;
        }
    }

    cout << "No se encontró ninguna serie/película con ID " << idABorrar << "." << endl;
}
*/
void BajaCatalogo(Pelicula SeriesPeliculas[], int &TamanioCatalogo)
{
    int IDaBorrar;
    cout << "Ingrese el ID a borrar: ";
    cin >> IDaBorrar;

    int indiceAeliminar = -1;
    for (int i = 0; i < TamanioCatalogo; i++)
    {
        if (SeriesPeliculas[i].id == IDaBorrar)
        {
            indiceAeliminar = i;
            break;
        }
    }

    if (indiceAeliminar != -1)
    {
        for (int i = indiceAeliminar; i < TamanioCatalogo - 1; i++)
        {
            SeriesPeliculas[i] = SeriesPeliculas[i + 1];
        }
        TamanioCatalogo--;

        cout << "La pelicula/serie con ID " << IDaBorrar << " ha sido eliminada." << endl;
    } else {
        cout << "No se encontro ninguna pelicula/serie con ID " << IDaBorrar << endl;
    }
}

/* FUNCION DADA POR INTELIGENCIA ARTIFICIAL
// Función para generar el Reporte 1
void reporte1(const vector<Media>& catalogo) {
    int contador = 0;
    for (const Media& media : catalogo) {
        if (media.annoLanzamiento == 2023) {
            contador++;
        }
    }
    cout << "Se lanzaron " << contador << " series/películas en 2023." << endl;
}
*/
void Reporte1(Pelicula SeriesPeliculas[], int TamanioCatalogo)
{
    int contador = 0;
    for (int i = 0; i < TamanioCatalogo; i++) {
        if (SeriesPeliculas[i].anioLanzamiento == 2023)
        {
            contador++;
        }
    }
    cout << "Se registraron " << contador << " series/peliculas en 2023" << endl;
}

/* FUNCION DADA POR INTELIGENCIA ARTIFICIAL
// Función para generar el Reporte 2 y mostrar películas y series con calificación 5
void reporte2(const vector<Media>& catalogo) {
    cout << "Películas y series con calificación 5:" << endl;
    for (const Media& media : catalogo) {
        if (media.calificacion == 5) {
            cout << "ID: " << media.id << endl;
            cout << "Título: " << media.titulo << endl;
            cout << "Género: " << media.genero << endl;
            cout << "Año de Lanzamiento: " << media.annoLanzamiento << endl;
            cout << "Calificación: " << media.calificacion << endl;
            cout << "-------------------------" << endl;
        }
    }
}
*/
void Reporte2(Pelicula SeriesPeliculas[], int TamanioCatalogo)
{
    cout << "Las peliculas y series con calificacion 5 son:" << endl;
    for (int i = 0; i < TamanioCatalogo; i++)
    {
        if (SeriesPeliculas[i].calificacion == 5)
        {
            cout << "ID: " << SeriesPeliculas[i].id << endl;
            cout << "Titulo: " << SeriesPeliculas[i].titulo << endl;
            cout << "Genero: " << SeriesPeliculas[i].genero << endl;
            cout << "Anio de Lanzamiento: " << SeriesPeliculas[i].anioLanzamiento << endl;
            cout << "Calificacion: " << SeriesPeliculas[i].calificacion << endl;
            cout << "-------------------------" << endl;
        }
    }
}

/* MENU PRINCIPAL DADO POR INTELIGENCIA ARTIFICIAL
int main() {
    vector<Media> catalogo;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Alta" << endl;
        cout << "2. Baja" << endl;
        cout << "3. Reporte 1" << endl;
        cout << "4. Reporte 2" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                alta(catalogo);
                break;
            case 2:
                baja(catalogo);
                break;
            case 3:
                reporte1(catalogo);
                break;
            case 4:
                reporte2(catalogo);
                break;
            case 5:
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }

    return 0;
}
*/
int main()
{
    Pelicula SeriesPeliculas[MAX_CATALOGO];
    int TamanioCatalogo = 0;
    int opcion;

    do
    {
        cout << "Menu: " << endl;
        cout << "1. Dar de alta una pelicula/serie" << endl;
        cout << "2. Dar de baja una pelicula/serie" << endl;
        cout << "3. Ver reporte de peliculas/series estrenadas en 2023" << endl;
        cout << "4. Ver reporte de peliculas/series con calificacion 5" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                if (TamanioCatalogo < MAX_CATALOGO)
                {
                    if (AltaCatalogo(SeriesPeliculas, TamanioCatalogo))
                    {
                        cout << "Pelicula/serie agregada con exito." << endl;
                    }
                } else
                {
                    cout << "El catalogo esta lleno, no se pueden agregar más peliculas/series." << endl;
                }
                break;

            case 2:
                BajaCatalogo(SeriesPeliculas, TamanioCatalogo);
                break;

            case 3:
                Reporte1(SeriesPeliculas, TamanioCatalogo);
                break;

            case 4:
                Reporte2(SeriesPeliculas, TamanioCatalogo);
                break;

            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Ingrese una opcion valida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}