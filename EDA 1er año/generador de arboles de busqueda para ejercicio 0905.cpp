
/*
 * Generador de árboles de busqueda
 * Para controlar el número y forma de los árboles que se generan modificar las constantes
 * MAX_CASOS indica el número de árboles que se generan
 * MAX_NODOS indica el número máximo de nodos. Los árboles pueden tener menos nodos de los que se indican como maximo
 * MAX_CARACTERES y el vector de caracteres se utilizan para generar arboles de caracteres. No se deben tocar.
 * Si se quiere generar siempre los mismos arboles cambiar la instruccion srand(time(NULL)) por srand(0);
 * Antes de cada arbol se escribe un 1 para indicar que el arbol es de caracteres como ocurre en el ejercicio 0905
 * La salida se muestra en el fichero datos2.txt
 *
 *
 * Arboles de búsqueda
 *  Created on: 18/04/2016
 *      Author: isabel
 *
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>


const int MAX_CASOS = 50; // Numero de arboles generados
const int MAX_NODOS = 40; // maximo numero de nodos del arbol
const int MAXCARACTERES = 26;
char c[MAXCARACTERES] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// genera un árbol de búsqueda a partir de los elementos de un vector ordenado
// Divide el vector por una posición al azar, el valor de esta posicion es la raiz
// los valores a la izquierda pertenecen al subarbol izquierdo
// los valores a la derecha pertenecen al subarbol derecho
// Parametros: v - vector ordenado
//             ini posición inicial del subvector que estamos considerando dentro de v
//             fin posicion final del subvector que estamos considerando dentro de v
void generaArbolOrdenado (std::vector<int> const& v, int ini,int fin) {
	if (fin < ini) std::cout << '.';  // arbol vacio
	else if (fin == ini) std::cout << c[v[ini]] << ".."; // arbol de un elemento
	else { // arbol con mas de un elemento
		int m = rand()%(fin - ini) + ini; // genera valor de la raiz
		std::cout << c[v[m]];
		generaArbolOrdenado(v,ini,m-1);  // genera subarbol izquierdo
		generaArbolOrdenado(v,m+1,fin);  // genera subarbol derecho
	}
}

int main() {
    #ifndef DOMJUDGE
     std::ofstream out("datos2.txt");
     auto coutbuf = std::cout.rdbuf(out.rdbuf()); //save old buf and redirect std::cout to casos.txt
     #endif
	//srand(0);
    srand(time(NULL));
    // Caso vacio
    std::cout << 1 << '\n';
    std::cout << ".\n";
	for (int i = 0; i < MAX_CASOS;++i) {
		// Numero de nodos maximo del arbol
		int numNodos = rand() % MAX_NODOS+1;  // numero de nodos del arbol
		std::vector<int> v(numNodos);
		for (int i = 0; i < numNodos; ++i) { // genera los valores del arbol
			v[i] = rand() % MAXCARACTERES;
		}
		sort (v.begin(), v.end());  // ordena los valores
		std::vector<int> ordenado;  // vector sin repetidos
		ordenado.push_back(v[0]);
		for (int i = 0; i < v.size() - 1; ++i) {  // elimina las repeticiones
			if (v[i] != v[i+1]) ordenado.push_back(v[i+1]);
		}
		// genera el arbol. El primer elemento debe escribirse fuera de la
		// funcion recursiva para cuadrar bien los blancos
        std::cout << 1 << '\n'; // indica que es un arbol de caracteres
		if (ordenado.size() == 0) std::cout << ".\n";  // arbol vacio
		else if (ordenado.size() == 1) std::cout << c[ordenado[0]] << "..\n";  // arbol de un elemento
		else {
			int m = rand()%(ordenado.size());
			std::cout << c[ordenado[m]]; // escribe la raiz
			generaArbolOrdenado(ordenado,0,m-1);  // subarbol izquierdo
			generaArbolOrdenado(ordenado,m+1,ordenado.size()-1);  // subarbol derecho
			std::cout << '\n';
		}
    }
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cout.rdbuf(coutbuf);
     #endif
    
    return 0;
}
