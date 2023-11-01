#include <iostream>
#include <string>
using namespace std;

int main()
{

    int arreglo[20]; // arreglo de tamaño 20
    int numero_ingresado;

    cout << "Ingrese 20 numeros enteros en orden ascendente:" << endl;

    for (int i = 0; i < 20; i++) {
        cin >> arreglo[i]; // Leer el número ingresado por el usuario y guardarlo en el arreglo
    }

    cout << "El arreglo ingresado es:" << endl;

    for (int i = 0; i < 20; i++) {
        cout << arreglo[i] << " "; // Mostrar el arreglo en el mismo orden en que se ingresó
    }
    return 0;
}