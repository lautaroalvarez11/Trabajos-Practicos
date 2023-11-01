#include <iostream>

int main()
{
    for(int numeros = 1; numeros <= 100; ++numeros)
    {
        std::cout << numeros << " ";
        if (numeros % 5 == 0)
        {
            std::cout << std::endl;
        }
    }
    return 0;
}