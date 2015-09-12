#include "Agenda.h"
#include "Cliente.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>

 using namespace std;

//Constructor de clase

	Agenda::Agenda(string ficheroAgenda) {

		list <Cliente> aux;
		aux = getArrayClientes();

		setNombreFichero(ficheroAgenda);
		aux.clear();
		setArrayClientes(aux);
	}


	Cliente pedirDatos(){

		Cliente aux;

//Variables 

		string nombre="", apellidos="", DNI="", nacimiento="", telefono="";
		char opcion;
		int opcionMenu;

		string fecha="";
		string hora="";
		string motivo="";
		Citas citas;

		cout<<"Introduce el nombre: ";
		getline(cin, nombre);
		cout<<"Introduce los apellidos: ";
		getline(cin, apellidos);
		cout<<"Introduce DNI: ";
		getline(cin, DNI);
		cout<<"Introduce Telefono: ";
		getline(cin, telefono);
		cout<<"Introduce fecha nacimiento: ";
		getline(cin, nacimiento);

		cout<<endl<<"Introduzca los datos de la cita"<<endl;
		cout<<"\t1.Fecha"<<endl;
		getline(cin, fecha);
		citas.fecha = fecha;
		cout<<"\t2.Hora"<<endl;
		getline(cin, hora);
		citas.hora = hora;
		cout<<"\t3.Motivo"<<endl;
		getline(cin, motivo);
		citas.motivo = motivo;

//Volcamos la informacion recogida en el cliente auxiliar

		aux.setNombre(nombre);
		aux.setApellidos(apellidos);
		aux.setDni(DNI);
		aux.setNacimiento(nacimiento);
		aux.setTelefono(telefono);
		aux.setCitas(citas);

		return (aux);
	}


//Funcion para insertar cliente

	bool Agenda::insertarCliente(){

		string nombre;
		list<Cliente> aux;
		Cliente c;

    	int elementos;
    	int opcion;
    	int posicion;

	cout<<endl<<endl<<"Introduce el nombre del cliente: ";
	getline(cin, nombre);

	aux = buscarCliente(nombre);
    	elementos = aux.size();

//Realizamos un check inicial para verificar si ya existe

   		if(elementos==0){
 
       cout << endl << "El cliente no existe, introduzca los datos" << endl;

//Pide los datos por pantalla y devuelve el cliente con esos datos
			c = pedirDatos();
			introducirEnLista(c);
			ordenarClientes();
				return (true);

		}else{
//Imprime la lista de clientes con ese nombre
			imprimirListaComprobando(aux, nombre);
			do{

				cout<<endl<<"Introduce una opcion: "<<endl;
				cout<<"\t0. Salir";
				cout<<"\t1. Modificar un cliente"<<endl;
				cout<<"\t2. Insertar nuevo cliente"<<endl;
				cout<<"OPCION -> ";
				cin>>opcion;

				switch(opcion){

					case 0: 
							return(false);
							break;

					case 1: 
						cout<<endl<<"Introduzca el numero de cliente: ";
						cin>>posicion;
						getchar();
						//Saca el cliente de la lista aux y lo modifica en ArrayClientes
						c = sacarClienteListaComprobando(aux, posicion);
			      			modificarClienteListaComprobando(arrayClientes_, c);
			      			ordenarClientes();
						//Reordenamos la lista
			      			return(true);
			      			break;

			      	case 2:	
			      			getchar();
			      			c = pedirDatos();
						introducirEnLista(c);
						ordenarClientes();
						return(true);
						break;

					default: cout<<endl<<"OPCION NO VALIDA"<<endl<<endl;

				}


			}while((opcion!=0)&&(opcion!=1)&&(opcion!=2));

			return (false);//El cliente ya existe
		}
	}

void Agenda::introducirEnLista(const Cliente &c){
	list<Cliente> array;
	array = getArrayClientes();
	array.push_back(c);
	setArrayClientes(array);
}

//Imprime la lista de clientes con el mismo nombre
					
void Agenda::imprimirListaComprobando( list <Cliente> aux, const string &nombre){
					
list<Cliente>::iterator i;				
int j=1;				
cout<<endl<<"Clientes localizados con nombre: < '"<<nombre<<"' >"<<endl;			

	for(i=aux.begin(); i!=aux.end(); ++i){
	if((i->getNombre())==nombre){
	cout<<"\t"<<j<<" ) Cliente con nombre < "<<i->getNombre()<<", "<<i->getApellidos()<<" > y DNI < "<<i->getDni()<<" >"<<endl<<endl;
	j++; }
	  }
	}


bool Agenda::ordenarClientes(){

	list<Cliente> aux;
	aux = getArrayClientes();
	aux.sort(funcionOrdenacion);

	setArrayClientes(aux);

	return(true);

}

bool Agenda::funcionOrdenacion(Cliente first, Cliente second){

    	string aux1,aux2;

    	aux1=first.getNombre();
    	aux2=second.getNombre();

    	return(aux1<aux2);

    }


list <Cliente> Agenda::buscarCliente(string nombre){

	list <Cliente> aux;
	list <Cliente> array;
	list <Cliente>::iterator it;

	array = getArrayClientes();

	for(it=array.begin();it!=array.end();++it){

		if(it->getNombre()==nombre){
			aux.push_back(*it);
		}

	}

	return(aux);

}


//Funcion Borrado
bool Agenda::borrarCliente(string nombre){

//Declaracion de variables
list<Cliente> aux;
int elementos;
Cliente c;
int posicion;

//Primero busca si existen clientes con ese nombre y devuelve una lista con ellos
aux = buscarCliente(nombre);
elementos = aux.size();
if(elementos!=0){
//Imprime la lista comprobando el nombre
imprimirListaComprobando(aux, nombre);
//Pide el numero del usuario, y segun la posicion lo saca y lo borra de ArrayClientes
cout<<endl<<"Introduce el numero del cliente para eliminar: ";
cin>>posicion;
c = sacarClienteListaComprobando(aux, posicion);
eliminarClienteListaComprobando(c);
return (true);
 }else{
return (false); /*NO SE ENCUENTRA EL CLIENTE O YA ESTA BORRADO*/
    }
}



Cliente Agenda::sacarClienteListaComprobando(list <Cliente> &aux, int posicion){


list<Cliente>::iterator i;
int j=1;
int elementos = aux.size();
Cliente caux;
 if(elementos==1){
	     i=aux.begin();
	     caux = *i;
	        }else{
	for(i=aux.begin(); i!=aux.end(); ++i){
	if(j==posicion){
	caux = *i;

		}
	j++;
	}
  }

return (caux);
}

void Agenda::eliminarClienteListaComprobando(Cliente caux){

string DNI;
DNI = caux.getDni();
list<Cliente>::iterator i;
list<Cliente> aux = getArrayClientes();
int elementos = aux.size();

        	if(elementos==1){
        			i=aux.begin();
        			i=aux.erase(i);
      		}else{
					for(i=aux.begin(); i!=aux.end(); ++i){
						if(DNI==i->getDni()){
							i=aux.erase(i);
						}
					}
      		}
        		setArrayClientes(aux);
	}


bool Agenda::modificarCliente(string nombre){

list<Cliente> aux;
int elementos;
Cliente c;
int posicion;
//Primero busca si existen clientes con ese nombre y devuelve una lista con ellos
aux = buscarCliente(nombre);
//Comprueba si hay clientes con ese nombre o no, es decir, si hay elementos en la lista
elementos = aux.size();

  if(elementos!=0){
 //Imprime la lista comprobando el nombre
     imprimirListaComprobando(aux, nombre);
  //Pide el numero del usuario, y segun la posicion lo saca y pregunta que desea modificar
			    cout<<endl<<"Introduce el numero del cliente para modificar: ";
			    cin>>posicion;
			    c = sacarClienteListaComprobando(aux, posicion);
	      		    modificarClienteListaComprobando(arrayClientes_, c);//Lo modifica directamente en arrayClientes
 			    return (true);
		}else{
			return (false); 
		}
	}

void Agenda::modificarClienteListaComprobando(list <Cliente> &laux, Cliente &caux){

		string DNI="";
		DNI = caux.getDni();
		list<Cliente>::iterator i;
		int opcion;

		string nombre="", apellidos="", nacimiento="", telefono="";
		char favorito;
		int opcionMenu;

		string fecha="";
		string hora="";
		string motivo="";
		Citas citas;



		//Busca en toda la lista de arrayClientes, el cliente con el mismo dni que el dni del cliente del parametro.
		for(i=laux.begin(); i!=laux.end(); ++i){
			if(DNI==i->getDni()){ //SI EL DNI DEL CLIENTE DE LA LISTA COINCIDE CON EL PARAMETRO DEL DNI
				do{
					//Muestra un menu para seleccionar que desea modificar de ese cliente
					cout<<"¿Que desea modificar?"<<endl;
					cout<<"\t1.Nombre"<<endl;
					cout<<"\t2.Apellidos"<<endl;
					cout<<"\t3.DNI"<<endl;
					cout<<"\t4.Telefono"<<endl;
					cout<<"\t5.Nacimiento"<<endl;
					cout<<"\t6.Citas"<<endl;
					cout<<"\t0. SALIR"<<endl;
					cout<<"Opcion: ";
					cin>>opcion;
                    getchar();
					switch(opcion){
						case 0: break;

						case 1:	cout<<"Introduce el nuevo nombre: ";
								getline(cin, nombre);
								i->setNombre(nombre);
								break;

						case 2:	cout<<"Introduce los nuevos apellidos: ";
								getline(cin, apellidos);
								i->setApellidos(apellidos);
								break;

						case 3:	cout<<"Introduce el nuevo dni: ";
								getline(cin, DNI);
								i->setDni(DNI);
								break;
						case 4:	cout<<"Introduce el nuevo telefono: ";
								getline(cin, telefono);
								i->setTelefono(telefono);
								break;

						case 5:	cout<<"Introduce nacimiento: ";
								getline(cin,nacimiento);
								i->setNacimiento(nacimiento);
								break;


						case 6:	do{
									cout<<"¿Que dato desea modificar?"<<endl;
									cout<<"\t1.Fecha"<<endl;
									cout<<"\t2.Hora"<<endl;
									cout<<"\t3.Motivo"<<endl;
									cout<<"\t0.Salir"<<endl;
									cout<<"Opcion: ";
									cin>>opcionMenu;
									getchar();

									switch(opcionMenu){

										case 0: break;

										case 1: cout<<"Introduce la fecha: ";
												cin>>fecha;
												citas.fecha=fecha;
												break;

										case 2: cout<<"Introduce la hora: ";
												cin>>hora;
												citas.hora=hora;
												break;

										case 3: cout<<"Introduce el motivo: ";
												cin>>motivo;
												citas.motivo=motivo;
												break;

										default: cout<<"OPCION NO VALIDA";
												break;
									}

								}while(opcionMenu!=0);
													i->setCitas(citas);
								break;

						
					}
					}while(opcion!=0);
					
				}
			}
}


//Funcion para imprimir la lista
void Agenda::imprimirLista(list<Cliente> Lista){

 list<Cliente>::iterator i;

      if(!Lista.empty()){
		      for(i = Lista.begin(); i != Lista.end(); ++i){
		      imprimeCliente(*i);
		    }
      }else{
        cout << "No hay clientes en la lista para imprimir" << endl << endl;
      }
	}

//Función que imprimirá un cliente por pantalla, el cual ha sido pasado por parametro
//Estará impreso siguiendo unos estandares de calidad
void Agenda::imprimeCliente(Cliente C){

Citas citas;
int buscado;

  //Mostramos el nombre
    cout << " CLIENTE--->" << C.getNombre() << ", "<< C.getApellidos() << endl;

  //Mostramos el dni
    cout << "\tDNI - < " << C.getDni()<< " >"<<endl;

  //Mostramos el Telefono
    cout << "\tTelefono - < " << C.getTelefono()<< " >"<<endl;

  //Mostramos la fecha de nacimiento del cliente
  cout << "\t*Fecha Nacimiento*"<<endl;
  cout << "\t"<<C.getNacimiento() << endl;

  //Mostramos las citas
    citas = C.getCitas();
    cout << "\tCitas Previstas"<<endl;
    cout << "\t\t- Fecha:\t" << citas.fecha <<endl;
    cout << "\t\t- Hora:\t" << citas.hora <<endl;
    cout << "\t\t- Motivo:\t" << citas.motivo <<endl;

  cout << endl << endl;

}


//Funcion para realizar copia de seguridad

bool Agenda::hacerCopiaSeguridad(string ficheroCopia){
char line[20000];

		ifstream fileAgenda;
		ofstream fileCopia;
		fileAgenda.open("Agenda.txt");
		if(fileAgenda.fail()){
			return false;
		}

		fileCopia.open(ficheroCopia.c_str());
		if(!(fileCopia.fail())){
			fileCopia.close();
			remove (ficheroCopia.c_str());
			fileCopia.open(ficheroCopia.c_str());
		}

		while(fileAgenda.getline(line,20000,'\n')){
			fileCopia << line <<endl;
		}

		fileAgenda.close();
		fileCopia.close();
		return true;
	}


//Funcion para restaurar copia de seguridad
bool Agenda::restaurarCopiaSeguridad(string ficheroCopia){
char line[20000];

		ofstream fileAgenda;
		ifstream fileCopia;

		fileCopia.open(ficheroCopia.c_str());
		if(fileCopia.fail()){
			return false;
		}

		fileAgenda.open("Agenda.txt");
		if(!(fileAgenda.fail())){
			fileAgenda.close();
			remove ("Agenda.txt");
			fileAgenda.open("Agenda.txt");
		}

		while(fileCopia.getline(line,20000,'\n')){
			fileAgenda << line <<endl;
		}

		fileAgenda.close();
		fileCopia.close();
		return true;
	}


//Funcion para pasar datos del fichero a la lista temporal

bool Agenda::ficheroALista(){
		char line[256];
		Cliente cl;
		list <Cliente> aux;
		Citas citas;
		ifstream fileAgenda;

		fileAgenda.open("Agenda.txt");
		if(fileAgenda.fail()){
			return false;
		}

    //Leemos el fichero y pasamos los datos de los clientes de uno en uno a la lista de clientes
		while(fileAgenda.getline(line,256,',')){
			cl.setNombre(line);

			fileAgenda.getline(line,256,',');
			cl.setApellidos(line);

			fileAgenda.getline(line,256,',');
			cl.setDni(line);

			fileAgenda.getline(line,256,',');
			cl.setNacimiento(line);

			fileAgenda.getline(line,256,',');
			cl.setTelefono(line);

			fileAgenda.getline(line,256,',');
			citas.fecha = line;
			fileAgenda.getline(line,256,',');
			citas.hora = line;
			fileAgenda.getline(line,256,',');
			citas.motivo = line;
			cl.setCitas(citas);

			aux.push_back(cl);
		}

		setArrayClientes(aux);

		fileAgenda.close();
		return true;

	}


//Funcion para pasar de la lista al fichero
	bool Agenda::listaAFichero(){
		char line[256];
		Cliente cl;
		Citas citas;
		list <Cliente> aux;
		aux = getArrayClientes();
		list <Cliente>::iterator pos;
		pos = aux.begin();
		ofstream fileAgenda;

    //Comprobamos si existe el fichero "Agenda.txt"
    //Y si existe, lo borramos y lo volvemos a crear en blanco
		fileAgenda.open("Agenda.txt");
		if(!(fileAgenda.fail())){
			fileAgenda.close();
			remove ("Agenda.txt");
			fileAgenda.open("Agenda.txt");
		}

    //Recorremos la lista de clientes y pasamos sus datos uno a uno al fichero
		while(pos != aux.end()){
			fileAgenda << (*pos).getNombre() << ',';
			fileAgenda << (*pos).getApellidos() << ',';
			fileAgenda << (*pos).getDni() << ',';
			fileAgenda << (*pos).getNacimiento() << ',';
			fileAgenda << (*pos).getTelefono() << ',';

			citas = (*pos).getCitas();
			fileAgenda << citas.fecha << ',';
			fileAgenda << citas.hora << ',';
			fileAgenda << citas.motivo << ',';

			pos++;
		}

		fileAgenda.close();
		return true;
	}
Agenda::~Agenda() {
}
