/*
Una matriz cuadrada A se dice que es simétrica si A(i,j) = A(j,i) para todo i, j.
Escribir un programa que decida si una matriz de 3 x 3 dada es o no simétrica.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int matriz[3][3];

    // Llenar la matriz
    cout << "Introduce los elementos de la matriz de 3x3:" << endl;
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            cin >> matriz[fila][columna];
        }
    }

     // Comprobar si la matriz es simétrica
    bool esSimetrica = true;
    for (int FILA = 0; FILA < 3; FILA++)
    {
        for (int COLUMNA = 0; COLUMNA < 3; COLUMNA++)
        {
            if (matriz[FILA][COLUMNA] != matriz[COLUMNA][FILA])
            {
                esSimetrica = false;
                break;
            }
        }
        if (esSimetrica == false)
        {
            break;
        }
    }

     // Mostrar el resultado
    if (esSimetrica)
    {
        cout << "La matriz es simetrica." << endl;
    } else
    {
        cout << "La matriz no es simetrica." << endl;
    }

    return 0;
}