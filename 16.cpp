// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Sol{
	int suma;
	bool deg;
};

Sol degradado(const std::vector<int> &v, const int ini, const int fin){
	Sol d;
	if (ini >= fin - 1){
		d.deg = true; d.suma = v[ini];
	}
	else{
		int mitad = (ini + fin) / 2;
		Sol m1 = degradado(v, ini, mitad);
		Sol m2 = degradado(v, mitad, fin);
		if (m1.deg && m2.deg && m1.suma < m2.suma) d.deg = true;
		else d.deg = false;
		d.suma = m1.suma + m2.suma;
	}
	return d;
}

// función que resuelve el problema
bool resolver(const int filas, const int columnas) {
	bool deg = true;
	for (int i = 0; i < filas; i++){
		std::vector<int> v;
		for (int j = 0; j < columnas; j++){
			int dato;
			std::cin >> dato;
			v.push_back(dato);
		}
		Sol d = degradado(v, 0, v.size());
		/*if (deg){
			int mitad = (v.size()) / 2;
			Sol m1 = degradado(v, 0, mitad);
			Sol m2 = degradado(v, mitad, v.size());
			if (m1.deg && m2.deg && m1.suma < m2.suma) deg = true;
			else deg = false;
		}*/
		if(!d.deg) deg = false;
	}
	return deg;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas, columnas;
	std::cin >> filas;

	if (!std::cin)
		return false;
	std::cin >> columnas;

	bool sol = resolver(filas, columnas);

	if (sol) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}