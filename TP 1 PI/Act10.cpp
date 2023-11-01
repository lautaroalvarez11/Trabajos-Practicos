#include <iostream>
#include <string>
using namespace std;

// FUNCION A
    int InvertirDigitos(int numero)
    {
        int numero_invertido = 0;

        while(numero != 0)
        {
            int digito = numero % 10; // Obtener el ultimo digito
            numero_invertido = numero_invertido * 10 + digito;
            numero /= 10; // Eliminar el ultimo digito
        }

        return numero_invertido;
    }

// FUNCION B

    int SumarDigitos(int numero1, int numero2)
    {
        int numero_sumado = 0;

        numero_sumado = numero1 + numero2;

        return numero_sumado;
    }

int main()
{
    
    char opciones;
    
    cout << "¡BIENVENIDO AL MENU!" << endl;

    cout << "A: Invertir numero" << endl;
    cout << "B: Sumatoria de digitos" << endl;
    cout << "C: Decir si son multiplos" << endl;
    cout << "D: Volver al menu" << endl;


    cout << "Elija una opcion: ";
    cin >> opciones;


    switch(opciones)
    {
        case 'a':
        case 'A':
        {
            int numero;
            cout << "Ingrese un numero: ";
            cin >> numero;

            int numero_invertido = InvertirDigitos(numero);
            cout << "El numero invertido es: " << numero_invertido;
            break;
        }

        case 'b':
        case 'B':
        {
            int numero1, numero2;
            cout << "Ingrese el primer numero: ";
            cin >> numero1;

            cout << "Ingrese el segundo numero: ";
            cin >> numero2;

            int numero_sumado = SumarDigitos(numero1, numero2);
            cout << "La suma es: " << numero_sumado;
            break;
        }

        case 'c':
        case 'C':
        {
            int numero1, numero2;
            cout << "Ingrese el primer numero: ";
            cin >> numero1;

            cout << "Ingrese el segundo numero: ";
            cin >> numero2;

            if(numero2 != 0 && numero1 % numero2 == 0)
            {
                cout << numero1 << " es multiplo de " << numero2;
            }

            else
            {
                cout << numero1 << " no es multiplo de " << numero2;
            }
            break;
        }

        case 'd':
        case 'D':
        {
            main();
            break;
        }

        default:
        cout << "Ingrese una opcion valida." << endl;
        main();
    }

    return 0;
}