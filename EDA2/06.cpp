// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Sol{
    int vagon;
    int ganancia;
};

Sol vagonAsalto(const std::vector<int> &v, const int nAsalt){
    int i = 0;
    Sol sol;
    sol.vagon = 0;
    sol.ganancia = 0;
    int primerVagonActual = 0;
    int gananciaActual;
    while(i < nAsalt){
        sol.ganancia += v[i];
        ++i;
    }
    gananciaActual = sol.ganancia;
    while(i < v.size()){
        gananciaActual = sol.ganancia - v[primerVagonActual] + v[i];
        ++primerVagonActual;
        if(gananciaActual >= sol.ganancia){
            sol.ganancia = gananciaActual;
            sol.vagon = primerVagonActual;
        }
        ++i;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int nVag, nAsalt;
    std::cin >> nVag;
    std::cin >> nAsalt;
    std::vector<int> v;
    for(int i = 0; i < nVag; ++i){
        int gan;
        std::cin >> gan;
        v.push_back(gan); 
    }
    Sol sol = vagonAsalto(v, nAsalt);
    std::cout << sol.vagon << " " << sol.ganancia << std::endl;
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
