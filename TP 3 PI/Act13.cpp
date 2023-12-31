#include <iostream>
#include <string>
using namespace std;

struct Venta
{
    int codigoProducto;
    int cantidadVendida;
};

struct Nodo
{
    Venta producto;
    Nodo* siguiente;
};

Nodo* insertarOrdenado(Nodo* inicio, Nodo* nuevaVenta) // nuevaVenta es para guardar las nuevas ventas de las sucursales
{   
    if(inicio == nullptr || nuevaVenta -> producto.codigoProducto < inicio -> producto.codigoProducto) // Si la lista está vacía o el codigo del nodo nuevaVenta debe ir al principio porque es menor que el primer codigo de la lista.
    {
        nuevaVenta -> siguiente = inicio; // El nodo nuevaVenta apunta al nodo actual en el inicio.
        inicio = nuevaVenta; // Se actualiza el inicio de la lista para que el nodo nuevaVenta sea el nuevo inicio.
    }
    else
    {
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que empieza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> producto.codigoProducto < nuevaVenta -> producto.codigoProducto) // Mientras la lista no esté vacía y el codigo del siguiente nuevo nodo es menor que el codigo del nodo nuevaVenta (Se busca la posición adecuada para insertar el nuevo codigo)
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor menor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el codigo de la nueva venta.
        nuevaVenta -> siguiente = auxiliar -> siguiente; // El nodo nuevaVenta apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevaVenta; // El anterior (auxiliar) apuntará al nodo nuevaVenta;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nodo nuevaVenta se insertó al inicio
}

Nodo* unirListas(Nodo* listaSucursal1, Nodo* listaSucursal2, Nodo* lista3)
{
    Nodo* auxiliar1 = listaSucursal1; // Se utiliza un puntero auxiliar1 para recorrer la lista1
    Nodo* auxiliar2 = listaSucursal2; // Se utiliza un puntero auxiliar2 para recorrer la lista2
    Nodo* auxiliar3 = lista3; // Se utiliza un puntero auxiliar3 para ir guardando los datos en la lista3

    while (auxiliar1 != nullptr) // Mientras la lista1 no se termine
    {
        Nodo* nuevo1 = new Nodo; // Crear un nuevo nodo para evitar problemas con el mismo nodo en ambas listas
        nuevo1 -> producto = auxiliar1 -> producto; // Copiar los datos del nodo actual de lista1 al nuevo nodo
        nuevo1 -> siguiente = nullptr; // Para indicar que se copiaron todos los elementos de la lista1

        auxiliar3 = insertarOrdenado(auxiliar3, nuevo1); // Insertar los datos de la lista1 en la lista3
        auxiliar1 = auxiliar1 -> siguiente; // Ir recorriendo los nodos
    }

    while (auxiliar2 != nullptr)
    {
        Nodo* nuevo2 = new Nodo; // Crear un nuevo nodo para evitar problemas con el mismo nodo en ambas listas
        nuevo2 -> producto = auxiliar2 -> producto; // Copiar los datos del nodo actual de lista2 al nuevo nodo
        nuevo2 -> siguiente = nullptr; // Para indicar que se copiaron todos los elementos de la lista1

        auxiliar3 = insertarOrdenado(auxiliar3, nuevo2); // Insertar los datos de la lista2 en la lista3
        auxiliar2 = auxiliar2 -> siguiente; // Ir recorriendo los nodos
    }

    return auxiliar3; // Retorna la lista3
}

void mostrarLista1(Nodo* inicio)
{
    cout << "LISTA DE PRODUCTOS VENDIDOS SUCURSAL 1:" << endl;
    for (Nodo* auxiliar = inicio ; auxiliar != nullptr ; auxiliar = auxiliar -> siguiente)
    {
        cout << "Codigo de producto: " << auxiliar -> producto.codigoProducto << endl;
        cout << "Cantidad vendida: " << auxiliar -> producto.cantidadVendida << endl;
        cout << "----------------------------" << endl;
    }
    cout << endl;
}

void mostrarLista2(Nodo* inicio)
{
    cout << "LISTA DE PRODUCTOS VENDIDOS SUCURSAL 2:" << endl;
    for (Nodo* auxiliar = inicio ; auxiliar != nullptr ; auxiliar = auxiliar -> siguiente)
    {
        cout << "Codigo de producto: " << auxiliar -> producto.codigoProducto << endl;
        cout << "Cantidad vendida: " << auxiliar -> producto.cantidadVendida << endl;
        cout << "----------------------------" << endl;
    }
    cout << endl;
}

void mostrarLista3(Nodo* inicio)
{
    cout << "LISTA DE PRODUCTOS VENDIDOS EN AMBAS SUCURSALES:" << endl;
    for (Nodo* auxiliar = inicio ; auxiliar != nullptr ; auxiliar = auxiliar -> siguiente)
    {
        cout << "Codigo de producto: " << auxiliar -> producto.codigoProducto << endl;
        cout << "Cantidad vendida: " << auxiliar -> producto.cantidadVendida << endl;
        cout << "----------------------------" << endl;
    }
    cout << endl;
}

int main()
{
    Nodo* inicio1 = new Nodo;
    inicio1 = nullptr;

    Nodo* inicio2 = new Nodo;
    inicio2 = nullptr;

    Nodo* inicio3 = new Nodo;
    inicio3 = nullptr;

    int codigo1, cantidadVendida1;
    cout << "Ingrese el codigo del producto de la lista de la sucursal 1 (-1 para cortar): ";
    cin >> codigo1;

    while(codigo1 != -1)
    {
        cout << "Ingrese la cantidad de productos vendidos en la sucursal 1: ";
        cin >> cantidadVendida1;

        Nodo* nuevo = new Nodo;
        nuevo -> producto.codigoProducto = codigo1;
        nuevo -> producto.cantidadVendida = cantidadVendida1;
        nuevo -> siguiente = nullptr;

        inicio1 = insertarOrdenado(inicio1, nuevo);
        cout << "Ingrese el codigo del producto de la lista de la sucursal 1 (-1 para cortar): ";
        cin >> codigo1;
    }

    int codigo2, cantidadVendida2;
    cout << "Ingrese el codigo del producto de la lista de la sucursal 2 (-1 para cortar): ";
    cin >> codigo1;

    while(codigo2 != -1)
    {
        cout << "Ingrese la cantidad de productos vendidos en la sucursal 2: ";
        cin >> cantidadVendida2;

        Nodo* nuevo = new Nodo;
        nuevo -> producto.codigoProducto = codigo2;
        nuevo -> producto.cantidadVendida = cantidadVendida2;
        nuevo -> siguiente = nullptr;

        inicio2 = insertarOrdenado(inicio2, nuevo);
        cout << "Ingrese el codigo del producto de la lista de la sucursal 2 (-1 para cortar): ";
        cin >> codigo2;
    }

    mostrarLista1(inicio1);
    mostrarLista2(inicio2);
    cout << endl;
    
    inicio3 = unirListas(inicio1, inicio2, inicio3);
    mostrarLista3(inicio3);

    return 0;
}