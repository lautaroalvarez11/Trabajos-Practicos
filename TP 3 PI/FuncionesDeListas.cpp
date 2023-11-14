// NODOS

// Declaración de Nodos mediante Structs
struct Nodo
{
    int dato;
    Nodo* siguiente;
};

// Declarar Puntero Inicial
Nodo* inicio = nullptr;

// Creación de Nodo
Nodo* nuevoNodo = new Nodo;

// Acceder al elemento del Nodo
nuevoNodo -> dato;
nuevoNodo -> siguiente;

// Ejemplo Creación de un Nodo apuntado por puntero inicial
Nodo* nuevo = new Nodo;
nuevoNodo -> dato = 34;
nuevoNodo -> siguiente = nullptr;
inicio = nuevo;

// ------------------------------------------------------------------------------------------------------------------------------

// LISTAS ENLAZADAS SIMPLES

/*
Insertar al inicio de la lista:

1. Se debe generar un nuevo nodo para el elemento a agregar y almacenar en dicho nodo el dato a insertar. 
2. A continuación, se enlazará ese nodo con el resto de la lista.
3. En este caso, enlazar al principio y dejar a este nuevo nodo como el primero de la lista. 
4. Es importante no perder nunca el “principio” de la lista, dado por su puntero inicial.
5. Si se crea una función para insertar, el puntero al inicio de la lista debe ser un parámetro por referencia o bien ser retornado.
*/
Nodo* insertarAlInicio(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    nuevoNodo -> siguiente = inicio; // Que el nuevo nodo apunte al puntero inicio
    inicio = nuevoNodo; // Que el nuevo nodo sea el inicio, osea el primer elemento
    return inicio;
}

/*
Insertar al final de la lista:

1. Se crea un nuevo nodo que será el último de la lista, por lo que su puntero al siguiente será nullptr.
2. Para hacer el enlace, se debe saber si este nodo es,el único de la lista (que significa que la lista estaba vacía), lo cual se detecta analizando si el puntero inicial es nulo.
3. En este caso, el nodo creado será apuntado por el puntero inicial.
4. En caso de existir otros nodos en la lista, se realiza una copia del puntero inicial en otra variable (para no perder el comienzo de la lista) y se avanza recorriendo la lista hasta encontrar un nodo que tenga como siguiente a nullptr (último nodo). 
5. Una vez hallado ese último nodo, se coloca como su siguiente al nuevo nodo creado.
6. El nodo inicial nunca se modifica.
*/
Nodo* insertarAlFinal(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    nuevoNodo -> siguiente = nullptr; // Que el nuevo nodo apunte al nullptr

    if(inicio == nullptr) // Si la lista está vacía (inicio apunta a nullptr), el nuevo nodo se convierte en el primer y único nodo.
    {
        inicio = nuevoNodo;
    }
    else
    {
        // Si la lista no está vacía. Hay que encontrar el último nodo para enlazarlo al nuevo nodo.
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que comienza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr) // Se recorre la lista hasta encontrar el último nodo, que se caracteriza por apuntar a nullptr.
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista.
        }
        auxiliar -> siguiente = nuevoNodo; // Una vez que se encontró el último nodo, se enlaza al nuevo nodo para que sea el nuevo último nodo.
    }
    return inicio; // Se retorna el puntero al inicio de la lista, porque pudo haber cambiado si el nuevo nodo se convirtió en el último.
}

/*
Insertar de manera ordenada en la lista:

1. Si la lista está vacía o el dato del nuevo nodo es menor que el primer elemento, se agrega el nuevo nodo al principio de la lista.
2. Si la lista no está vacía o el dato del nuevo nodo es mayor que el primer elemento,
entonces se recorre la lista buscando el ultimo nodo que contenga un valor menor que el que se quiere insertar con el nuevo nodo,
modificar los punteros siguientes de los nodos para no perder ninguno y a partir de esto hay dos opciones,
que el nuevo nodo se inserte entre dos nodos existentes o que el nuevo nodo se inserte al final
*/
Nodo* insertarOrdenado(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    
    if(inicio == nullptr || nuevoNodo -> dato < inicio -> dato) // Si la lista está vacía o el nuevo nodo debe ir al principio porque es menor que el primer elemento.
    {
        nuevoNodo -> siguiente = inicio; // El nuevo nodo apunta al nodo actual en el inicio, convirtiendose en el primer elemento.
        inicio = nuevoNodo; // Se actualiza el inicio de la lista para que el inicio sea el nuevo nodo.
    } else
    {
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que empieza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato < nuevoNodo -> dato) // Si la lista no está vacía y el nuevo nodo no va al principio.
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor menor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el nuevo nodo.
        nuevoNodo -> siguiente = auxiliar -> siguiente; // El nuevo nodo apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevoNodo; // El anterior (auxiliar) apuntará al nuevo nodo;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nuevo nodo se insertó al inicio
}

/*
Recorrer e Imprimir una lista
1. Se copia el puntero inicial en otra variable (ya que, si se modifica el puntero inicial, se modifica el comienzo de la lista).
2. Se avanza recorriendo la lista hasta encontrar un nodo que tenga como siguiente a nullptr (es decir, hasta encontrar al último nodo).
*/
void mostrarLista(Nodo* inicio)
{
    cout << "Lista: ";
    for(Nodo* temporal = inicio; temporal != nullptr; temporal = temporal -> siguiente)
    {
        cout << temporal -> dato << " ";
    }
}

/*
Eliminar un Nodo de una lista:
1. Asigno un puntero auxiliar para recorrer la lista
2. Si debe eliminarse el primer elemento:
    Asignar el puntero al primer nodo a eliminar en una variable auxiliar
    Cambiar el puntero inicial al siguiente de la lista
    Eliminar el nodo de la variable auxiliar 
3. Si no es el primero de la lista:
    Si el siguiente debe eliminarse:
        Guardar el puntero del nodo a eliminar en una variable auxiliar
        Asignar el puntero del nodo actual al siguiente que hay que eliminar
        Eliminar el nodo de la variable auxiliar
    Si no debe eliminarse el siguiente, paso al siguiente.
*/
Nodo* eliminar(Nodo* inicio, int datoABorrar)
{
    if (inicio != nullptr) // Si la lista no está vacía
    { 
        Nodo* auxiliar = inicio; // Se crea un puntero auxiliar que arranca desde el inicio para recorrer la lista
        if (auxiliar -> dato == datoABorrar) // Si el primer elemento es el que contiene el dato a eliminar
        { 
            inicio = inicio -> siguiente; // El inicio pasa a apuntar al siguiente elemento
            delete auxiliar; // Se elimina el que era el primer elemento y el que era el segundo pasa a ser el primero
        } 
        else
        { 
            while (auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato != datoABorrar) // Mientras el puntero auxiliar no llegue al final de la lista y el siguiente nodo apuntado por el puntero auxiliar no contenga el dato a eliminar
            { 
                auxiliar = auxiliar -> siguiente; // Se recorre la lista
            }
            if (auxiliar -> siguiente -> dato == datoABorrar) // Si el siguiente nodo apuntado por el puntero auxiliar contiene el dato a eliminar
            { 
                Nodo* aEliminar = auxiliar -> siguiente; // Se guarda el puntero del nodo a eliminar en el puntero aEliminar
                auxiliar -> siguiente = aEliminar -> siguiente; // Se asigna el puntero del nodo actual al siguiente que hay que eliminar
                delete aEliminar; // Se elimina el nodo deseado
            } 
        }
    } 
    return inicio; // Se retorna el inicio por si se modificó
}
/*
Eliminar varias ocurrencias de una lista:
*/
int eliminarNumero(Nodo* inicio, int numeroABorrar)
{
    int contador = 0; // Inicializar un contador para saber cuántas ocurrencias se eliminan.
    Nodo* anterior = nullptr; // Inicializar un puntero anterior para ubicar el nodo anterior al nodo actual.
    Nodo* auxiliar = inicio; // Inicializar un puntero auxiliar que comienza en el inicio de la lista.

    while (auxiliar != nullptr) // Mientras el puntero auxiliar no llegue al final de la lista.
    {
        if (auxiliar -> dato == numeroABorrar) // Comprobar si el dato del nodo actual es igual al número que se quiere borrar.
        {
            contador++; // Incrementar el contador porque se encontró una ocurrencia del número a borrar.
            
            if (anterior == nullptr) // Comprobar si el nodo actual es el primer nodo de la lista.
            {
                inicio = auxiliar -> siguiente; // Actualizar el inicio de la lista para que sea el siguiente nodo.
                delete auxiliar; // Eliminar el nodo actual.
                auxiliar = inicio; // Mover el puntero auxiliar al nuevo inicio de la lista.
            }
            else
            {
                anterior -> siguiente = auxiliar -> siguiente; // Actualizar el puntero siguiente del nodo anterior para saltear el nodo actual.
                delete auxiliar; // Eliminar el nodo actual.
                auxiliar = anterior -> siguiente; // Mover el puntero auxiliar al siguiente nodo después del nodo actual.
            }
        }
        else
        {
            anterior = auxiliar; // Actualizar el puntero anterior para que apunte al nodo actual.
            auxiliar = auxiliar -> siguiente; // Mover el puntero auxiliar al siguiente nodo en la lista.
        }
    }
    return contador; // Retornar la cantidad total de ocurrencias eliminadas.
}

/*
Dividir una lista en dos:
*/
void dividir_lista(Nodo* & inicio, Nodo* parametro)
{
    Nodo* anterior;
    while (inicio != nullptr)
    {
        anterior = inicio;
        inicio = inicio->siguiente;
        anterior->siguiente = nullptr;
        if (anterior->dato % 2 == 0)
        {
        pares = insertarAlFinal(pares, anterior);
        }
        else
        {
        impares = insertarAlFinal(impares, anterior);
        }
    }
}