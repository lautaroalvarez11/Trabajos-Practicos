#include <iostream>
#include <string>
using namespace std;

const int dimension = 5;

void mas_uno(int arreglo[], int dimension)
{
    for(int i = 0; i < dimension; i++)
    {
        arreglo[i]++;
    }
}

int main()
{
    int mi_arreglo[dimension] = {1, 2, 3, 4, 5};

    mas_uno(mi_arreglo, dimension);

    for (int i = 0; i < dimension; i++)
    {
        cout << mi_arreglo[i] << " ";
    }

    return 0;
}