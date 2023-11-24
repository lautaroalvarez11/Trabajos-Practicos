/*
Identificar los errores, si los hay, de las siguientes declaraciones de arreglos.
Para aquellos que son correctos especificar: la cantidad de elementos ocupados y los valores almacenados.
*/

#include <iostream>
#include <string>
using namespace std;

int a[4] = {8, 7, 6, 4, 3};
// Mal: El arreglo es de dimensión física 4 y se lo inicializó con 5

int b[] = {8, 7, 6, 4};
// Bien: No se declaró la dimensión física pero se lo inicializó con 4, la dimensión lógica es 4

const int MAX = 4; 
int c[MAX];
// Bien: Se declaró un arreglo c con dimensión física 4 porque se utiliza la constante MAX

int d[5];
// Bien: Se declaró un arreglo d con dimensión física 5