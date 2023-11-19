// Escribir una función recursiva que calcule la suma de los cuadrados de los N primeros números positivos

#include <iostream>
#include <string>
using namespace std;

int sumarCuadrados(int a)
{
    // Casos base
    if(a == 0)
    {
        return 0;
    }
    // Caso recursivo
    else
    {
        return a * a + sumarCuadrados(a - 1);
    }
    
}

int main()
{
    int numero, sumaCuadrados;
    cout << "Ingrese un numero: ";
    cin >> numero;

    sumaCuadrados = sumarCuadrados(numero);
    cout << "La suma de los cuadrados de su numero es: " << sumaCuadrados;
    return 0;
}

/*
Como funciona este programa:
Ejemplo a = 2
1. a es distinto de 0 entonces entra al caso recursivo
2. Al 2 lo multiplica por si mismo (obtiene el cuadrado) y le suma recursivamente el cuadrado de su anterior
3. Volvio a entrar a la funcion pero ahora a vale 1

1. a es distinto de 0 entonces entra al caso recursivo
2. Al 1 lo multiplica por si mismo (obtiene el cuadrado) y le suma recursivamente el cuadrado de su anterior
3. Volvio a entrar a la funcion pero ahora a vale 0
4. Como a es igual a 0 sale de la funcion

Y el codigo queda de la siguiente manera:
a = 2 -> (2 * 2) + (1 * 1) = 5
*/