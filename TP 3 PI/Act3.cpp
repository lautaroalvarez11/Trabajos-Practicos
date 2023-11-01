#include <iostream>
#include <string>
using namespace std;

int main()
{
    char *x = new char;
    char *z = x;

    //A
    *x = 'M';

    //B
    cout << *x;

    //C
    *z = 'P';

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
   x = new char;

   //G
   cin >> *x;

   //H
   if (*x == '*')
   {
        cout << "Asterisco";
   }

    return 0;
}