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

// ---------------------------------------------------------------------------------------------------------------------------------

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

    if(inicio == nullptr) // Si la lista está vacía (inicio apunta a nullptr)
    {
        inicio = nuevoNodo; // El nuevo nodo se convierte en el primer y único nodo.
    }
    else // Si la lista no está vacía. Hay que encontrar el último nodo para enlazarlo al nuevo nodo.
    {
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
void dividir_lista(Nodo* & inicio, Nodo* & lista1, Nodo* & lista2)
{
    Nodo* anterior; // Se declara un puntero anterior para mantener una referencia al nodo actual que está siendo procesado dentro del bucle while que recorre las listas.
    while (inicio != nullptr) // Mientras que la lista principal tenga elementos
    {
        anterior = inicio; // El puntero anterior apunta al mismo nodo que inicio
        inicio = inicio -> siguiente; // Inicio se mueve al siguiente nodo en la lista
        anterior -> siguiente = nullptr; // El puntero anterior pasa a ubicarse en el ultimo nodo de la lista al apuntar a nullptr
        if (anterior -> dato "Alguna condición") // Se comprueba alguna condición con el dato del nodo anterior
        {
        lista1 = insertarAlFinal(lista1, anterior); // Si la condición se cumple entonces se inserta anterior al final de la lista1
        }
        else
        {
        lista2 = insertarAlFinal(lista2, anterior); // Si la condición no se cumple, entonces se inserta al final de la lista2
        }
    }
}

/*
Unir dos listas:
*/
Nodo* unirListas(Nodo* lista1, Nodo* lista2, Nodo* lista3)
{
    Nodo* auxiliar1 = lista1; // Se utiliza un puntero auxiliar1 para recorrer la lista1
    Nodo* auxiliar2 = lista2; // Se utiliza un puntero auxiliar2 para recorrer la lista2
    Nodo* auxiliar3 = lista3; // Se utiliza un puntero auxiliar3 para ir guardando los datos en la lista3

    while(auxiliar1 != nullptr) // Mientras la lista1 no se termine
    {
        auxiliar3 = insertarOrdenado(auxiliar3, auxiliar1 -> dato); // Insertar los datos de la lista1 en la lista3
        auxiliar1 = auxiliar1 -> siguiente; // Ir recorriendo los nodos
    }
    while(auxiliar2 != nullptr) // Mientras la lista2 no se termine
    {
        auxiliar3 = insertarOrdenado(auxiliar3, auxiliar2 -> dato); // Insertar los datos de la lista2 en la lista3
        auxiliar2 = auxiliar2 -> siguiente; // Ir recorriendo los nodos
    }
    return auxiliar3; // Retornar la lista3
}

/*
Listas de Structs:
Funcionamiento con un ejemplo
*/
struct Articulos
{
    int codigo;
    string descripcion;
    int precio;
    int stock;
};

struct Nodo
{
    Articulos dato;
    Nodo* siguiente;
};

Nodo* insertarOrdenado(Nodo* inicio, Articulos productos)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nuevo nodo para insertar un articulo en la lista
    nuevoNodo -> siguiente = nullptr; // Se indica que la lista no contiene ningun elemento

    // Al campo articulosSuper del nuevo nodo se le asigna el parametro productos para que se guarden los productos pasados por este ultimo parametro y de ahi se almacenen en el struct Articulos 
    nuevoNodo -> dato = productos;

    
    if(inicio == nullptr || nuevoNodo -> dato.codigo < inicio -> dato.codigo) // Si la lista está vacía o el codigo del nuevo nodo debe ir al principio porque es menor que el primer codigo de la lista.
    {
        nuevoNodo -> siguiente = inicio; // El nuevo nodo apunta al nodo actual en el inicio.
        inicio = nuevoNodo; // Se actualiza el inicio de la lista para que el nuevo nodo sea el nuevo inicio.
    }
    else
    {
        Nodo* auxiliar = inicio; // Se crea un nodo auxiliar que empieza en el inicio de la lista.
        while(auxiliar -> siguiente != nullptr && auxiliar -> siguiente -> dato.codigo < nuevoNodo -> dato.codigo) // Mientras la lista no esté vacía y el codigo del siguiente nuevo nodo es menor que el codigo del nuevo nodo (Se busca la posición adecuada para insertar el nuevo codigo)
        {
            auxiliar = auxiliar -> siguiente; // Se avanza al siguiente nodo en la lista buscando el último nodo que contenga un valor menor al que se quiere insertar.
        }
        // Una vez que se encontró el lugar correcto, se actualizan los punteros para insertar el codigo del nuevo nodo.
        nuevoNodo -> siguiente = auxiliar -> siguiente; // El nuevo nodo apuntará al siguiente de su anterior (auxiliar)
        auxiliar -> siguiente = nuevoNodo; // El anterior (auxiliar) apuntará al nuevo nodo;
    }
    return inicio; // Se retorna el puntero al inicio de la lista, por si el nuevo nodo se insertó al inicio
}

// ---------------------------------------------------------------------------------------------------------------------------------

// LISTAS CIRCULARES

/*
Son muy similares a las listas enlazadas simples, sólo que no tienen un
valor nullptr al final ya que, al recorrer todos los elementos, se
vuelve al nodo inicial.

Si la lista tiene un solo nodo, su puntero siguiente
referenciará al mismo nodo.

Si la lista está vacía, al igual que en las listas simples, el
puntero contendrá nullptr.

La declaración de los nodos de una lista circular será igual
que en las listas simples, y las operaciones que pueden
realizarse son muy similares a las de una lista simple.

La diferencia es que ahora tendremos un puntero que, aunque
inicialmente contendrá nullptr mientras la lista no tenga nodos
(vacía), luego apuntará siempre al último nodo de la lista

Nodo* fin = new Nodo;
fin = nullptr;
EN EL MAIN
*/

/*
Insertar al inicio de la lista:
*/
Nodo* insertarAlPrincipio(Nodo* fin, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nodo para almacenar el valor
    nuevoNodo -> dato = numero; // El dato que va a contener el nuevo nodo es el que ingrese el usuario

    if (fin == nullptr) // Si la lista esta vacía
    {
      nuevoNodo -> siguiente = nuevoNodo; // El nuevo nodo va a apuntarse a sí mismo, es decir va a ser el primer elemento
      fin = nuevoNodo; // El final es el inicio, es decir el nuevo nodo va a ser el primero y el ultimo
    }
    else // Si la lista no está vacía
    {
      nuevoNodo -> siguiente = fin -> siguiente; // El nuevo nodo va a apuntar al nodo que apunte el puntero fin
      fin -> siguiente = nuevoNodo; // Y el puntero fin va a apuntar al nuevo nodo porque es el primer elemento
    }

    return fin; // Retorna el puntero fin porque apunta al primer elemento de la lista
}

/*
Insertar al final de la lista:
*/
Nodo* insertarAlFinal(Nodo* fin, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Se crea un nodo para almacenar el valor
    nuevoNodo -> dato = numero; // El dato que va a contener el nuevo nodo es el que ingrese el usuario

    if (fin == nullptr) // Si la lista está vacía
    {
        nuevoNodo -> siguiente = nuevoNodo; // El nuevo nodo debe apuntarse a sí mismo
    }
    else // Si la lista no está vacía
    {
        nuevoNodo -> siguiente = fin -> siguiente; // El nuevo nodo va a apuntar al nodo que apunte el puntero fin
        fin -> siguiente = nuevoNodo; // // El puntero fin va a apuntar al nuevo nodo porque es el primer elemento
    }
    return nuevoNodo; // Retorna el ultimo numero insertado en la lista
}

/*
Recorrer e imprimir una lista:
*/
void mostrarLista(Nodo* fin)
{
    cout << "Lista:" << endl;
    if(fin != nullptr)
    {
        Nodo* auxiliar = fin -> siguiente;
        do
        {
            cout << auxiliar -> dato << " ";
            auxiliar = auxiliar -> siguiente; 
        } while (auxiliar != fin -> siguiente);
    }
}

/*
Eliminar un elemento de una lista:
*/
Nodo* eliminarElemento(Nodo* fin, int datoABorrar)
{
    if (fin != nullptr) // Comprobar si la lista tiene elementos
    {
        Nodo* auxiliar = fin; // Se crea un puntero auxiliar que apunta al nodo final.
        Nodo* aEliminar; // Se declara un puntero 'aEliminar' para almacenar el nodo a eliminar.
        do // Inicia un bucle 'do-while' para recorrer la lista.
        {
            if (auxiliar -> siguiente -> dato == datoABorrar) // Comprueba si el siguiente nodo tiene el dato a borrar.
            {
                aEliminar = auxiliar -> siguiente; // Se asigna a 'aEliminar' el nodo a borrar.
                if (aEliminar == fin) // Comprobar si el nodo a eliminar es el nodo final.
                {
                    fin = auxiliar; // Si es así, se actualiza el nodo final (fin) al nodo anterior.
                }
                auxiliar -> siguiente = aEliminar -> siguiente; // Enlaza el nodo anterior con el siguiente del nodo a eliminar.
                delete aEliminar; // Libera la memoria del nodo a eliminar.
                break; // Sale del bucle 'do-while'.
            }
            else
            {
                auxiliar = auxiliar -> siguiente; // Avanza al siguiente nodo en la lista.
            }
        } while (auxiliar != fin); // El bucle se ejecuta hasta que se alcanza nuevamente el nodo final.

        // Si el elemento no se encuentra, o se eliminó, se devuelve el nodo final actualizado.
    }
    return fin;
}