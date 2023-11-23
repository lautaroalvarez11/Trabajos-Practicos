#include <iostream>
#include <string>
using namespace std;

int main()
{
    char letra1, letra2, letra3;

    cout << "Ingrese la primera letra: " << endl;
    cin >> letra1;

    while ((letra1 < 'a' || letra1 > 'z') && (letra1 < 'A' || letra1 > 'Z'))
    {
        cout << "Por favor ingrese una letra, intente nuevamente." << endl;
        cin >> letra1;
    }

    cout << "Ingrese la segunda letra: " << endl;
    cin >> letra2;

    while ((letra2 < 'a' || letra2 > 'z') && (letra2 < 'A' || letra2 > 'Z'))
    {
        cout << "Por favor ingrese una letra, intente nuevamente." << endl;
        cin >> letra2;
    }

    cout << "Ingrese la tercera letra: " << endl;
    cin >> letra3;

    while ((letra3 < 'a' || letra3 > 'z') && (letra3 < 'A' || letra3 > 'Z'))
    {
        cout << "Por favor ingrese una letra, intente nuevamente." << endl;
        cin >> letra3;
    }

    if (letra1 <= letra2 && letra1 <= letra3)
    {
        cout << "La letra que esta primera en el alfabeto es: " << letra1 << endl;

    } else if (letra2 <= letra1 && letra2 <= letra3)
    {
        cout << "La letra que esta primera en el alfabeto es: " << letra2 << endl;
    } else
    {
        cout << "La letra que esta primera en el alfabeto es: " << letra3 << endl;
    }

    return 0;
}