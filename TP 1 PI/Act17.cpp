#include <iostream>
#include <string>
using namespace std;

int main()
{
    int año;
    cout << "Ingrese un año: ";
    cin >> año;

    while((año <= 1000) || (año >= 9999))
    {
        cout << "Ingrese un año correctamente." << endl;
        main();
    }

    if(año % 4 == 0)
    {
        cout << "El año es bisiesto";
    } else
    {
        cout << "El año no es bisiesto";
    }


    return 0;
}