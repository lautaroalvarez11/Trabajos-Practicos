#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;
    cout << "Ingrese una frase: ";
    getline(cin, cadena); //Leer la frase ingresada

    int longitudUltimaPalabra = 0;
    int tamañoCadena = cadena.length();

    for(int i = 0; i < tamañoCadena; i++)
    {
        if(cadena[i] == ' ')
            longitudUltimaPalabra = 0;
        else longitudUltimaPalabra++;
    }

    cout << "La longitud de la ultima palabra es: " << longitudUltimaPalabra;

    return 0;
}