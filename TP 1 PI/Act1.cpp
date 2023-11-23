#include <iostream>
#include <string>
using namespace std;

int main()
{
    for(int numeros = 1; numeros <= 100; ++numeros)
    {
        cout << numeros << " ";
        if (numeros % 5 == 0)
        {
            cout << endl;
        }
    }
    return 0;
}