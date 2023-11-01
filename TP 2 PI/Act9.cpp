#include <iostream>
#include <string>
using namespace std;

// Función
void invertirDigitos(int arreglo_num[], int dim_log)
{
    int inicio = 0;
    int final = dim_log - 1;

    while(inicio < final)
    {
        int temporal = arreglo_num[inicio];
        arreglo_num[inicio] = arreglo_num[final];
        arreglo_num[final] = temporal;

        inicio++;
        final--;
    }
}

int main()
{
    int dim_log;
    cout << "Ingrese la dimension logica del arreglo: ";
    cin >> dim_log;

    if(dim_log <= 0)
    {
        cout << "La dimensión logica debe ser mayor a 0." << endl;
        main();
    }



    int arreglo[dim_log];
    cout << "Ingrese los elementos del arreglo: " << endl;
    for(int i = 0; i < dim_log; i++)
    {
        cout << "Número " << i + 1 << ": ";
        cin >> arreglo[i];
    }



    invertirDigitos(arreglo, dim_log);



    cout << "Arreglo invertido: ";
    for(int i = 0; i < dim_log; i++)
    {
        cout << arreglo[i] << " - ";
    }

    return 0;
}