/*
Generar una lista enlazada simple con la nómina de artículos de un supermercado. De cada artículo se conoce:
código, descripción, precio y stock. La carga finaliza con el código -1. Se solicita:

A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.

B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
incrementar el stock. Si no existe el artículo en la lista se debe informar.

C. Eliminar de la lista los artículos que no tienen stock.
*/

#include <iostream>
#include <string>
using namespace std;

struct Articulos
{
    int codigo;
    string descripcion;
    int precio;
    int stock;
};

struct Nodo
{
    Articulos articulosSuper;
    Nodo* siguiente;
};

// -----------------------------------------------------------------------

Nodo* insertarOrdenado(Nodo* inicio, Articulos productos)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nuevo nodo para insertar un articulo en la lista
    nuevoNodo -> siguiente = nullptr; // Se indica que la lista no contiene ningun elemento

    // Al campo articulosSuper del nuevo nodo se le asigna el parametro productos para que se guarden los productos pasados por este ultimo parametro y de ahi se almacenen en el struct Articulos 
    nuevoNodo -> articulosSuper = productos;

    
    if(inicio == nullptr || nuevoNodo -> articulosSuper.codigo < inicio -> articulosSuper.codigo) // Si la lista está vacía o el codigo del nuevo nodo debe ir al principio porque es menor que el primer codigo de la lista.
    {
        nuevoNodo -> siguiente = inicio; // El nuevo nodo apunta al nodo actual en el inicio.
        inicio = nuevoNodo; // Se actualiza el inicio de la lista para que el nuevo nodo sea el nuevo inicio.
    }
    else
    {
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que empieza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> articulosSuper.codigo < nuevoNodo -> articulosSuper.codigo) // Mientras la lista no esté vacía y el codigo del siguiente nuevo nodo es menor que el codigo del nuevo nodo (Se busca la posición adecuada para insertar el nuevo codigo)
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor menor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el codigo del nuevo nodo.
        nuevoNodo -> siguiente = auxiliar -> siguiente; // El nuevo nodo apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevoNodo; // El anterior (auxiliar) apuntará al nuevo nodo;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nuevo nodo se insertó al inicio
}

// FUNCIÓN A
Nodo* incrementarPrecio(Nodo* inicio, float porcentaje)
{
    Nodo* auxiliar = inicio; // Se crea un puntero auxiliar que empieza en el inicio de la lista
    while(auxiliar != nullptr) // Mientras la lista no termine
    {
        auxiliar -> articulosSuper.precio += auxiliar -> articulosSuper.precio * porcentaje / 100; // Al precio de un articulo se le suma ese precio multiplicado por el porcentaje que el usuario desee y dividido 100 para convertirlo a una fracción
        auxiliar = auxiliar -> siguiente; // Recorre todos los nodos (articulos de la lista) para incrementar el precio de c/u
    }
    return inicio; // Retorna el inicio por si se modificaron los precios de los articulos
}

// FUNCION B
Nodo* incrementarStock(Nodo* inicio, int codigo, int stock)
{
    Nodo* auxiliar = inicio; // Se crea un puntero auxiliar que empieza en el inicio de la lista
    while(auxiliar != nullptr) // Mientras la lista no termine
    {
        if(auxiliar -> articulosSuper.codigo == codigo) // Si el codigo del articulo es igual al codigo ingresado por el usuario
        {
            auxiliar -> articulosSuper.stock += stock; // A cada stock del articulo se le suma la cantidad de stock que el usuario ingrese
            return inicio; // Retorna el inicio por si se modificó la cantidad de stocks
        }
        else
        {
            auxiliar = auxiliar -> siguiente; // Si el codigo del articulo es distinto del codigo ingresado por el usuario, recorre la lista hasta encontrar el que sea igual
        }
    }
    cout << "El codigo ingresado no corresponde a ningun articulo en stock."; // Si se ingresa un codigo no existente
    return inicio; // Retorna el inicio por si se modificó la cantidad del primer articulo
}

// FUNCION C
Nodo* eliminarArticuloSinStock(Nodo* inicio)
{
    if(inicio != nullptr) // Mientras la lista contenga articulos
    {
        Nodo* auxiliar = inicio; // Se crea un puntero auxiliar que empieza en el inicio de la lista
        if(auxiliar -> articulosSuper.stock == 0) // Si la cantidad de stock del primer articulo es 0
        {
            inicio = inicio -> siguiente; // El puntero inicial va a apuntar al siguiente articulo en la lista
            delete auxiliar; // Se elimina el primer articulo que contenia stock 0
        }
        else
        {
            while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> articulosSuper.codigo != 0) // Mientras la lista contenga elementos y el codigo del segundo articulo sea distinto de 0
            {
                auxiliar = auxiliar -> siguiente; // Recorre la lista
            }
            if(auxiliar -> siguiente -> articulosSuper.codigo == 0) // Si el codigo del articulo apuntado por el puntero auxiliar, es decir el inicio, es 0
            {
                Nodo* aEliminar = auxiliar -> siguiente; // Se crea un puntero que apunta al siguiente articulo que apunta el puntero auxiliar, es decir el inicio
                auxiliar -> siguiente = aEliminar -> siguiente; // Se actualiza el puntero siguiente del articulo apuntado por el puntero auxiliar para saltar al articulo con stock 0
                delete aEliminar; // Se elimina el articulo que contenia stock 0
            }
        }
    }
    return inicio; // Retorna el inicio por si se modificó la cantidad de articulos en la lista
}

void mostrarLista(Nodo* inicio)
{
    cout << "LISTA DE ARTICULOS" << endl;
    for(Nodo* auxiliar = inicio; auxiliar != nullptr; auxiliar = auxiliar -> siguiente)
    {
        cout << "Codigo: " << auxiliar -> articulosSuper.codigo << endl;
        cout << "Descripcion: " << auxiliar -> articulosSuper.descripcion << endl;
        cout << "Precio: " << auxiliar -> articulosSuper.precio << endl;
        cout << "Stock: " << auxiliar -> articulosSuper.stock << endl;
        cout << "----------------" << endl;
    }
    cout << endl;
}

void Menu(Nodo* inicio)
{
    int opcion, stock, codigo;
    float porcentaje;

    cout << "MENU" << endl;
    cout << "1. Incrementar el precio de los articulos" << endl;
    cout << "2. Incrementar el stock de un articulo" << endl;
    cout << "3. Eliminar los articulos que no tienen stock" << endl;
    cout << "4. Mostrar lista de articulos" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;

    switch(opcion)
    {
        case 1:
        {
            cout << "Ingrese el porcentaje a aumentar en los precios: ";
            cin >> porcentaje;
            inicio = incrementarPrecio(inicio, porcentaje);
            Menu(inicio);
            break;
        }

        case 2:
        {
            cout << "Ingrese el codigo del articulo: ";
            cin >> codigo;
            cout << "Ingrese la cantidad que desea aumentar de articulos en stock: ";
            cin >> stock;
            inicio = incrementarStock(inicio, codigo, stock);
            Menu(inicio);
            break;
        }

        case 3:
        {
            inicio = eliminarArticuloSinStock(inicio);
            Menu(inicio);
            break;
        }

        case 4:
        {
            mostrarLista(inicio);
            break;
        }
        
        case 5:
        {
            break;
        }

        default:
        {
            cout << "Se ingreso una opcion no valida.";
            Menu(inicio);
            break;
        }
    }
}



int main()
{
    Nodo* inicio = new Nodo;
    inicio = nullptr;

    Articulos producto;

    cout << "Ingrese el codigo del articulo: ";
    cin >> producto.codigo;

    while(producto.codigo != -1)
    {
        cout << "Ingrese la descripcion del articulo: ";
        getline(cin>>ws, producto.descripcion);
        cout << "Ingrese el precio del articulo: ";
        cin >> producto.precio;
        cout << "Ingrese el stock del articulo: ";
        cin >> producto.stock;

        inicio = insertarOrdenado(inicio, producto);

        cout << "Ingrese el codigo del producto: ";
        cin >> producto.codigo;
    }

    Menu(inicio);

    return 0;
}