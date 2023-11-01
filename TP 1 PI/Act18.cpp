#include <iostream>
#include <string>
using namespace std;

// Función bisiesto
bool esBisiesto(int año) 
{
    return (año % 4 == 0);
}

int main() 
{
    int año, diasTranscurridos;
    cout << "Ingrese el año: ";
    cin >> año;
    cout << "Ingrese la cantidad de dias transcurridos: ";
    cin >> diasTranscurridos;

    int DiasQueTieneElMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (esBisiesto(año)) 
    {
        DiasQueTieneElMes[1] = 29;  // Febrero tiene 29 días en años bisiestos
        cout << "Es bisiesto" << endl;
    }

    int mes = 0;
    while (diasTranscurridos > DiasQueTieneElMes[mes]) 
    {
        diasTranscurridos -= DiasQueTieneElMes[mes];
        mes++;
    }

    cout << "Los dias transcurridos corresponden al: " << diasTranscurridos << "/" << mes + 1 << "/" << año << endl;

    return 0;
}