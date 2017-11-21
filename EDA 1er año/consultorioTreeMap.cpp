// Ejercicio 12 del tema 10
// Implementacion de un consultorio medico
// Se utiliza el tipo de datos TreeMap.h
// El listado de los medicos es ordenado por orden alfabetico.

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <utility>
#include <list>

#include "TreeMap.h"

using namespace std;


typedef string medico;
typedef string paciente;
typedef list<paciente> colaPacientes;

class consultorio {
	TreeMap< medico,colaPacientes > tabla;
public:
	void nuevoMedico(medico const& m);
	list<medico> listadoMedicos();
	void pideConsulta(medico const& m, paciente const& p);
	paciente const& siguientePaciente(medico const& m);
	void atiendeConsulta(medico const& m);
	colaPacientes const& listaPacientes(medico const & m);
};

// Añade un medico al consultorio
// Si ya se encuentra no hace nada
void consultorio::nuevoMedico(medico const& m) {
	if (!tabla.contains(m))
    tabla.insert(m,colaPacientes());
}

// Recorre la tabla mostrando los medicos (en cualquier orden)
list<medico> consultorio::listadoMedicos() {
	list<medico> l;
	TreeMap< medico,colaPacientes >::ConstIterator it = tabla.cbegin();
	TreeMap< medico,colaPacientes >::ConstIterator itFin = tabla.cend();
	while (it != itFin) {
		l.push_back(it.key());
		++it;
	}
	return l;
}

// Añade un paciente a la cola de pacientes de un medico
// Si el médico no existe lanza una excepcion
void consultorio::pideConsulta(medico const& m, paciente const& p){
	if (tabla.contains(m)){
		colaPacientes l = tabla.at(m);
		l.push_back(p);
		tabla.insert(m,l);
	}
	else throw invalid_argument("medico inexistente");
}

// Obtiene el siguiente paciente de un medico
paciente const& consultorio::siguientePaciente(medico const& m){
	try {
		if (tabla.at(m).size() > 0) return tabla.at(m).front();
		else throw invalid_argument("Sin pacientes");
	}
	catch (out_of_range & e) {throw out_of_range("medico inexistente");}
}

// elimina el primer elemento de la lista ed pacientes de un medico
// lanza excepcion si el medico no existe o si la lista de pacientes esta vacia
void consultorio::atiendeConsulta(medico const& m){
	if (tabla.contains(m)){
		if (tabla.at(m).size() > 0) {
			colaPacientes l = tabla.at(m);
			l.pop_front();
			tabla.insert(m,l);
		}
		else throw invalid_argument("Sin pacientes");
	}
	else throw out_of_range("medico inexistente");
}

// devuelve la lista de pacientes de un medico
colaPacientes const& consultorio::listaPacientes(medico const & m){
	return tabla.at(m);
}

// Muestra el contenido de una lista generica
template <class T>
void mostrar(list<T> const& l) {
	typename list<T>::const_iterator it = l.cbegin();
	typename list<T>::const_iterator itFin = l.cend();
	if (it != itFin) {
		cout << *it;
		++it;
	}
	while (it != itFin) {
		cout << ' ' << *it;
		++it;
	}
    
}

bool resolverCaso(){
	consultorio c;
	string nombreMedico;
	string nombrePaciente;
	string nombreOp;
	int numOp;
	cin >> numOp;
	if (!cin) return false;
	for (int i = 0; i < numOp; ++i) {
		cin >> nombreOp;
		if (nombreOp == "nuevoMedico") {
			cin >> nombreMedico;
			c.nuevoMedico(nombreMedico);
		}
		else if (nombreOp == "pideConsulta") {
			cin >> nombreMedico >> nombrePaciente;
			try {
				c.pideConsulta(nombreMedico,nombrePaciente);
			}
			catch (invalid_argument const& e) {
				cout << e.what() << '\n';
			}
		}
		else if (nombreOp == "siguientePaciente") {
			cin >> nombreMedico;
			try {
				cout << c.siguientePaciente(nombreMedico) << '\n';
			}
			catch (invalid_argument const& e) {
				cout << e.what() << '\n';
			}
			catch (out_of_range const& e) {
				cout << e.what() << '\n';
			}
		}
		else if (nombreOp == "atiendeConsulta") {
			cin >> nombreMedico;
			try {
				c.atiendeConsulta(nombreMedico);
			}
			catch (invalid_argument const& e) {
				cout << e.what() << '\n';
			}
			catch (out_of_range const& e) {
				cout << e.what() << '\n';
			}
		}
		else if (nombreOp == "listadoMedicos") {
			mostrar(c.listadoMedicos()); cout << '\n' ;
		}
		else if (nombreOp == "listaPacientes") {
			cin >> nombreMedico;
			mostrar(c.listaPacientes(nombreMedico)); cout << '\n' ;
		}
	}
	return true;
}

int main(){
#ifndef DOMJUDGE
    std::ifstream in("datos1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resolverCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
