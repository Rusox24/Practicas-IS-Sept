#include "Cliente.h"
#include <string>

using namespace std;

//Inicializamos la clase
Cliente::Cliente() { }

Cliente::Cliente(string nombre, string apellidos, string DNI, string nacimiento, string telefono, Citas citas){
	setNombre(nombre);
	setApellidos(apellidos);
	setDni(DNI);
	setNacimiento(nacimiento);
	setTelefono(telefono);
	setCitas(citas);
}


Cliente::~Cliente() {
	
}

const string& Cliente::getNombre() const {
	return nombre_;
}

void Cliente::setNombre(const string& nombre) {
	nombre_ = nombre;
}

const string& Cliente::getApellidos() const {
	return apellidos_;
}

void Cliente::setApellidos(const string& apellidos) {
	apellidos_ = apellidos;
}

const string& Cliente::getDni() const {
	return DNI_;
}

void Cliente::setDni(const string& dni) {
	DNI_ = dni;
}

const string& Cliente::getNacimiento() const {
	return nacimiento_;
}

void Cliente::setNacimiento(const string& nacimiento) {
	nacimiento_ = nacimiento;
}

const string& Cliente::getTelefono() const {
	return telefono_;
}

void Cliente::setTelefono(const string& telefono) {
	telefono_ = telefono;
}

const Citas& Cliente::getCitas() const {
	return citas_;
}

void Cliente::setCitas(const Citas& citas) {
	citas_ = citas;
}
