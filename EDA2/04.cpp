// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::vector<int> acumula(const std::vector<int> &v){
    std::vector<int> sol(v.size());
    int n = v.size();
    sol[n-1] = v[n-1];
    int suma = v[n-1];
    int i = n-2;
    while(i >= 0){
        suma += v[i];
        sol[i] = suma;
        --i;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::vector<int> v;
	int num;
	std::cin >> num;
	while(num != 0){
		v.push_back(num);
		std::cin >> num;
	}
	if(v.size() == 0) return false;
	else{
		std::vector<int> result = acumula(v);
        int i = 0;
        while(i < result.size()){
            std::cout << result[i];
            if(i < result.size()-1) std::cout << " ";
			++i;
        }
        std::cout << std::endl;
	    return true;
	}

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
