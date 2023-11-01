// Lucas Cordova
// Joaquín Marcos
// Augusto Frontini
// Juan Pablo Nieto
// Lautaro Ezequiel Alvarez

#include <iostream>
#include <string>
using namespace std;

// Función encriptar
string encriptar(string texto1)
{
    string texto_encriptado = "";

    for(char letra : texto1)
    {
        if(isalpha(letra)) // Función para verificar que sea una letra, si lo es ejecuta el algoritmo, utilizamos esta función de una IA
        {
            char letraEncriptada = (toupper(letra) - 'A' + 10) % 26 + 'A'; // Algoritmo de desencriptación ROT10, devuelve 10 lugares posteriores a la letra ingresada
            texto_encriptado += letraEncriptada;
        } else
        {
            texto_encriptado += letra; // Agrega un caracter sin cambios cuando no sea una letra
        }
    }

    return texto_encriptado;
}

// Función desencriptar
string desencriptar(string texto1)
{
    string texto_desencriptado = "";

    for(char letra : texto1)
    {
        if(isalpha(letra))
        {
            char letraDesencriptada = (toupper(letra) - 'A' - 10 + 26) % 26 + 'A'; // // Algoritmo de desencriptación ROT10, devuelve 10 lugares anteriores a la letra ingresada, además se utilizó otra IA para poder darnos cuenta del encriptado inverso
            texto_desencriptado += letraDesencriptada;
        } else
        {
            texto_desencriptado += letra; // Agrega un caracter sin cambios cuando no sea una letra
        }
    }

    return texto_desencriptado;
}

int main()
{

// Menu
    char opciones;
    
    cout << "¡BIENVENIDO AL MENU!" << endl;

    cout << "A: Encriptar" << endl;
    cout << "B: Desencriptar" << endl;
    cout << "C: Salir" << endl;

    cout << "Elija una opcion: ";
    cin >> opciones;

    switch(opciones)
    {
        case 'a':
        case 'A':
        {
            string ingresar_texto1;
            cout << "Ingrese un texto a encriptar: ";
            cin.ignore();
            getline(cin, ingresar_texto1);

            cout << "Texto encriptado: " << encriptar(ingresar_texto1); // Llama a la función con los paramétros locales
            break;
        }

        case 'b':
        case 'B':
        {
            string ingresar_texto2;
            cout << "Ingrese un texto a desencriptar: ";
            cin.ignore();
            getline(cin, ingresar_texto2); // Para que cuente los espacios ingresados

            cout << "Texto desencriptado: " << desencriptar(ingresar_texto2); // Llama a la función con los paramétros locales
            break;
        }

        case 'c':
        case 'C':
        {
            break;
        }

        default: // Por si se ingresa una opcion no valida
        cout << "Ingrese una opcion valida." << endl;
        main();
    }



    return 0;
}