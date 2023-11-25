/*
¿Qué salidas producirá el siguiente código?
*/

#include <iostream>
#include <string>
using namespace std;

struct TipoZapato
{
    string estilo;
    double precio;
};

int main()
{
    TipoZapato zapato1, zapato2; // Declara dos variables de tipo 'TipoZapato' que es el struct
    zapato1.estilo = "Sandalia"; // En la variable zapato1 en el campo estilo del struct se almacena "Sandalia"
    zapato1.precio = 9.99; // En la variable zapato1 en el campo precio del struct se almacena "9.99"
    cout << zapato1.estilo << " $" << zapato1.precio << endl; // Se imprime: "Sandalia $9.99"
    zapato2 = zapato1; // En la variable zapato2 se almacena los mismos valores que la variable zapato1, es decir, en zapato2 tambien se almacena "Sandalia" y "9.99"
    zapato2.precio = zapato2.precio / 9; // Pero al precio "9.99" de la variable zapato2 se lo divide por 9
    cout << zapato2.estilo << " $" << zapato2.precio << endl; // Se imprime: "Sandalia $1.11"

    return 0;
}