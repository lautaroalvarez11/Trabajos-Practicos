#include <iostream>
using namespace std;

int main()
{
    int *p1, *p2; // Se declaran dos punteros

    p1 = new int; // Ambas variables de los punteros se declaran en la memoria heap
    p2 = new int;

    *p1 = 10; // Al puntero p1 se le asigna la dirección de memoria que almacena el valor 10 
    *p2 = 20; // Al puntero p2 se le asigna la dirección de memoria que almacena el valor 20

    cout << *p1 << " " << *p2 << endl; // 10  20

    *p1 = *p2; // Al puntero p1 se le asigna la dirección de memoria del puntero p2, entonces *p1 = 20

    cout << *p1 << " " << *p2 << endl; // 20  20

    *p2 = 30; // Al puntero p2 se le modifica la dirección de memoria y ahora almacena el valor 30

    cout << *p1 << " " << *p2 << endl; // 20  30
    return 0;
}