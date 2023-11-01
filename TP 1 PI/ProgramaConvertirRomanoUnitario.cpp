#include <iostream>
using namespace std;

string convertirARomano(int numero)
{
    /*
    Esta función recibe un único parámetro "numero", de tipo entero, que representa el valor que se desea convertir al sistema romano
    Su valor de retorno es una cadena (string) con la representación del numero convertido.
    Este será una combinación de los siguientes simbolos romanos:
    I -> unidad
    V -> cinco
    X -> diez
    L -> cincuenta
    C -> cien
    D -> quinientos
    M -> mil
    */

    string convertido = "";
    /*
    El numero recibido tiene como máximo 4 digitos, por lo tanto la división por 1000 obtiene el primero desde la izquierda, de existir, que indaca los miles
    por ejemplo si el numero es 3895,  3895/1000 = 3, este indicará la cantidad de "Miles" que tiene el numero y por lo tanto cuantas veces se repite el simbolo M
    En caso de que el numero sea menor a 1000, este resultado será 0 y al no estar contemplado en los posibles "case", no agrega nada a la cadena
    */
    switch (numero/1000)
    {
    case 1:
        /*
        En caso de que el resultado de hacer numero/1000 sea 1, se ejecuta este case y se agrega el caracter "M" (1000) a la cadena de resultado
        Cada case siguiente agrega tantas M como miles haya en el número, hasta un máximo de 3 (ya que el maximo posible es 3999)
        La misma lógica aplica para los siguientes switchs.
        */
        convertido += "M";
        break;
    case 2:
        convertido += "MM";
        break;
    case 3:
        convertido += "MMM";
        break;
    }

    /*
    Este switch decide la cantidad de centenas que contiene el número, corriendo la coma desde la derecha dos posiciones y quedandose con el ultimo digito.
    por ejemplo si el numero es 144,  144/100 = 1, este indicará la cantidad de "cientos" que tiene el numero y por lo tanto cuantas veces se repite el simbolo C o la combinación adecuada
     Al igual que el anterior si el numero es menor a 100, este resultado será 0 y al no estar contemplado en los posibles "case", no agrega nada a la cadena
    */
    switch ((numero / 100) % 10)
    {
    case 1:
        convertido += "C";
        break;
    case 2:
        convertido += "CC";
        break;
    case 3:
        convertido += "CCC";
        break;
    case 4:
        convertido += "CD";
        break;
    case 5:
        convertido += "D";
        break;
    case 6:
        convertido += "DC";
        break;
    case 7:
        convertido += "DCC";
        break;
    case 8:
        convertido += "DCCC";
        break;
    case 9:
        convertido += "CM";
        break;
    }

    /*
    El proceso para las decenas es igual que para las centenas, con distintos valores ya que debo correr la coma solo un lugar desde la derecha.
    */
    switch ((numero / 10) % 10)
    {
    case 1:
        convertido += "X";
        break;
    case 2:
        convertido += "XX";
        break;
    case 3:
        convertido += "XXX";
        break;
    case 4:
        convertido += "XL";
        break;
    case 5:
        convertido += "L";
        break;
    case 6:
        convertido += "LX";
        break;
    case 7:
        convertido += "LXX";
        break;
    case 8:
        convertido += "LXXX";
        break;
    case 9:
        convertido += "XC";
        break;
    }

    /*
    En este switch se consideran las unidades simples no es necesario desplazar la coma, solo saber el último dígito del numero ingresado.
    */
    switch (numero % 10)
    {
    case 1:
        convertido += "I";
        break;
    case 2:
        convertido += "II";
        break;
    case 3:
        convertido += "III";
        break;
    case 4:
        convertido += "IV";
        break;
    case 5:
        convertido += "V";
        break;
    case 6:
        convertido += "VI";
        break;
    case 7:
        convertido += "VII";
        break;
    case 8:
        convertido += "VIII";
        break;
    case 9:
        convertido += "IX";
        break;
    }
    /*
    Una vez se ejecutaron todos los switchs, la representación romana esta completa y se devuelve al contexto que invocó la función.
    */
    return convertido;
}

string convertirAUnitario(int numero, char simbolo)
{
    /*
    Esta función recibe dos parámetros, ambos por copia ya que no es necesario alterarlos en el ambito principal:
        - "numero", de tipo entero, que representa el valor que se desea convertir al sistema unitario
        - "simbolo", de tipo char, que representa qué símbolo se usará para representar la cantidad deseada
    Su valor de retorno es una cadena (string) con la representación del numero convertido.
    */
    string resultado = "";
    for (int i = 1; i <= numero; i++)
    {
        /*
        El sistema unitario contempla la repetición de un único símbolo tantas veces como la cantidad que se desee representar, por lo tanto se ejecuta un bucle con limite en el numero
        a convertir, y por cada ciclo se agrega una instancia del símbolo a la cadena de resultado.
        Por ejemplo si se ingresa un 3, la cadena se construirá asi:
        1° ciclo: "*" (i=1)
        2° ciclo: "**" (i=2)
        3° ciclo: "***" (i=3)
        */
        resultado += simbolo;
    }
    return resultado;
}

int main()
{
    //Esta variable almacenará la opción del menú elegida por usuario . Al ser un char, elimina problemas entre numeros y caracteres.
    char opcion;
    do
    /*
     Uso un do-while para imprimir el menú de opciones al menos una vez y permitir al usuario elegir que acción quiere llevar a cabo.
     Cada opción tiene asignada una letra mayúscula, y gracias al do-while el usuario puede elegir letras tantas veces como quiera hasta el momento en que ingrese la C (mayuscula o minuscula)
     */
    {
        cout << endl
             << "A - Convertir a romano" << endl;
        cout << "B - Convertir a unitario" << endl;
        cout << "C - Salir" << endl;
        cout << endl
             << "Ingrese una opcion: ";
        cin >> opcion;
        //Se declara la variable numeroAConvertir aquí ya que ambas opciones del menú (A,B) requieren un número a convertir para funcionar.
        int numeroAConvertir;
        //Se convierte la opción seleccionada a mayúsculas para poder comparar contra algo conocido
        switch (toupper(opcion))
        {
        case 'A':
            /*
            Si el usuario elige la primera opción, se solicita el ingreso de un número restringido al rango entre 1 y 3999 (incluidos) debido a las limitaciones de los numeros romanos.
            Luego, se ejecuta un bucle while donde se verifica si el numero efectivamente se encuentra en ese rango. Si esto no es cierto, se informa del error y se vuelve a solicitar el ingreso.
            El usuario no puede escapar de este bucle hasta que ingrese un numero que cumpla con las condiciones solicitadas.
            */
            cout << "Numero a convertir (entre 1 y 3999): ";
            cin >> numeroAConvertir;
            while (numeroAConvertir <= 0 || numeroAConvertir > 3999)
            {
                cout << "¡Error, el numero " << numeroAConvertir << " está fuera de rango!" << endl;
                cout << "Por favor, reingrese un numero (entre 1 y 3999): ";
                cin >> numeroAConvertir;
            }
            //La función convertirARomano devuelve una cadena (string), por lo tanto se imprime por pantalla directamente el resultado de invocarla. El número ya fue validado en los pasos anteriores
            cout << convertirARomano(numeroAConvertir) << endl;
            break;
        case 'B':
        {
            /*
            Si el usuario elige la segunda opción, se solicita el ingreso de un número en forma no restringida y de un símbolo. Esto es por que el sistema unario utiliza un símbolo único
            en repetición para representar las cantidades. Por ejemplo si el símbolo base es "*", el número 5 se representa como "*****" (5 del mismo simbolo en secuencia).
            */
            cout << "Numero a convertir: " << endl;
            cin >> numeroAConvertir;
            char simbolo;
            cout << "Elija un símbolo para representar las unidades: ";
            cin >> simbolo;
            /*
            Una vez que se eligieron tanto el numero como el simbolo, se ejecuta la función y se muestra el valor retornado por pantalla (un string)
            */
            cout << endl << "El numero " << numeroAConvertir<< " en el sistema unario se representa como: "<< convertirAUnitario(numeroAConvertir, simbolo)<<endl;
            break;
        }
        case 'C':
            /*
            Si el usuario elige la tercera opción del menú, solo se ejecuta un break para forzar a la evaluación de la condición del while.
            Este case es importante, ya que si bien no tiene un comportamiento especifico, evita que el caracter de escape se reconozca como "no valido"
            */
            break;
        default:
            /*comportamiento esperado si el usuario ingresa un caracter no disponible en el menú*/
            cout << "No se reconoció la opción, por favor ingrese una de las disponibles en el menú a continuación" << endl;
        };
    } while (toupper(opcion) != 'C');

    cout << "Gracias por usar el sistema de conversiones" << endl;

    return 0;
}