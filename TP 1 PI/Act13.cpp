#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;
    cout << "Ingrese una frase: ";
    getline(cin,cadena);

    if(cadena.empty()) //Ver si la cadena esta vacia
    {
        cout << "La cadena está vacía.";
    } else
    {
        cadena[0] = toupper(cadena[0]); // Convertir el primer caracter a mayuscula

        for(int i = 1; i < cadena.length(); i++) // Recorrer la cadena
        {
            cadena[i] = tolower(cadena[i]); // Convertir a minuscula los demas caracteres
        }
    }    
 
    cout << "Cadena convertida: " << cadena;

    return 0;
}