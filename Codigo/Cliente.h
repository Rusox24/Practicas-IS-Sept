#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <iostream>

 using namespace std;

//Generamos tipo de datos Citas 

typedef struct CitasDentista{
	string fecha;
	string hora;
	string motivo;
}Citas;

//Definicion de la clase cliente

class Cliente {

private:
	string nombre_;
	string apellidos_;
	string DNI_;
	string nacimiento_;
	string telefono_;
	Citas citas_;



public:
	Cliente(string nombre, string apellidos, string DNI, string nacimiento, string telefono, Citas citas);
	Cliente();
	virtual ~Cliente();


	const string& getNombre() const;
	void setNombre(const string& nombre);

	const string& getApellidos() const;
	void setApellidos(const string& apellidos);

	const string& getDni() const;
	void setDni(const string& dni);

	const string& getNacimiento() const;
	void setNacimiento(const string& nacimiento);

	const string& getTelefono() const;
	void setTelefono(const string& telefono);

	const Citas& getCitas() const;
	void setCitas(const Citas& citas);


};

#endif /* CLIENTE_H_ */
