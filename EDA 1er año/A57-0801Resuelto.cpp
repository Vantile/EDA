
#include <iostream>
#include <stdexcept>


template <class T>
class SinglyLinkedList {
public:
	// Constructor sin parámetros
	SinglyLinkedList() : _ini(nullptr) {}

	// Constructor copia
	SinglyLinkedList(SinglyLinkedList const& other) {
		_ini = copia(other._ini);
	}

	// destructor
	~SinglyLinkedList() {
		libera(_ini);
		_ini = nullptr;
	}

	// Operador de asignación
	SinglyLinkedList<T> &operator=(SinglyLinkedList<T> const& other) {
		if (this != &other) {
			libera(_ini);
			_ini = copia(other._ini);
		}
		return *this;
	}

	// Operador de comparacion
	bool operator== (SinglyLinkedList<T> const& rhs) const {
		Nodo* aux1 = _ini; Nodo* aux2 = rhs._ini;
		while (aux1 != nullptr && aux2 != nullptr && aux1->_elem == aux2->_elem) {
			aux1 = aux1->_sig;
			aux2 = aux2->_sig;
		}
		return (aux1 == nullptr && aux2 == nullptr);
	}

	// Añadir un nodo por el comienzo de la lista
	void push_front(T const& e) {
		Nodo * nuevo = new Nodo(e, _ini);
		_ini = nuevo;
	}

	// Elimina el nodo del comienzo de la lista
	void pop_front() {
		if (_ini == nullptr) throw std::invalid_argument("lista vacia");
		Nodo *aux = _ini;
		_ini = _ini->_sig;
		delete aux;
	}

	// Duplica los nodos de una lista
	void duplicate() {
		Nodo *auxini = _ini;
		Nodo *auxsig;
		while (auxini != nullptr)
		{
			auxsig = auxini->_sig;
			auxini->_sig = new Nodo(auxini->_elem, auxsig);
			auxini = auxsig;
		}

	}

	// Muestra una lista por pantalla
	void showList() {
		Nodo *aux = _ini;
		while (aux != nullptr)
		{
			std::cout << aux->_elem;
			aux = aux->_sig;
			if (aux != nullptr)
				std::cout << " ";
			else
				std::cout << std::endl;
		}
	}

private:

	/*
	Clase nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente.
	*/
	class Nodo {
	public:
		Nodo() : _sig(nullptr) {}
		Nodo(const T &elem) : _elem(elem), _sig(nullptr) {}
		Nodo(const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	// Puntero al primer elemento
	Nodo *_ini;

	// libera todos los nodos de la lista
	void libera(Nodo *ini) {
		while (ini != nullptr) {
			Nodo *aux = ini;
			ini = ini->_sig;
			delete aux;
		}
	}

	// Copia el parámetro en la lista.
	// La lista debe estar vacia.
	Nodo* copia(Nodo* other) {
		if (other == nullptr) return nullptr;
		else if (other->_sig == nullptr) {
			Nodo* nuevo = new Nodo(other->_elem);
			return nuevo;
		}
		else {
			Nodo* aux = copia(other->_sig);
			Nodo* nuevo = new Nodo(other->_elem, aux);
			aux = nuevo;
			return aux;
		}
	}

};

/*
bool func()
{
	SinglyLinkedList<int> lista;
	bool terminar;
	int aux;
	std::cin >> aux;
	if (aux == 0)
		terminar = true;
	else
	{
		while (aux != 0)
		{
			lista.push_front(aux);
			std::cin >> aux;
		}
		lista.duplicate();
		lista.showList();
		terminar = false;
	}
	return terminar;
}

int main()
{
	bool terminar = false;
	while (!terminar)
	{
		terminar = func();
		std::cin.sync();
	}
	return 0;
}*/

