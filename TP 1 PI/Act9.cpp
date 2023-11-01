#include <iostream>
#include <string>
using namespace std;

int main()
{

    char caracter;
    do
    {
        cout << "Ingrese un caracter: ";
        cin >> caracter;

        if (caracter == 's')
        {
            cout << "Usted eligió SI";
        } else if(caracter == 'n')
        {
            cout << "Usted eligió NO";
        }
        
    } while(caracter != 's' && caracter != 'n');
    
    
    
    
    return 0;
}