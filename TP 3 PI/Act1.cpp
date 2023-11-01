#include <iostream>
using namespace std;

int main()
{
    int *p1, *p2; // Se declaran dos punteros de tipo int

    p1 = new int; // La variable del puntero p1 se la asigna en la memoria heap
    *p1 = 42; // Y al valor del puntero se le asigna el valor 42

    p2 = p1; // La variable p2 apunta a la misma dirección que p1, entonces p2 vale 42

    cout << *p1 << endl;
    cout << *p2 << endl; // A.Luego de ejecutar esta línea

    *p2 = 53; // Como p2 apuntaba a la misma dirección que p1, ambos se modifican y ahora ambos apuntan a 53

    cout << *p1 << endl;
    cout << *p2 << endl; //B. Luego de ejecutar esta línea
    
    p1 = new int; // La variable del puntero p1 se la asigna nuevamente en la memoria heap
    *p1 = 88; // Pero el valor del puntero p1 ahora es 88
    // Como al puntero p2 no se le hizo ninguna modificación, sigue manteniendo su valor 53
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << "FIN"; //C. Luego de ejecutar esta línea
    return 0;
}

/*
A:
*p1: 42
*p2: 42

B:
*p1: 53
*p2: 53

C:
*p1: 88
*p2: 53
*/