#include <iostream>
#include <string>
using namespace std;

int main()
{
    int matriz1[4][4];
    int matriz2[4][4];
    int matrizResultado[4][4];

    cout << "Introduce los elementos de la primera matriz 4x4:" << endl;
    for (int fila = 0; fila < 4; fila++)
    {
        for (int columna = 0; columna < 4; columna++)
        {
            cin >> matriz1[fila][columna];
        }
    }

     cout << "Introduce los elementos de la segunda matriz 4x4:" << endl;
    for (int fila = 0; fila < 4; fila++)
    {
        for (int columna = 0; columna < 4; columna++)
        {
            cin >> matriz1[fila][columna];
        }
    }

    // Calcular la matriz resultado
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    cout << "La matriz resultante de la suma es:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrizResultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}