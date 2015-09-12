#ifndef AGENDA_H_
#define AGENDA_H_


#include "Cliente.h"
#include <list>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

class Agenda {

private:


	string nombreFichero_;
	list <Cliente> arrayClientes_;

public:
	Agenda(string ficheroAgenda="Agenda.txt");

	virtual ~Agenda();

	bool insertarCliente();
	void introducirEnLista(const Cliente &c);
	void imprimirListaComprobando( list <Cliente> aux, const string &nombre);

	bool borrarCliente(string nombre);
	Cliente sacarClienteListaComprobando(list <Cliente> &aux,  int posicion);
	void eliminarClienteListaComprobando(Cliente caux);

	bool modificarCliente(string nombre);
	void modificarClienteListaComprobando(list <Cliente> &laux, Cliente &caux);

	list <Cliente> buscarCliente(string nombre);
	void AumentarNumeroCliente(list<Cliente> lista);
	bool ordenarClientes();
	static bool funcionOrdenacion(Cliente first, Cliente second);

	void imprimirLista(list<Cliente> Lista);
	void imprimeCliente(Cliente C);

	bool hacerCopiaSeguridad(string ficheroCopia);
	bool restaurarCopiaSeguridad(string ficheroCopia);

	inline const list<Cliente>& getArrayClientes() const {return arrayClientes_;};

	inline void setArrayClientes(const list<Cliente>& arrayClientes) {arrayClientes_ = arrayClientes;};

	inline const string& getNombreFichero() const {return nombreFichero_;};

	inline void setNombreFichero(const string& nombreFichero) {nombreFichero_ = nombreFichero;};

	bool ficheroALista();
	bool listaAFichero();
};

#endif
