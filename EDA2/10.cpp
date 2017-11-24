// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int sumaSinMax(const std::vector<int> &v){
    int max = -1;
    int numRepMax = 0;
    int suma = 0;
    int i = 0;
    while(i < v.size()){
        suma += v[i];
        if(v[i] > max){
            max = v[i];
            numRepMax = 1;
        }
        else if(v[i] == max) ++numRepMax;
        ++i;
    }
    suma = suma - max * numRepMax;
    return suma;
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
    int s = sumaSinMax(v);
    std::cout << s << std::endl;
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
