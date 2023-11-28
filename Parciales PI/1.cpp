#include <iostream>
#include <string>
using namespace std;

/*
1) Analizar que hace el código y ver que se imprime por pantalla:

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
        }
	else
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

QUE HACE Y QUE IMPRIME:
Lo que hace esta función es eliminar los números impares fijandose si el resto
de dividir cada numero es igual a 0, si no lo es, lo elimina y en su lugar
se lo reemplaza por el siguiente numero, a su vez que se decrementa la dimensión lógica
Imprime 4,12,6,8,14

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2) Analizar el código e indicar que se imprime por pantalla:

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

SE IMPRIME:
10 20 30
1 2 3
1 20 3

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

3) Realizar código:

const int MaximoProductos = 1000;

struct Comercio
{
	int ID;
	string Rubro;
	string Descripcion;
	float Precio;
	int stockActual;
	int stockMinimo;
};

void Informe(Comercio arreglo[MaximoProductos], int dimensionLogica)
{
	for(int i = 0; i < dimensionLogica - 1; i++)
	{
		if(arreglo[i].stockActual < arreglo[i].stockMinimo)
		{
			cout << "ID: " << arreglo[i].ID << endl;
			cout << "Descripcion: " << arreglo[i].Descripcion << endl;
		}
	}
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

4) Realizar código:

int matriz[2][3];

a-
matriz[1][0] = 105;

b-
matriz[1][1] = 42;

c-
for(int i = 0; i < 3; i++)
{
	matriz[0][i] = 42;
}

d-
for(int i = 0; i < 2; i++)
{
	matriz[i][2] = 78;
}
*/