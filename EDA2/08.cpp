// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Sol{
    int ini;
    int fin;
};
// Coste O(n) siendo n el tamaño de v
Sol heights(const std::vector<int> &v, const int h){
    Sol s;
    int iniH = -1;
    int finH = -1;
    int maxIniH = -1;
    int maxFinH = -1;
    int i = 0;
    while(i < v.size()){
        if(v[i] > h){
            if(iniH == -1 && finH == -1){
                iniH = i;
                finH = i;
            }
            else ++finH;
            if((maxIniH == -1 && maxFinH == -1) || (finH - iniH > maxFinH - maxIniH)){
                maxIniH = iniH;
                maxFinH = finH;
            }
        }
        else{
            iniH = -1;
            finH = -1;
        }
        ++i;
    }
    s.ini = maxIniH;
    s.fin = maxFinH;
    return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, height;
    std::cin >> n;
    std::cin >> height;
    std::vector<int> v;
    for(int i = 0; i < n; ++i){
        int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    Sol s = heights(v, height);
    std::cout << s.ini << " " << s.fin << std::endl;
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
