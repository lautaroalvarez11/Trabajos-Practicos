/*
A pesar de que el programa a continuación no tiene errores de sintaxis, sí tiene varios otros problemas.
¿Cuáles son? ¿Cómo podrían corregirse?
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

int cargar(float arreglo[], int dl)
{
    for (int i = 0; i < MAX; i++)
    {
        cout << "Número para almacenar: ";
        cin >> arreglo[i];
    }
    return dl;
}

int main()
{
    float numeros[MAX];
    int cantidad = 0;
    cargar(numeros, cantidad);
}

/*
Problemas:
1- Falta el "return 0" en la función principal por lo tanto nunca va a retornar nada el programa.

2- En la función "cargar" se recorre hasta "MAX" elementos pero el parametro "dl" no se utiliza
en el bucle ni se actualiza en ningun lugar del código. Por lo tanto no se controla la cantidad
real de elementos que se cargan en el arreglo.

3- En la función principal se utiliza "cantidad" como argumento de la función "cargar" pero el
problema está en que se inicializa con 0 y nunca se actualiza en ningun lugar del código, esto
significa que la función "cargar" nunca sabe cuantos elementos se cargaron en el arreglo "numeros"
*/