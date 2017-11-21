
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <list>
#include "TreeMap.h"
#include "horas.h"

using namespace std;

// lee los datos del árbol y los inserta utilizando el metodo insert
template <class T1, class T2>
void leerArbol (TreeMap<T1, T2> & a, T1 const& finalDatos){
	T1 n1; T2 n2;
	cin >> n1;
	while (n1 != finalDatos) {
		cin >> n2;
		a.insert(n1,n2);
		cin >> n1;
	}
}

bool resolverCaso(){
	int k; // k-esima clave
	cin >> k;
	if (!cin) return false;
	TreeMap<horas, string> a;
	horas finalDatos; // inicializa la hora a 00:00:00
	leerArbol(a, finalDatos);
	try {  // LLama a la funcion consultaK del arbol de busqueda
		TreeMap<horas, string>::ConstIterator it = a.consultaK(k);
		cout << it.key() << ' ' << it.value() << '\n';
	}
	catch (invalid_argument const& e) {
		cout << "NO\n";
	}
	return true;
    
}


int main(){
#ifndef DOMJUDGE
    std::ifstream in("datos1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resolverCaso()){}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
