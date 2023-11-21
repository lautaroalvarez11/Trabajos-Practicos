#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

/*
Analizar la siguiente función e indicar qué retorna si la lista pasada por parámetro contiene los siguientes elementos: 6 - 2 - 8 - 1.
*/

int funcion(Nodo* inicio, int m = -1)
{
    if (inicio == nullptr)
    {
        return m;
    }
    if (inicio -> dato > m)
    {
        m = inicio -> dato;
    }
    return funcion(inicio -> siguiente, m);
}

/*
Como funciona este programa:
La funcion busca el valor máximo en la lista. Toma como argumentos un puntero al inicio de la lista (inicio) y un valor m que inicia en -1
1. La función inicia con inicio apuntando al primer nodo de la lista y m inicializado en -1
2. Para el primer nodo con dato 6:
    m (inicialmente -1) es menor que el dato actual (6), entonces m se actualiza a 6
3. Para el segundo nodo con dato 2:
    m (actualmente 6) es mayor que el dato actual (2), entonces m no se actualiza
4. Para el tercer nodo con dato 8:
    m (actualmente 6) es menor que el dato actual (8), entonces m se actualiza a 8
5. Para el cuarto nodo con dato 1:
    m (actualmente 8) es mayor que el dato actual (1), entonces m no se actualiza
6. Finalmente, cuando la función alcanza el último nodo (nullptr), retorna el valor de m, que en este caso es 8, que es el valor maximo encontrado en la lista
*/