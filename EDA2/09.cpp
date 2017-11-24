// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Coste O(n) siendo n el tamaño de v.
int equilibrio(const std::vector<int> &v){
    if(v.size() == 0) return -1;
    int eq = 0;
    int posEq = -1;
    int i = 0;
    while(i < v.size()){
        if(v[i] == 1) ++eq;
        else if(v[i] == 0) --eq;
        if(eq == 0) posEq = i;
        ++i;
    }
    return posEq;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for(int i = 0; i < n; ++i){
        int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    int p = equilibrio(v);
    std::cout << p << std::endl;
    return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    int i = 0;
	while (i < numCasos){
        resuelveCaso();
        ++i;
    }


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
