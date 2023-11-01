#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declarar un arreglo bidimensional de tipo float de 7 filas y 10 columnas.
    float arreglo[7][10];

// A

    // Asignar el valor 105 a la posición en la segunda fila (fila 1) y quinta columna (columna 4).
    arreglo[1][4] = 105.0;

    // Imprimir el valor asignado para verificar.
    cout << "El valor en la segunda fila, quinta columna es: " << arreglo[1][4] << endl;

// B

    // Asignar 1.5 a todas las posiciones de la cuarta fila (fila con índice 3)
    for (int columna = 0; columna < 10; columna++)
    {
        arreglo[3][columna] = 1.5;
    }

    // Imprimir el arreglo para verificar los valores asignados
    for (int fila = 0; fila < 7; fila++)
    {
        for (int columna = 0; columna < 10; columna++)
        {
            cout << arreglo[fila][columna] << " ";
        }
        cout << endl;
    }

// C

    // Previamente inicializar el arreglo con valores
    // Ejemplo: float matriz[1][10] = { {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0} };
    // Recorrer la matriz e imprimir los valores
    for (int fila = 0; fila < 7; fila++)
    {
        for (int columna = 0; columna < 10; columna++)
        {
            cout << arreglo[fila][columna] << " ";
        }
        cout << endl; // Cambiar de línea después de cada fila
    }

// D

    // Intercambiar las columnas 3 y 5
    for (int i = 0; i < 7; ++i)
    {
        // Guardar el valor de la columna 3
        float temporal = arreglo[i][2];
        
        // Copiar el valor de la columna 5 en la columna 3
        arreglo[i][2] = arreglo[i][4];
        
        // Copiar el valor temporal en la columna 5
        arreglo[i][4] = temporal;
    }

    // Imprimir el arreglo después de la permutación
    cout << "Arreglo después de la permutación:" << endl;
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << arreglo[i][j] << "  ";
        }
        cout << endl;
    }

// E

    // Sumar todos los elementos de las filas 2 y 6
    float suma_filas_2_y_6 = 0.0;

    for (int columna = 0; columna < 10; columna++)
    {
        suma_filas_2_y_6 += arreglo[1][columna]; // Sumar elementos de la fila 2
        suma_filas_2_y_6 += arreglo[5][columna]; // Sumar elementos de la fila 6
    }

    // Imprimir el resultado
    cout << "La suma de los elementos de las filas 2 y 6 es: " << suma_filas_2_y_6 << endl;

// F

     // Imprimir la tercera columna (columna con índice 2)
    for (int fila = 0; fila < 7; fila++)
    {
        cout << arreglo[fila][2] << endl;
    }

// G

    const int filas = 7;
    const int columnas = 10;
    float matriz[filas][columnas];
    // Rellenar la matriz con valores

    // Inicializar el mayor elemento con el primer elemento de la matriz
    float mayor = matriz[0][0];
    int fila_mayor = 0;
    int columna_mayor = 0;

    // Recorrer la matriz para encontrar el mayor elemento y sus índices
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            if (matriz[fila][columna] > mayor)
            {
                mayor = matriz[fila][columna];
                fila_mayor = fila;
                columna_mayor = columna;
            }
        }
    }

    // Imprimir el resultado
    cout << "El mayor elemento se encuentra en la fila " << fila_mayor << " y columna " << columna_mayor << "." << endl;

    return 0;
}
