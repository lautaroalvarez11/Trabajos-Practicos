#include <iostream>
#include <string>
#include <ctime>
using namespace std;


struct datosPaciente //hacemos una estructura tipo "paciente"
{
	string apellido;
	string nombre;
	string dni;
	string telefono; 
};

struct datosEspMed// hacemos una estructura tipo "datosEspMed"
{
    string codigo;
    string nombre;
    string desc;
};

struct datosTurnos // hacemos una estructura tipo "datosTurnos"
{
    int codigo;
    string fecha;
    string hora;
    string minutos;
    string paciente;
    string especialidadMedica;
    int estado;
};

bool esUnNumeroFunc(const string &str)
{
    cout << (str);
    cout << endl;
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
        {
            cout << "Alguno de los datos ingresados no es un numero";
            cout << endl;
            return false;
        }
    }
    return true;
}

bool noEsUnNumeroFunc(const string &str)
{
    cout << (str);
    cout << endl;
    for (char const &c : str)
    {
        if (isalpha(c) == 0)
        {
            cout << "Alguno de los datos ingresados contiene un numero";
            cout << endl;
            return false;
        }
    }
    return true;
}

void AltaPacientes(datosPaciente arregloPaciente[], int & refe){ 
    cout<<"Usted eligio -Alta de Pacientes-"<<endl;
    
	int condicion=0;
    
	while (condicion == 0){
		cout << "ingrese apellido del paciente"<< endl;
		getline(cin>>ws, arregloPaciente[refe].apellido);
		
		cout << "ingrese nombre del paciente"<< endl;
		getline(cin>>ws, arregloPaciente[refe].nombre);
		
    	cout << "ingrese dni del paciente" << endl;
    	cin >> arregloPaciente[refe].dni;
    	
    	cout << "ingrese telefono del paciente" << endl;
    	cin >> arregloPaciente[refe].telefono;
			
	if (arregloPaciente[refe].apellido != " ") {
			condicion = 1;
			}else{
				condicion = 0;
				cout << "habeis introducido el apellido del paciente en blanco"<< endl;
				break; 
				}
				
	if (arregloPaciente[refe].nombre != " ") {
			condicion = 1;
			}else{
				condicion = 0;
				cout << "habeis introducido el nombre del paciente en blanco"<< endl;
				break;
				}
				
	if (arregloPaciente[refe].dni != "") {
			condicion = 1;
			}else{
				condicion = 0;
				cout << "habeis introducido el dni = 0 y tiene ser distinto a 0"<< endl;
				break;
				}
				
	if (arregloPaciente[refe].telefono != "") {
			condicion = 1;		
			}else{
				condicion = 0;
				cout << "habeis introducido el nro de telefono = 0 y tiene ser distinto a 0"<< endl;
				break;
				}
	cout << "el apellido del paciente ingresado es: " << arregloPaciente[refe].apellido << endl;
	cout << "el nombre del paciente ingresado es: " << arregloPaciente[refe].nombre << endl;
	cout << "el dni del paciente ingresado es: " << arregloPaciente[refe].dni << endl;
	cout << "el numero de telefono ingresado del paciente es: " << arregloPaciente[refe].telefono << endl;
	cout << endl;
	refe++;
	
	
    
	cout<<"Presione ENTER para volver al menu de Pacientes" << endl;
	cin.get();

}
}

//Funcion para Modificar la informacion del paciente
void ModificarPacientes (datosPaciente arregloPaciente[], int limit){
	cout << "Usted eligio -Modificacion de Pacientes-" << endl;
	
	string dniIngresado = 0;
	 bool esUnNumero = false;
    do{
	cout << "ingrese el dni del usuario"<< endl;
	cin >> dniIngresado;
        esUnNumero = esUnNumeroFunc(dniIngresado);
    }while (esUnNumero == false);
            
 	int condicion = 0;
 	int iterador2=0;
 	
 	for (iterador2=0; iterador2 < limit; iterador2++){
 		if (arregloPaciente[iterador2].dni == dniIngresado){
 		    while (condicion == 0){
				cout << "ingrese apellido del paciente"<< endl;
				getline(cin>>ws, arregloPaciente[iterador2].apellido);
				
				cout << "ingrese nombre del paciente"<< endl;
				getline(cin>>ws, arregloPaciente[iterador2].nombre);
    			
    			cout << "ingrese telefono del paciente" << endl;
    			cin >> arregloPaciente[iterador2].telefono;
				system ("cls"); //borra la pantalla
				
			
				if (arregloPaciente[iterador2].apellido != " "){
				condicion = 1;
				}else{
					condicion = 0;
					break;
					}
				
				if (arregloPaciente[iterador2].nombre != " ") {
					condicion = 1;
				}else{
					condicion = 0;
					break;
					}
					
				if (arregloPaciente[iterador2].telefono != " ") {
					condicion = 1;
				}else{
					condicion = 0;
					break;
					}
			}
			iterador2 = limit + 1;
		}
		

	}
				if (iterador2 == limit) {
 			        condicion = 1;
 			        cout << " el dni no es valido"<< endl;
 					system ("cls"); //borra la pantalla
				}
	
	
	
	
    cout<<"Presione ENTER para volver al menu de Pacientes"<< endl;
	cin.get();
	system ("cls"); //borra la pantalla
	}
 	
 	
 	


//Funcion para eliminar a un paciente del sistema
void BajaPacientes(){ 
    cout<<"Usted eligio -Baja de Pacientes-"<<endl;
    cout<<"Presione ENTER para volver al menu de Pcientes"<< endl;
	cin.get();
	system ("cls"); //borra la pantalla
}

//Funcion para mostrar todos los pacientes del sistema y sus datos
void list_Pacientes_Completo(){
    cout<<"Usted eligio -Listado de Pacientes Completo-"<<endl;
	cout<<"Presione ENTER para volver al menu de Listados"<< endl;
	cin.get();
	system ("cls"); //borra la pantalla
}

//Funcion para la busqueda de los datos de un paciente en particular
void list_Pacientes_Busqueda(){
    cout<<"Usted eligio -Busqueda de Pacientes-"<<endl;
	cout<<"Presione ENTER para volver al menu de Listados"<< endl;
	cin.get();
	system ("cls"); //borra la pantalla
}

//Funcion para seleccionar que tipo busqueda de informacion se desea usar
void ListadoPacientes(){
    char sub_menu_list_pacientes = 'A';
    
    cout<<"Usted eligio -Listado de Pacientes-"<<endl;
    cout<<"Elija el listado"<<endl;
    
    while (sub_menu_list_pacientes != 'h'){   
        
    //Menu para seleccionar que tipo de busqueda de informacion se desea
    cout<<"f)  Listado Completo"<<endl;
    cout<<"g)  Busqueda de Paciente"<<endl;
    cout<<"h)  Volver al menu de Pacientes" <<endl;
    
    cin>>sub_menu_list_pacientes;
    system ("cls"); //borra la pantalla
    
        //Swich para seleccionar que tipo de funcion se eligio  
        switch (sub_menu_list_pacientes){
            
            case 'f':
                list_Pacientes_Completo();
                break;
            
            case 'g':
                list_Pacientes_Busqueda();
                break;
                
            case 'h':
                break;
            
            default:
                cout <<"Ustede no a selecionado ninguna de las opciones posibles" <<endl;
                cout<< endl;
                break;
        }
    }
}

//Funcion del menu para la seccion de pacientes
void mainPacientes(datosPaciente arrayPacientes[],int & indicePacientes,datosTurnos arrayTurnos[],int & indiceTurnos){
    
    char menu_opcion = 'A';
    while (menu_opcion != 'e') {
        
    //Menu para seleccionar que funcion se va a utilizar     
    cout<<"a)  Alta de Pacientes"<<endl;
    cout<<"b)  Modificación de Pacientes"<<endl;
    cout<<"c)  Baja de Pacientes"<<endl;
    cout<<"d)  Listado de Pacientes"<<endl;
    cout<<"e)  Volver al menu Principal" <<endl;
    cin >> menu_opcion;
	system ("cls"); //borra la pantalla	

    //Swich para seleccionar que tipo de funcion se eligio 
    switch (menu_opcion){
        
        case 'a':
            AltaPacientes(arrayPacientes, indicePacientes);
            
            break;
            
        case 'b':
            ModificarPacientes(arrayPacientes, indicePacientes);
            
            break;
            
        case 'c':
            BajaPacientes();
            break;
            
        case 'd':
            ListadoPacientes();
            break;
            
         case 'e':
            break;
            
         default:
            cout <<"Ustede no a selecionado ninguna de las opciones posibles" <<endl;
            cout<< endl;
            break;
         
}
}
}


void AltaEspeMed(datosEspMed arregloEspMed[] , int & indEspMed){ 
    
    cout<<"Usted eligio -Alta de Especialidades Medicas-"<<endl;
    
    int error = 0;
    bool noEsUnNumero = false;
    
    do{
        
        cout << "Ingrese el Nombre de la Especialidad Medica: ";
        getline(cin>>ws, arregloEspMed[indEspMed].nombre);
        
        arregloEspMed[indEspMed].codigo = to_string(indEspMed);
        
        cout << "descripcion especialidad medica: ";
        getline(cin>>ws, arregloEspMed[indEspMed].desc);
        
        if (arregloEspMed[indEspMed].nombre != " "){
            error = 1;
        
        }
        else{
            continue;
        } 
        
        noEsUnNumero = noEsUnNumeroFunc( arregloEspMed[indEspMed].nombre);
    }while (error == 0 and noEsUnNumero == false );
    
    
    cout << arregloEspMed[indEspMed].nombre<<endl;
    cout << arregloEspMed[indEspMed].codigo<<endl;
    cout << arregloEspMed[indEspMed].desc<<endl;

    indEspMed++;
	cout<<"Presione ENTER para volver al menu de Especialidades Medicas" << endl;
	cin.get();
}

//Funcion para Modificar la informacion de las especialidades medicas
void ModificarEspeMed(datosEspMed arregloEspMed[],int indEspMed){ 
    cout<<"Usted eligio -Modificación de Especialidades Medicas-"<<endl;
    
    string selector;
    
    bool esUnNumero = false;
    do{
        cout << "Ingrese el codigo de la espcialidad medica a modifica: "<< endl;
        cin>> selector;
        esUnNumero = esUnNumeroFunc(selector);
    }while (esUnNumero == false);
            
    int intselector = stoi(selector);
       
            
    if (arregloEspMed[intselector].codigo == selector and intselector < indEspMed ){
            
        int error =0;
        bool noEsUnNumero = false;
        do{
                 
            cout << "Nombre: ";
            getline(cin>>ws, arregloEspMed[intselector].nombre);
            cout << "descripcion especialidad medica: ";
            getline(cin>>ws, arregloEspMed[intselector].desc);
            
            cout << arregloEspMed[intselector].nombre<<endl;
            cout << arregloEspMed[intselector].codigo<<endl;
            cout << arregloEspMed[intselector].desc<<endl;
                
            if  (arregloEspMed[intselector].nombre != " "){
                    error = 1;
            }
            else{
                continue;
            }
            
            noEsUnNumero = noEsUnNumeroFunc( arregloEspMed[intselector].nombre);
        
        } while (error == 0 and noEsUnNumero == false);
    }
    else{ 
    cout << "Ingreso un codigo inexistente "<< endl;
            
    }

    cout<<"Presione ENTER para volver al menu de Especialidades Medicas"<< endl;
	cin.get();
}

//Funcion para eliminar a un paciente del sistema
void BajaEspeMed(datosEspMed arregloEspMed[],datosTurnos arregloTurnos[],int indEspMed,int indTurnos){ 
    
    cout<<"Usted eligio -Baja de Especialidades Medicas-"<<endl;
    
    string selector;
    
    bool esUnNumero = false;
        do{
            cout << "Ingrese el codigo de la espcialidad medica a modifica: "<< endl;
            cin>> selector;
            esUnNumero = esUnNumeroFunc(selector);
        }while (esUnNumero == false);
            
    int intselector = stoi(selector);
            
    if (arregloEspMed[intselector].codigo == selector and intselector < indEspMed ){ 
            
        cout << arregloEspMed[intselector].nombre<<endl;
        cout << arregloEspMed[intselector].codigo<<endl;
        cout << arregloEspMed[intselector].desc<<endl;
            
        char selectorMenuBaja;
            
        cout << "Desea eliminar la especialidad medica de la base de datos ?" << endl;
        cout << endl;
            
        do{ 
            cout<<"1)  Eliminar"<<endl;
            cout<<"2)  Volver al menu"<<endl;
            
            cin >>selectorMenuBaja;
            
            switch (selectorMenuBaja){
        
            case '1':
                    
                for(int i = 0 ; i <= indTurnos; i++){
                    if(arregloTurnos[i].especialidadMedica == arregloEspMed[intselector].codigo){
                           
                        cout <<"La especialidad médica no puede eliminarse debido a que se encuentra presente en uno o más turnos reservados" << endl;
                    }
                    else if(i == indTurnos){
                        arregloEspMed[intselector].codigo = " ";
                        arregloEspMed[intselector].nombre = " ";
                        arregloEspMed[intselector].desc = " ";
                        cout << "Se elimino con exito"<<endl;
                    }
                    else{
                    }
                }
                selectorMenuBaja = 2;
                break;

            case '2':
       
                break;
            default:
                cout <<"Ustede no a selecionado ninguna de las opciones posibles" <<endl;
                cout<< endl;
                break;
            }
        }while (selectorMenuBaja  != '2');
    }
    else{
        cout << "El Codigo ingresado no corresponde a ninguna especialidad medica"<<endl; 
    }
    
    cout<<"Presione ENTER para volver al menu de Especialidades Medicas"<< endl;
	cin.get();
}

//Funcion para mostrar todos los pacientes del sistema y sus datos
void list_EspeMed_Completo(){
    cout<<"Usted eligio -Listado de Especialidades Medicas Completo-"<<endl;
	cout<<"Presione ENTER para volver al menu de Listados"<< endl;
	cin.get();
}

//Funcion para la busqueda de los datos de una especialidad medica en particular
void list_EspeMed_Busqueda(){
    cout<<"Usted eligio -Busqueda de Especialidades Medicas-"<<endl;
	cout<<"Presione ENTER para volver al menu de Listados"<< endl;
	cin.get();
}

//Funcion para seleccionar que tipo busqueda de informacion se desea usar
void ListadoEspeMed(){
    char sub_menu_list_espemed = 'A';
    
    cout<<"Usted eligio -Listado de Especialidades Medicas-"<<endl;
    cout<<"Elija el listado"<<endl;
    
    while (sub_menu_list_espemed != 'h'){   
        
    //Menu para seleccionar que tipo de busqueda de informacion se desea
    cout<<"f)  Listado Completo de Especialidades Medicas"<<endl;
    cout<<"g)  Busqueda de Especialidad Medica"<<endl;
    cout<<"h)  Volver al menu de Especialidades Medicas" <<endl;
    
    cin>>sub_menu_list_espemed;
    
        //Swich para seleccionar que tipo de funcion se eligio  
        switch (sub_menu_list_espemed){
            
            case 'f':
                list_EspeMed_Completo();
                break;
            
            case 'g':
                list_EspeMed_Busqueda();
                break;
                
            case 'h':
                break;
            
            default:
                cout <<"Ustede no a selecionado ninguna de las opciones posibles" <<endl;
                cout<< endl;
                break;
        }
    }
}

//Funcion del menu para la seccion de Especialidades Medicas
void mainEspMed(datosEspMed arrayEspMed[],int & indiceEspMed,datosTurnos arrayTurnos[],int & indiceTurnos){
    
    char menu_opcion_espemed  = 'A';
    while (menu_opcion_espemed  != 'e') {
        
    //Menu para seleccionar que funcion se va a utilizar     
    cout<<"a)  Alta de Especialidades Medicas"<<endl;
    cout<<"b)  Modificación de Especialidades Medicas"<<endl;
    cout<<"c)  Baja de Especialidades Medicas"<<endl;
    cout<<"d)  Listado de Especialidades Medicas"<<endl;
    cout<<"e)  Volver al menu Principal" <<endl;

    cin >> menu_opcion_espemed ;

    //Swich para seleccionar que tipo de funcion se eligio 
    switch (menu_opcion_espemed ){
        
        case 'a':
            AltaEspeMed(arrayEspMed, indiceEspMed );

            break;
            
        case 'b':
       
            ModificarEspeMed(arrayEspMed,indiceEspMed);
            
            break;
            
        case 'c':
            BajaEspeMed(arrayEspMed,arrayTurnos,indiceEspMed,indiceTurnos);
            break;
            
        case 'd':
            ListadoEspeMed();
            break;
            
         case 'e':
            break;
            
         default:
            cout <<"Ustede no a selecionado ninguna de las opciones posibles" <<endl;
            cout<< endl;
            break;
            
         
}
}
}


void alta_turnos(datosTurnos arrayTurnos[],int & indiceTurnos,datosPaciente arrayPaciente[],int &  indicePaciente,datosEspMed arrayEspMed[],int & indiceEspMed)
{
    datosTurnos turnoTemp;
    string dia;
    string mes;
    string year;
    string hora;
    string minutos;
    bool comprobador = false;
    do
    {
        cout << "Ingrese el dia del turno: ";
        cin >> dia;
        cout << endl;
        cout << "Ingrese el mes del turno (valor numerico): ";
        cin >> mes;
        cout << endl;
        cout << "Ingrese el año del turno (completo): ";
        cin >> year;
        cout << endl;
        comprobador = esUnNumeroFunc(dia + mes + year);
    } while (comprobador == false);
    comprobador = false;
    do
    {
        cout << "Ingrese la hora del turno HH: ";
        cin >> hora;
        cout << endl;
        cout << "Ingrese los minutos del turno MM: ";
        cin >> minutos;
        cout << endl;
        comprobador = esUnNumeroFunc(hora + minutos);
    } while (comprobador == false);
    do
    {
        comprobador == false;
        cout << "Ingrese el DNI del paciente: ";
        cin >> turnoTemp.paciente;
        cout << endl;
        for (int i = 0; i < indicePaciente; i++)
        {
            if (arrayPaciente[i].dni ==turnoTemp.paciente)
            {
                comprobador == true;
            }
        };
        if (comprobador == false){
            cout << "El DNI que ingreso no se encuenta en la base de datos, registrelo primero en Administrar Pacientes o ingrese otro DNI"; 
            cout << endl;
        }
    } while (comprobador == false);
    do
    {
        comprobador == false;
        cout << "Ingrese la especialidad medica: ";
        cin >> turnoTemp.especialidadMedica;
        cout << endl;
        for (int i = 0; i < indiceEspMed; i++)
        {
            if (turnoTemp.especialidadMedica == arrayEspMed[i].codigo)
            {
                comprobador == true;
            }
        };
        if (comprobador == false){
            cout << "La especialidad medica no se encuentra en la base de datos, registrela en Administrar Especialidades Medicas o ingrese otra" ;
            cout << endl;
        }
    } while (comprobador == false);
    cout << "Ingrese el DNI del paciente: ";
    cin >> turnoTemp.paciente;
    cout << endl;
    cout << "Ingrese la especialidad medica: ";
    cin >> turnoTemp.especialidadMedica;
    cout << endl;
    for (int i = 0; i <= indiceTurnos; i++)
    {
        if ((turnoTemp.paciente == arrayTurnos[i].paciente) && (turnoTemp.especialidadMedica == arrayTurnos[i].especialidadMedica))
        {
            cout << "Ya existe un turno para ese paciente en esa especialidad medica";
            cout << endl;
            return;
        }
    };
    arrayTurnos[indiceTurnos].codigo = indiceTurnos;
    arrayTurnos[indiceTurnos].especialidadMedica = turnoTemp.especialidadMedica;
    arrayTurnos[indiceTurnos].estado = 1;
    arrayTurnos[indiceTurnos].fecha = (dia + "/" + mes + "/" + year);
    arrayTurnos[indiceTurnos].hora = hora;
    arrayTurnos[indiceTurnos].minutos = minutos;
    arrayTurnos[indiceTurnos].paciente = turnoTemp.paciente;
    indiceTurnos++;
}

int indiceTurnoBuscado(datosTurnos arrayTurnos[], int indiceTurno[], int indice)
{
    int indiceTemp = 0;
    string dniIngresado;
    bool dniComprobado = 0;
    cout << "Ingrese el DNI del paciente: ";
    cin >> dniIngresado;
    cout << endl;
    for (int i = 0; i < indice; i++)
    {
        if (dniIngresado == arrayTurnos[i].paciente)
        {
            dniComprobado = 1;
            indiceTurno[indiceTemp] = i;
            indiceTemp++;
        }
    }
    if (dniComprobado == 0)
    {
        cout << "El DNI que ingreso no tiene un turno asignado";
        cout << endl;
    }
    return (indiceTemp - 1);
}

void modificaciones(datosTurnos arrayTurnos[], int indice)
{
    if (indice == 0)
    {
        cout << "No Hay ningun turno registrado";
        cout << endl;
        return;
    }
    int indiceTurno[indice];
    int maxIndice = indiceTurnoBuscado(arrayTurnos, indiceTurno, indice);
    if (maxIndice == -1)
    {
        cout << "volvera al menu principal";
        cout << endl;
        return;
    }
    cout << "Los datos de el/los turnos a modificar son los siguientes:";
    cout << endl;
    for (int i = 0; i <= maxIndice; i++)
    {
        cout << "Codigo: " << arrayTurnos[indiceTurno[i]].codigo << endl;
        cout << "Fecha: " << arrayTurnos[indiceTurno[i]].fecha << endl;
        cout << "Hora: " << arrayTurnos[indiceTurno[i]].hora << endl;
        cout << "Paciente: " << arrayTurnos[indiceTurno[i]].paciente << endl;
        cout << "Especialidad medica: " << arrayTurnos[indiceTurno[i]].especialidadMedica << endl;
        cout << "Estado: " << arrayTurnos[indiceTurno[i]].estado << endl;
        cout << endl;
    }
    int indiceMod;
    bool comprobador = false;
    do
    {
        cout << "Seleccionar el codigo del turno a modificar: ";
        cin >> indiceMod;
        cout << endl;
        for (int i = 0; i <= maxIndice; i++)
        {
            if (indiceMod == arrayTurnos[indiceTurno[i]].codigo)
            {
                comprobador = true;
            }
        }
        if (comprobador == false)
        {
            cout << "El codigo seleccionado no se encuentra en los turnos mostrados";
            cout << endl;
        }
    } while (comprobador == false);
    string dia;
    string mes;
    string year;
    comprobador = false;
    do
    {
        cout << "Ingrese el dia del turno: ";
        cin >> dia;
        cout << endl;
        cout << "Ingrese el mes del turno (valor numerico): ";
        cin >> mes;
        cout << endl;
        cout << "Ingrese el año del turno (completo): ";
        cin >> year;
        cout << endl;
        comprobador = esUnNumeroFunc(dia + mes + year);
    } while (comprobador == false);
    arrayTurnos[indiceMod].fecha = (dia + "/" + mes + "/" + year);
    cout << "Ingrese la hora del turno HH:MM: ";
    cin >> arrayTurnos[indiceMod].hora;
    cout << endl;
    cout << "La operacion se realizo con exito";
    cout << endl;
}

void baja_turnos(datosTurnos arrayTurnos[], int indice)
{
    if (indice == 0)
    {
        cout << "No Hay ningun turno registrado";
        cout << endl;
        return;
    }
    int indiceTurno[indice];
    int maxIndice = indiceTurnoBuscado(arrayTurnos, indiceTurno, indice);
    if (maxIndice == -1)
    {
        cout << "volvera al menu principal";
        cout << endl;
        return;
    }
    if (maxIndice == 0)
    {
        cout << "Los datos de el turnos a eliminar son los siguientes:";
        cout << endl;
        cout << "Codigo: " << arrayTurnos[indiceTurno[maxIndice]].codigo << endl;
        cout << "Fecha: " << arrayTurnos[indiceTurno[maxIndice]].fecha << endl;
        cout << "Hora: " << arrayTurnos[indiceTurno[maxIndice]].hora << endl;
        cout << "Paciente: " << arrayTurnos[indiceTurno[maxIndice]].paciente << endl;
        cout << "Especialidad medica: " << arrayTurnos[indiceTurno[maxIndice]].especialidadMedica << endl;
        cout << "Estado: " << arrayTurnos[indiceTurno[maxIndice]].estado << endl;
        cout << endl;
    }
    if (maxIndice > 0)
    {
        cout << "Los datos de los turnos que puede eliminar son los siguientes:";
        cout << endl;
        for (int i = 0; i <= maxIndice; i++)
        {
            cout << "Codigo: " << arrayTurnos[indiceTurno[i]].codigo << endl;
            cout << "Fecha: " << arrayTurnos[indiceTurno[i]].fecha << endl;
            cout << "Hora: " << arrayTurnos[indiceTurno[i]].hora << endl;
            cout << "Paciente: " << arrayTurnos[indiceTurno[i]].paciente << endl;
            cout << "Especialidad medica: " << arrayTurnos[indiceTurno[i]].especialidadMedica << endl;
            cout << "Estado: " << arrayTurnos[indiceTurno[i]].estado << endl;
            cout << endl;
        }
    }
    int indiceElim;
    bool comprobador = false;
    do
    {
        cout << "Seleccionar el codigo del turno a modificar: ";
        cin >> indiceElim;
        cout << endl;
        for (int i = 0; i <= maxIndice; i++)
        {
            if (indiceElim == arrayTurnos[indiceTurno[i]].codigo)
            {
                comprobador = true;
            }
        }
        if (comprobador == false)
        {
            cout << "El codigo seleccionado no se encuentra en los turnos mostrados";
            cout << endl;
        }
    } while (comprobador == false);
    struct tm *fecha;
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    fecha = localtime(&currentTime);
    int horaActual = fecha->tm_hour;
    int minutoActual = fecha->tm_min;
    int valorTiempoActual = (horaActual + (minutoActual / 60));
    int valorTiempoTurno = (stoi(arrayTurnos[indiceElim].hora) + (stoi(arrayTurnos[indiceElim].minutos) / 60));
    if ((valorTiempoTurno - valorTiempoActual) < 24)
    {
        cout << "Por razones de agenda, el turno no puede ser cancelado";
        cout << endl;
        return;
    }
    else
    {
        arrayTurnos[indiceElim].estado = 2;
        cout << "El Turno se ah cancelado con exito";
        cout << endl;
    }
}

void listado_completo()
{
    cout << "Se ingreso a la funcion listado completo" << endl;
    cout << "Presione ENTER para continuar";
    cin.get();
    cout << endl;
}

void listado_busqueda()
{

    cout << "Se ingreso a la funcion listado por busqueda" << endl;
    cout << "Presione ENTER para continuar";
    cin.get();
    cout << endl;
}

void listado()
{
    char menu_listados = 'A';
    cout << "Se ingreso a la funcion listas, elija la acción que desea realizar" << endl;
    do
    {

        cout << "f) listado completo" << endl;
        cout << "g) listado por busqueda" << endl;
        cout << "h) volver al menu" << endl;

        cin >> menu_listados;
        switch (menu_listados)
        {
        case 'f':
            listado_completo();
            break;
        case 'g':
            listado_busqueda();
            break;
        default:
            cout << "Ha ingresado un caracter invalido" << endl;
            cout << endl;
            break;
        case 'h':
            break;
        }
    } while (menu_listados != 'h');
}

void mainTurnos(datosTurnos arrayTurnos[], int &  indiceTurnos, datosPaciente arrayPaciente[], int &  indicePaciente, datosEspMed arrayEspMed[], int & indiceEspMed)
{

    char menu_de_opciones = 'A';
    do
    {
        cout << endl;
        cout << "Elija la accion que desea realizar" << endl;
        cout << "a) Alta de Turnos" << endl;
        cout << "b) Modifcacion de turnos" << endl;
        cout << "c) Baja de Turnos" << endl;
        cout << "d) Listado de Turnos" << endl;
        cout << "e) Volver al menu principal" << endl;

        cin >> menu_de_opciones;

        switch (menu_de_opciones)
        {
        case 'a':
            alta_turnos(arrayTurnos, indiceTurnos, arrayPaciente, indicePaciente, arrayEspMed, indiceEspMed);
            cout << indiceTurnos;
            cout << endl;
            break;
        case 'b':
            modificaciones(arrayTurnos, indiceTurnos);
            break;
        case 'c':
            baja_turnos(arrayTurnos, indiceTurnos);
            break;
        case 'd':
            listado();
            break;
        case 'e':
            break;
        default:
            cout << "Ha ingresado un caracter invalido" << endl;
            break;
        }
    } while (menu_de_opciones != 'e');
}

int main()
{
    const int dim = 1000;
    datosTurnos arrayTurnos[dim];
    int indiceTurnos = 0;
    datosEspMed arrayEspMed[dim];
    int indiceEspMed = 0;
	datosPaciente arrayPaciente[dim];
	int indicePaciente = 0;
	
	char menuPrincipal= 'A';
 	
 	do{
 		cout<<endl;
 		cout<<"Elija una de las opciones"<<endl;
 		cout<<"1. Administrar Especialidades Médicas"<<endl;
 		cout<<"2. Administrar Pacientes"<<endl;
 		cout<<"3. Administrar Turnos"<<endl;
 		cout<<"4. Salir"<<endl;
 	  
	 	
 		cin>>menuPrincipal;
 		
 		switch (menuPrincipal){
 			case '1':

 				mainEspMed(arrayEspMed,indiceEspMed,arrayTurnos,indiceTurnos);
 				
 				break;
 			case'2':
 				mainPacientes(arrayPaciente,indicePaciente,arrayTurnos,indiceTurnos);
 				
 				break;
 			case '3':
 			    mainTurnos(arrayTurnos,indiceTurnos, arrayPaciente,indicePaciente, arrayEspMed,indiceEspMed);
 				
 				break;
 			case'4':
 	
 				break;
 			default:
 				cout<<"Ha ingresado un caracter invalido"<<endl;
 				
 				break;
 				
	
		 }
       }while(menuPrincipal !='4');
       return 0;
}