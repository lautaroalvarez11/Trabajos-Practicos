/*
Escribir una función llamada cantidad_ocurrencias que reciba como parámetro un arreglo de tipo int, un
parámetro con la dimensión lógica del arreglo y un parámetro con un valor de tipo int. La función debe retornar
la cantidad de ocurrencias del valor int encontradas en el arreglo.
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

// Función cantidad de ocurrencias
int cantidad_ocurrencias(int arreglo[], int dl, int numeroOcurrencias)
{
    int contador = 0;

    for(int i = 0; i < dl; i++)
    {
        if(arreglo[i] == numeroOcurrencias)
        {
            contador++;
        }
    }
    return contador;
}

int main() 
{

    int valor_a_buscar = 2;

    int A[MAX] = {2,8,5,2,2,7,2,7,4,2};
    int B[MAX];
    int C[MAX] = {2};
    int D[MAX] = {2,2,2};
    int E[MAX] = {1,3,5,7,9};

    const int dlA=10, dlB=0, dlC=1, dlD=3, dlE=5;

    int ocurrenciasA = cantidad_ocurrencias(A, dlA, valor_a_buscar);
    cout << "El valor " << valor_a_buscar << " aparece " << ocurrenciasA << " veces en el arreglo A." << endl;

    int ocurrenciasB = cantidad_ocurrencias(B, dlB, valor_a_buscar);
    cout << "El valor " << valor_a_buscar << " aparece " << ocurrenciasB << " veces en el arreglo B." << endl;

    int ocurrenciasC = cantidad_ocurrencias(C, dlC, valor_a_buscar);
    cout << "El valor " << valor_a_buscar << " aparece " << ocurrenciasC << " veces en el arreglo C." << endl;

    int ocurrenciasD = cantidad_ocurrencias(D, dlD, valor_a_buscar);
    cout << "El valor " << valor_a_buscar << " aparece " << ocurrenciasD << " veces en el arreglo D." << endl;

    int ocurrenciasE = cantidad_ocurrencias(E, dlE, valor_a_buscar);
    cout << "El valor " << valor_a_buscar << " aparece " << ocurrenciasE << " veces en el arreglo E." << endl;

    return 0;

}