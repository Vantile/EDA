// Problema 1 del tema 11
// Implementacion de un sistema de venta de libros por internet

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <list>

using namespace std;



// Muestra el contenido de una lista
template <class T>
void mostrar(list<T> const& l) {
	typename list<T>::const_iterator it = l.cbegin();
	typename list<T>::const_iterator itFin = l.cend();
	while (it != itFin) {
		cout << *it << '\n';
		++it;
	}
    
}

bool resolverCaso(){
	ventaLibros c;
	string tituloLibro;
	int numUnidades;
	string nombreOp;
	int numOp;
	cin >> numOp;
	if (!cin) return false;
	for (int i = 0; i < numOp; ++i) {
		cin >> nombreOp;
		char aux;
		cin.get(aux); // lee el blanco despues del nombre de la operacion
		if (nombreOp == "nuevoLibro") {
			cin >> numUnidades;
			float precio;
			cin >> precio;
			char aux;
			cin.get(aux);
			getline(cin, tituloLibro);
			c.nuevoLibro(tituloLibro,numUnidades, precio);
		}
		else if (nombreOp == "comprar") {
			int num;
			cin >> num;
			getline(cin,tituloLibro);
			list<tlibro> l;
			for (int i = 0; i < num; ++i) {
				getline(cin,tituloLibro);
				l.push_back(tituloLibro);
			}
			try {
				float precioTotal = c.comprar(l);
				cout << fixed<< setprecision(2) << "Precio total " << precioTotal << "\n---\n";;
			}
			catch (out_of_range const& e) {
				cout << e.what() << '\n';
				cout << "---\n";
			}
			catch (invalid_argument const& e) {
				cout << e.what() << '\n';
				cout << "---\n";
			}
		}
		else if (nombreOp == "estaLibro") {
			getline(cin, tituloLibro);
			if (c.estaLibro(tituloLibro)) {
				cout << "El libro " << tituloLibro;
				cout << " esta en el sistema\n";
			}
			else {
				cout << "No existe el libro " << tituloLibro;
				cout << " en el sistema\n";
			}
			cout << "---\n";
		}
		else if (nombreOp == "elimLibro") {
			getline(cin, tituloLibro);
			c.elimLibro(tituloLibro);
		}
		else if (nombreOp == "numEjemplares") {
			getline(cin, tituloLibro);
			if (c.estaLibro(tituloLibro)) {
				cout << "Existen " << c.numEjemplares(tituloLibro);
				cout << " ejemplares del libro " << tituloLibro << '\n';
			}
			else {
				cout << "No existe el libro " << tituloLibro;
				cout << " en el sistema\n";
			}
			cout << "---\n";
		}
		else if (nombreOp == "top10") {
			mostrar(c.top10());
			cout << "---\n";
		}
		else if (nombreOp == "pedido") {
			int n;
			cin >> n;
			mostrar(c.pedido(n));
			cout << "---\n";
		}
	}
	return true;
}

int main(){
#ifndef DOMJUDGE
    std::ifstream in("datos1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resolverCaso()){ cout << "------\n";}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
