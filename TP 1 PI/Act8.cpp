#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    char caracteres;
    int contador_minusculas = 0;
    int contador_total = 0;
    int contador_vocales = 0;

    do
    {
        cout << "Ingrese caracteres: ";
        cin >> caracteres;
        contador_total++;

        if((caracteres == 'a') || (caracteres == 'e') || (caracteres == 'i') || (caracteres == 'o') || (caracteres == 'u'))
        {
            contador_vocales++;
        }

        if((caracteres >= 'a') || (caracteres <= 'z'))
        {
            contador_minusculas++;
        }
    } while(caracteres != 'n');

    cout << "La cantidad de vocales es: " << contador_vocales << endl;
    cout << "La cantidad total de minusculas es: " << contador_minusculas << endl;
    cout << "La cantidad total de caracteres es: " << contador_total << endl;;

    return 0;
}