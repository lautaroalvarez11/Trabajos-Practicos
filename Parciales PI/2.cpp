#include <iostream>
#include <string>
using namespace std;

// ACT 1 Analizar función
void funcion(int arreglo[], int &dl)
{
    int i = 0;
    while(i < dl)
    {
        if(arreglo[i] % 2 != 0)
        {
            for(int j = i; j < dl; j++)
            {
                arreglo[j] = arreglo[j+1];
            }
            dl--;
        } else
        {
            i++;
        }
    }
}

int main()
{
    int num[] = {5,4,3,1,12,6,7,8,9,14};
    int dl = 10;

    funcion(num, dl);

    for(int i = 0; i < dl; i++)
    {
        cout << num[i] << endl;
    }

    return 0;
}

/*
Lo que hace esta función es eliminar los números impares fijandose si el resto
de dividir cada numero es igual a 0, si no lo es, lo elimina y en su lugar
se lo reemplaza por el siguiente numero, a su vez que se decrementa la dimensión lógica.
Va a mostrar por pantalla: 4,12,6,8,14
*/


// Act 2 Analizar código
void hacer_calculo(int &x, int y, int &z)
{
    cout << x << " " << y << " " << z << endl;
    x = 1;
    y = 2;
    z = 3;
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;
    hacer_calculo(a, b, c);
    cout << a << " " << b << " " << c;
    return 0;
}

/*
Va a mostrar por pantalla:
10 20 30
1 2 3
1 20 3
*/