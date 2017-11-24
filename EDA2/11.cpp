// Jose Antonio Bernal Pérez
// F06


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas {diamante, rubi, esmeralda, zafiro, jade};

std::istream& operator>>(std::istream& entrada, piedrasPreciosas& p){
	char num;
	entrada >> num;
	switch(num){
		case 'd': p = diamante; break;
		case 'r': p = rubi; break;
		case 'e': p = esmeralda; break;
		case 'z': p = zafiro; break;
		case 'j': p = jade; break;
	}
	return entrada;
}

int seqPiedras(const std::vector<piedrasPreciosas> &v, const int &seq, 
	const piedrasPreciosas &p1, const int &p1num, const piedrasPreciosas &p2, const int &p2num){
		int i = 0;
		int numSeqOk = 0;
		piedrasPreciosas primSeq = v[0];
		int tamSeq = 0;
		int p1numAct = 0;
		int p2numAct = 0;
		while(i < v.size()){
			if(tamSeq < seq){
				++tamSeq;
				if(v[i] == p1) ++p1numAct;
				if(v[i] == p2) ++p2numAct;
			}
			else{
				if(p1numAct == p1num && p2numAct == p2num) ++numSeqOk;
				if(primSeq == p1) --p1numAct;
				if(primSeq == p2) --p2numAct;
				if(v[i] == p1) ++p1numAct;
				if(v[i] == p2) ++p2numAct;
				primSeq = v[i - seq];
			}
			++i;
		}
		return numSeqOk;
	}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, seq, p1num, p2num;
	piedrasPreciosas p1, p2;
	// Parámentros del problema
	std::cin >> n;
	std::cin >> seq;
	std::cin >> p1;
	std::cin >> p1num;
	std::cin >> p2;
	std::cin >> p2num;
	// Vector
	std::vector<piedrasPreciosas> v;
	for(int i = 0; i < n; ++i){
		piedrasPreciosas p;
		std::cin >> p;
		v.push_back(p);
	}
	int s = seqPiedras(v, seq, p1, p1num, p2, p2num);
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
