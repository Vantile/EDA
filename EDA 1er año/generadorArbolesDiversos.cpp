/*
 * Generador de arboles aleatorios
 * CrearCasosPrueba.cpp
 *
 *  Created on: 13/01/2015
 *      Author: isabel
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_CASOS = 500;
const int MAX_ALTURA = 10;
const int MAX_VALOR = 100;

// Arboles que pueden tener nodos con 0, 1, 2, hijos
void ArbolesRaros(int altura) {
	if (altura == 0) cout << " -1" ;
	else {
		int numhijos = rand() % 4; // 0, 1 - hijo izdo, 2- hijo dr, 3 dos hijos
		int num = rand() % MAX_VALOR + 1;
		cout << ' ' << num;
		switch (numhijos) {
            case 0:
                cout << " -1 -1";
                break;
            case 1 :
                ArbolesRaros(altura - 1); // hijo izquierdo
                cout << " -1";
                break;
            case 2:
                cout << " -1";
                ArbolesRaros(altura - 1); // hijo derecho
                break;
            case 3:
                ArbolesRaros(altura - 1); // hijo izquierdo
                ArbolesRaros(altura - 1); // hijo derecho
                break;
		}
	}
}

int main() {
#ifndef DOMJUDGE
    std::ofstream out("datos2.txt");
    auto coutbuf = std::cout.rdbuf(out.rdbuf()); //save old buf and redirect std::cout to casos.txt
#endif
	//srand(0);
    srand(time(NULL));
    
	for (int i = 0; i < MAX_CASOS ; ++i) {
		int num = rand() % MAX_VALOR + 1;
		cout << num;
		ArbolesRaros(MAX_ALTURA); // arbol izquierdo
		ArbolesRaros(MAX_ALTURA); // arbol derecho
		cout << '\n';
	}
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cout.rdbuf(coutbuf);
#endif
    
    return 0;
}
