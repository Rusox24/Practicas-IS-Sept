#include "Agenda.h"
#include "Cliente.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

char opcion='1';
Agenda aux("Agenda.txt");
string nombre;
string respuesta;
string copia;
list<Cliente> Buscados;

    cout<<endl<<endl<<endl<<endl;
    cout << "Agenda Electronica" << endl<<endl;

    if(aux.ficheroALista()){
        cout<<"Fichero cargado:"<<endl;
    }else{
        cout<<"Fallo al cargar fichero."<<endl<<endl;
    }

while(opcion != '0'){

    cout << "\tImprimir clientes por pantalla:   1\t" << endl;
    cout << "\tBuscar un cliente:                2\t" << endl;
    cout << "\tAñadir un cliente:                3\t" << endl;
    cout << "\tModificar un cliente:             4\t" << endl;
    cout << "\tBorrar un cliente:                5\t" << endl;
    cout << "\tSalir :                           0\t" << endl;

    cout << "Elija una de las siguientes opciones: " << endl;
    cout << "Opción -> ";
    cin >> opcion;
    getchar();

    switch(opcion){

      case '0': aux.listaAFichero();
              cout << endl<< "*** Bye !***" << endl<<endl;
              break;

      case '1':

              aux.imprimirLista(aux.getArrayClientes());
              break;

      case '2':
              Buscados.clear();
              cout << "Introduzca el nombre del cliente: " << endl;
              getline(cin,nombre);
              Buscados = aux.buscarCliente(nombre);
              if(!Buscados.empty()){
                aux.imprimirLista(Buscados);
              }else{
                cout << "El nombre introducido no existe en la agenda." << endl;
                do{
                  cout << "¿Añadir el cliente a la agenda? S/N " << endl;
                  cin >> respuesta;
                  getchar();
                  if(respuesta=="S"){
                    aux.insertarCliente();
                  }
                }while(respuesta!="S" && respuesta!="N");
              }
              break;

      case '3':
            if(aux.insertarCliente()){
      				cout<<"Se ha introducido el cliente con exito"<<endl;
      			}else{
      				cout<<"Ya existen clientes"<<endl;
      			}
              break;

      case '4':
              cout << "Introduzca el nombre del cliente que desea modificar" << endl;
              getline(cin,nombre);
              if(aux.modificarCliente(nombre)){
                cout << "Cliente modificado" << endl;
              }else{
                cout << "No existe ningun cliente con el nombre indicado" << endl;
                do{
                cout << "¿Añadir el cliente a la agenda? S/N " << endl;
                cin >> respuesta;
                if(respuesta=="S"){
                  getchar();
                  aux.insertarCliente();
                }
              }while(respuesta!="S" && respuesta!="N");
              }
              break;

      case '5':
              cout << "Introduzca el nombre del cliente que desea borrar" << endl;
              getline(cin,nombre);
              if(aux.borrarCliente(nombre)){
                cout << "Cliente borrado" << endl;
              }else{
                cout << "El cliente no se encuentra" << endl;
              }
              break;

      case '8':
              aux.listaAFichero();
              cout << "Introduzca nombre de fichero: " << endl;
              getline(cin,copia);
              if(aux.hacerCopiaSeguridad(copia)){
                cout <<endl<< "Hecho" << endl<<endl;
              }else{
                cout << "No se encuentra el fichero de la agenda" << endl;
              }
              break;

      case '9':
              cout << "Introduzca el nombre del fichero: " << endl;
              getline(cin,copia);
              if(aux.restaurarCopiaSeguridad(copia)){
                aux.ficheroALista();
                cout <<endl<< " Hecho" << endl<<endl;
              }else{
                cout << "No se encuentra el fichero a restaurar" << endl;
              }
              break;

      default:  cout << "Opción no valida" << endl;

    }

    if(opcion!='0'){
        cout<<endl<<"\tPulse ENTER para continuar...";
        getchar();
    }

}

  return 0;
}
