#include <iostream>
#include <string>
using namespace std;

int main()
{
    int dia, mes, año;

    cout << "Ingrese un año: ";
    cin >> año;
    while((año <= 1000) || (año >= 9999))
    {
        cout << "Ingrese un año correctamente.";
        cin >> año;
        main();
    }

    cout << "Ingrese un mes: ";
    cin >> mes;
    while((mes <= 0) || (mes >= 13))
    {
        cout << "Ingrese un mes correctamente.";
        cin >> mes;
        main();
    }

    cout << "Ingrese un dia: ";
    cin >> dia;
    while((dia <= 0) || (dia >= 32))
    {
        cout << "Ingrese un dia correctamente.";
        cin >> dia;
        main();
    }

    cout << dia << "/" << mes << "/" << año;

    return 0;
}