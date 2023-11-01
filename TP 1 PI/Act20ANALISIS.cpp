#include <iostream>
#include <string>
using namespace std;

// CASO 1)
void primeraFuncion(int x)
{
    x = x+8;
    cout << "Valor de x luego de la primera función:" << x << endl;
}

void segundaFuncion(int &x)
{
    x = x+5;
    primeraFuncion(x);
    cout << "Valor de x luego de la segunda función:" << x << endl;
}

int main()
{
    int x = 2;
    segundaFuncion(x);
    return 0;
}
/*
La primera función imprime 10 porque a 8 le suma 2 y lo guarda en x
La segunda función primero imprime 7 porque a 5 le suma 2 y lo guarda en x,
pero al llamar la primera función y pasarle parámetro por referencia,
se vuelve a la primera función y en el lugar de la x se sustituye por 7
que es el valor de x de la segunda función, por lo tanto la primera función
imprimirá el valor 15 y la segunda función imprimirá el valor 7
*/

// CASO 2)
void funcion(int a, int &y, int &z)
{
    int b = 1;
    y = y + 1;
    z = z + a;
    b = 4;
}

int main()
{
    int a = 2;
    int b = 3;
    funcion(a+b, a, a);
    cout << "Variable a:" << a << endl;
    cout << "Variable b:" << b << endl;
    return 0;
}

// ¿Qué cambiaría si en la función se reemplazara el nombre del parámetro a por el nombre x? Es decir:
void funcion(int x, int &y, int &z)
{
    int b = 1;
    y = y + 1;
    z = z + x;
    b = 4;
}

/*
Parametros: En la función el parametro a es 5 porque es la suma de la variable a y b,
los parametros z e y son 2 porque cuando se invoca la funcion se dice que en ese lugar
se utiliza el valor de a

Entonces la funcion funciona de la siguiente manera:
z = z + a -> a = a + (2+3) -> a = 2 + 5 -> a = 7
y = y + 1 -> a = a + 1 -> a = 7 + 1 -> a = 8
Esto sucede porque al pasarse los parametros por referencia, el 7 de la primera a
se utiliza tambien en el parametro y

Por lo tanto el valor de la variable a es 8 y el valor de la variable b es 3 porque
no se opera sobre la variable b

Si en la funcion se cambia el parametro a por x pero en la invocación se utiliza como parametro a,
no modifica en absoluto el código porque el parametro x es local, es decir se reemplaza por el valor
que le demos en la invocación de la funcion
*/


// CASO 3)
int sumatoriaPares(int numero)
{
    int suma = 0;
    while (numero != 0)
    {
        if ((numero % 10) % 2 == 0)
        {
        suma += numero % 10;
        }
        numero = numero / 10;
    }
    return suma;
}

void alterarNumero(int a, int &b, int c)
{
    a = sumatoriaPares(c);
    b = a;
}

int main()
{
    int i = 4;
    int numero = 90210;
    alterarNumero(i, numero, sumatoriaPares(numero));
    cout << "Numero: " << numero << endl;
    cout << "Variable i: " << i << endl;
    return 0;
}

/*
La función sumatoriaPares(numero):
numero % 10: Esta expresión calcula el último dígito del número de la variable numero.
El operador % calcula el resto de la división de la variable numero entre 10.
En este caso el numero es 90210, entonces numero % 10 sería igual a 0,
ya que 90210 dividido por 10 da como resultado 9021 con resto 0.

(numero % 10) % 2 == 0: Esta parte verifica si el último dígito es par.
Para hacerlo, calcula el resto de la división del último dígito entre 2 y
verifica si ese resto es igual a 0. Si es igual a 0, significa que el dígito es par,
y si no, no se suma a la variable suma.

suma += numero % 10: Si el último dígito es par, se agrega su valor a la variable suma.
El operador += se utiliza para acumular el valor en suma. Entonces, si el último dígito es par,
se suma a la variable suma, y si no es par, no se suma nada.

----------------------------------------------------------------------------------------------------------

La función alterarNumero:
a se establece en 2 (el resultado de sumatoriaPares(numero)),
pero esto no afecta a i en main.

----------------------------------------------------------------------------------------------------------

Luego, b se establece en 2 por el parametro por referencia, lo que modifica la variable numero en main.

Por lo tanto, al final, cuando se imprime numero, muestra 2 (ya que ha sido modificado por alterarNumero),
y cuando se imprime i, muestra 4 (ya que no ha sido modificado por alterarNumero).
*/