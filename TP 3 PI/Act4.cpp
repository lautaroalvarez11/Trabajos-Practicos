#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    string descripcion;
    float precio;
};

struct Venta
{
    Producto producto;
    int cantidad;
};


int main()
{
// A- Declarar una variable puntero a Venta y reservar memoria.
    Venta* ventaPtr = new Venta;

// B- Pedir al usuario que ingrese una cantidad vendida, descripción de producto y precio de producto,
// almacenando los datos en la Venta apuntada por el puntero declarado en el inciso anterior.
    ventaPtr -> producto.descripcion = "Yerba";
    ventaPtr -> producto.precio = 1000;
    ventaPtr -> cantidad = 2;

// C- Restar un 15% al precio del Producto guardado en la Venta apuntada por el puntero.
    float descuento = ventaPtr -> producto.precio * 0.15;
    ventaPtr -> producto.precio -= descuento;

// D- Imprimir la descripción del producto dentro de la Venta y monto total (precio del producto * cantidad)
    cout << "Descripcion: " << ventaPtr -> producto.descripcion << endl;
    cout << "Monto total: " << ventaPtr -> producto.precio * ventaPtr -> cantidad;

    delete ventaPtr;

    return 0;
}