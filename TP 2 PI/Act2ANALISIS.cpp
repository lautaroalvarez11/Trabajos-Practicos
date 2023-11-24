/*
¿Qué salida produce el siguiente código?
*/

#include <iostream>
#include <string>
using namespace std;

int i, arreglo[10];

    for(i = 0; i < 10; i++)
    {
        arreglo[i] = 2*i;
    }
    for(i = 0; i < 10; i++)
    {
        cout << arreglo[i] << " ";
        cout << endl;
    }

    for(i = 0; i <= 10; i = i + 2)
    {
        cout << arreglo[i] << " ";
    }
/*
Este código tiene como salida:
Primer for: A cada elemento del arreglo lo multiplica por 2 => 0,2,4,6,8,10,12,14,16,18

Segundo for: Imprime cada valor del arreglo por linea

Tercer for: Después de cada iteración, el valor de i se incrementa en 2 =>  0,2,4,6,8,10
*/