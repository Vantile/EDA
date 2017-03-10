/*
 * Generador de arboles completos
 *
 * CrearCasosPrueba.cpp
 *
 *  Created on: 13/01/2015
 *      Author: isabel
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ALTURA = 10;
const int MAX_VALOR = 100;
const int NUM_CASOS_COMPLETO = 3;


void ArbolesCompletos(int altura) {
	if (altura == 0) cout << " -1";
	else {
		int num = rand() % MAX_VALOR + 1;
		cout << ' ' << num;  //raiz
		ArbolesCompletos(altura - 1); // hijo izquierdo
		ArbolesCompletos(altura - 1); // hijo derecho
	}
}


int main() {
#ifndef DOMJUDGE
	std::ofstream out("datos2.txt");
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); //save old buf and redirect std::cout to casos.txt
#endif
	//srand(0);
	srand(time(NULL));
    
    // Arboles completos
    for (int k = 0; k < NUM_CASOS_COMPLETO; ++k) {
    	cout << 0 << '\n';  // Indicador de arboles de numeros enteros
    	cout << "-1\n"; // caso vacio
    	for (int i = 0; i < MAX_ALTURA-1 ; ++i) {
    		cout << 0 << '\n'; // Indicador de arboles de numeros enteros
    		int num = rand() % MAX_VALOR + 1; // raiz
    		cout << num;
    		ArbolesCompletos(i); 	//Hijo izquierdo
    		ArbolesCompletos(i);	// hijo derecho
    		cout << '\n';
    	}
    }
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cout.rdbuf(coutbuf);
#endif
    
    return 0;
}
