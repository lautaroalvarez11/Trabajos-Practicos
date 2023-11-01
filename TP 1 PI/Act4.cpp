#include <iostream>
#include <string>
using namespace std;

int main()
{
    float segundos;
    cout << "Ingrese los segundos que desee: " << endl;
    cin >> segundos;

    float horas = segundos / 3600;
        cout << "Su equivalente en horas es: " << horas << endl;

    float minutos;
        minutos = horas * 60;
        cout << "Su equivalente en minutos es: " << minutos << endl;

    cout << "el tiempo total es: " << horas << " hr - " << minutos << " min - " << segundos << " seg" << endl;

    return 0;
}