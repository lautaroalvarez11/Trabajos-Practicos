#include <iostream>
#include <string>
using namespace std;

bool coordenadas(int x, int y)
{
    if(y == (3*x)+2)
    {
        return true;
    } else
    {
        return false;
    }
}

int main()
{

    int x, y;

    cout << "Ingrese el valor x: ";
    cin >> x;

    cout << "Ingrese el valor de y: ";
    cin >> y;

    bool pertenece = coordenadas(x, y);

    if (pertenece) 
    {
        cout << "El punto (" << x << ", " << y << ") pertenece a la recta Y = 3X + 2." << endl;
    } else {
        cout << "El punto (" << x << ", " << y << ") no pertenece a la recta Y = 3X + 2." << endl;
    }


    return 0;
}