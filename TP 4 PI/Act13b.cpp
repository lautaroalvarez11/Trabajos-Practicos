#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

/*
¿Qué debería cambiarse en la función anterior si se intentara obtener el resultado opuesto?
En el ejemplo de la lista con los números 6 - 2 - 8 - 1 se debería obtener el número 1.
Se asume que la lista no contiene valores mayores que 99.
*/

int funcion(Nodo* inicio, int m = 100)
{
    if (inicio == nullptr)
    {
        return m;
    }
    if (inicio -> dato < m)
    {
        m = inicio -> dato;
    }
    return funcion(inicio -> siguiente, m);
}

/*
Como funciona este programa:
La funcion busca el valor minimo en la lista. Toma como argumentos un puntero al inicio de la lista (inicio) y un valor m que inicia en 100 asumiendo que ningún valor en la lista será mayor que 99 (ya que se busca el número mínimo)
1. Se inicia con inicio apuntando al primer nodo de la lista y m inicializado en 100.
2. Para el primer nodo con dato 6:
    m (inicialmente 100) es mayor que el dato actual (6), entonces m se actualiza a 6
3. Para el segundo nodo con dato 2:
    m (actualmente 6) es mayor que el dato actual (2), entonces m se actualiza a 2
4. Para el tercer nodo con dato 8:
    m (actualmente 2) es menor que el dato actual (8), entonces m no se actualiza
5. Para el cuarto nodo con dato 1:
    m (actualmente 2) es mayor que el dato actual (1), entonces m se actualiza a 1
6. Finalmente, cuando la función alcanza el último nodo (nullptr), retorna el valor de m, que en este caso es 1, que es el valor mínimo encontrado en la lista
*/