/******************************************************************************

Escribir un programa el cual lee información de 10 empleados. 
De cada uno se conoce: su nombre y apellido, su sueldo base, su DNI y la cantidad de horas extras trabajadas (0 si no trabajó ninguna). 
El monto pagado por hora extra es $150.

A medida que la información es leída se debe informar el sueldo que debe pagarse a cada empleado. 
Estos datos deben almacenarse en un arreglo.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

const int numeroDeEmpleados = 10;
const double montoPorHoraExtra = 150.0;

struct Empleado 
{
    string nombre;
    string apellido;
    double sueldoBase;
    string dni;
    int horasExtrasTrabajadas;
    double sueldoTotal;};

double calcularElSueldoTotalDeUnEmpleado(int horasExtrasTrabajadasPorUnEmpleado, double sueldoBaseDeEsteEmpleado)
{   
    double pagoPorLasHorasExtras = horasExtrasTrabajadasPorUnEmpleado * montoPorHoraExtra;
    return sueldoBaseDeEsteEmpleado + pagoPorLasHorasExtras;
}
    
void cargarLosDatosDeLosEmpleados(Empleado todosLosEmpleados[])
{
    for (int i = 0; i < numeroDeEmpleados; ++i) 
    {
        cout << "Ingrese el nombre del empleado " << i + 1 << ": ";
        cin >> todosLosEmpleados[i].nombre;

        cout << "Ingrese el apellido del empleado " << i + 1 << ": ";
        cin >> todosLosEmpleados[i].apellido;

        cout << "Ingrese el sueldo base del empleado " << i + 1 << ": $";
        cin >> todosLosEmpleados[i].sueldoBase;

        cout << "Ingrese el DNI del empleado " << i + 1 << ": ";
        cin >> todosLosEmpleados[i].dni;

        cout << "Ingrese la cantidad de horas extras trabajadas por el empleado " << i + 1 << ": ";
        cin >> todosLosEmpleados[i].horasExtrasTrabajadas;

        // invoca a la función que calcula el sueldo total
        todosLosEmpleados[i].sueldoTotal = calcularElSueldoTotalDeUnEmpleado(todosLosEmpleados[i].horasExtrasTrabajadas, todosLosEmpleados[i].sueldoBase);
    
        cout << "El sueldo a pagar al empleado " << i + 1 << " es: $" << todosLosEmpleados[i].sueldoTotal << "\n\n";
    }
}

int main() 
{
    Empleado todosLosEmpleados[numeroDeEmpleados];
    cargarLosDatosDeLosEmpleados(todosLosEmpleados);
    return 0;
}
