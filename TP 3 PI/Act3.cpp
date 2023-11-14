#include <iostream>
#include <string>
using namespace std;

int main()
{
    char *x = new char; // La variable del puntero x se declara en la memoria heap
    char *z = x; // El puntero z tiene la misma dirección de memoria que el puntero x

    //A
    *x = 'M'; // Al puntero x se le asigna la letra M

    //B
    cout << *x; // M

    //C
    *z = 'P'; // Al puntero z se le asigna la letra P

    //D
    cout << *z << " " << *x;
    // El puntero z va a imprimir el valor P y el puntero x tambien porque al declarar los punteros, z se modifica si x se modifica

    //E
    delete x;
    x = nullptr;
    /*
    Esto libera la memoria apuntada por x.
    Sin embargo, z todavía apunta a la misma dirección de memoria que fue liberada.
    Si se quiere imprimir *z después de eliminar el dato apuntado por x, se obtiene un comportamiento indefinido.
    No se puede acceder de manera segura a la memoria liberada. Puede imprimir un carácter aleatorio o un error en ejecución.
    */

   //F
   x = new char; // Se asigna a la variable x en la memoria heap

   //G
   cin >> *x; // Se almacena en la dirección de memoria de la variable x

   //H
   if (*x == '*') // Si el valor de la dirección de memoria de la variable x es igual a *
   {
        cout << "Asterisco";
   }
   
    return 0;
}