// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

long long int fib(const int n){
    if(n == 0) return 0;
    else if(n == 1 || n == 2) return 1;
    else{
        long long int p1 = 1;
        long long int p2 = 1;
        long long int fib = 2;
        int i = 3;
        while(i < n){
            p1 = p2;
            p2 = fib;
            fib = p1+p2;
            ++i;
        }
        return fib;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    std::cin >> n;
    if(n == -1) return false;
    else{
        long long int num = fib(n);
        std::cout << num << std::endl;
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
