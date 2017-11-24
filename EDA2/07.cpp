// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct Sol{
	int ini;
	int fin;
};

Sol blancos(const std::vector<std::string> &v){
	Sol s;
	s.ini = 0;
	s.fin = -1;
	int priBlanco = -1;
	int ultBlanco = -1;
	int maxPriBlanco = -1;
	int maxUltBlanco = -1;
	int i = 0;
	while(i < v.size()){
		if(v[i] == "FFFFFF"){
			if(priBlanco == -1 && ultBlanco == -1){
				priBlanco = i;
				ultBlanco = i;
			} 
			else{
				++ultBlanco;
			}	
			if((maxPriBlanco == -1 && maxUltBlanco == -1) 
			|| (ultBlanco - priBlanco > maxUltBlanco - maxPriBlanco)){
				maxPriBlanco = priBlanco;
				maxUltBlanco = ultBlanco;
			}
		}
		else{
			priBlanco = -1;
			ultBlanco = -1;
		}
		++i;
	}
	if(maxPriBlanco != -1 && maxUltBlanco != -1){
		s.ini = maxPriBlanco;
		s.fin = maxUltBlanco;
	}
	return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas, pixels;
	std::cin >> filas;
	if(!std::cin) return false;
	std::cin >> pixels;
	for(int i = 0; i < filas; i++){
		int j = 0;
		std::vector<std::string> fila;
		while(j < pixels){
			std::string s;
			std::cin >> s;
			fila.push_back(s);
			++j;
		}
		Sol s = blancos(fila);
		std::cout << s.ini << " " << s.fin << std::endl;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	bool c = true;
	while (c){
		c = resuelveCaso();
		if(c) std::cout << std::endl;
	} 


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
