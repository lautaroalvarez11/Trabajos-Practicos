#include <iostream>
#include <string>
using namespace std;

int funcion(int m, int n)
{
    // Caso base
    if (n == 0)
    {
        return 0;
    }

    return m + funcion(m, n-1); // Caso recursivo
}

int main()
{
    cout << funcion(20, 3);
    return 0;
}

/*
El programa funciona de la siguiente manera:
1. funcion(20, 3) llama a funcion(20, 2) y devuelve 20 + funcion(20, 2).
2. funcion(20, 2) llama a funcion(20, 1) y devuelve 20 + funcion(20, 1).
3. funcion(20, 1) llama a funcion(20, 0) y devuelve 20 + funcion(20, 0).
4. funcion(20, 0) devuelve 0 según el caso base.

Entonces, funcion(20, 1) devuelve 20 + 0 = 20.
funcion(20, 2) devuelve 20 + 20 = 40.
Finalmente, funcion(20, 3) devuelve 20 + 40 = 60.
*/