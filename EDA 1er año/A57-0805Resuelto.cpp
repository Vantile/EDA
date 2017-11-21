#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <class T>
class DoubleLinkedList {
public:
	// Constructor sin parámetros
	DoubleLinkedList() : _ini(nullptr) {}

	// Constructor copia
	DoubleLinkedList(DoubleLinkedList const& other) {
		_ini = copia(other._ini);
	}

	// destructor
	~DoubleLinkedList() {
		libera(_ini);
		_ini = nullptr;
	}

	// Operador de asignación
	DoubleLinkedList<T> &operator=(const DoubleLinkedList<T> &other) {
		if (this != &other) {
			libera(_ini);
			_ini = copia(other._ini);
		}
		return *this;
	}

	// Operador de comparacion
	bool operator== (DoubleLinkedList<T> const& rhs) const {
		Nodo* aux1 = _ini; Nodo* aux2 = rhs._ini;
		while (aux1 != nullptr && aux2 != nullptr) {
			if (aux1->_elem != aux2->_elem) return false;
			aux1 = aux1->_sig;
			aux2 = aux2->_sig;
		}
		return (aux1 == nullptr && aux2 == nullptr);
	}

	// Añadir un nodo por el comienzo de la lista
	void push_front(const T &e) {
		Nodo * nuevo = new Nodo(nullptr, e, _ini);
		if (_ini != nullptr) _ini->_ant = nuevo;
		_ini = nuevo;
	}

	// Elimina el nodo del comienzo de la lista
	void pop_front() {
		if (_ini == nullptr) throw std::invalid_argument("lista vacia");
		Nodo *aux = _ini;
		_ini = _ini->_sig;
		if (_ini != nullptr) _ini->_ant = nullptr;
		delete aux;
	}

	// La funcion debe devolver un booleano.
	template<class funcion>
	void filtrarLista(funcion f)
	{
		Nodo *aux = _ini;
		while (aux != nullptr)
		{
			if (!f(aux->_elem))
			{
				Nodo *ant = aux->_ant;
				Nodo *sig = aux->_sig;
				if (ant != nullptr)
					ant->_sig = sig;
				if (sig != nullptr)
					sig->_ant = ant;
				delete aux;
				aux = sig;
				if (aux != nullptr && aux->_ant == nullptr)
					_ini = aux;
				if (aux == nullptr && ant == nullptr && sig == nullptr)
					_ini = nullptr;
			}
			else
				aux = aux->_sig;
		}
	}

	void mostrarHaciaAtras()
	{
		Nodo *aux = _ini;
		if (aux != nullptr)
		{
			while (aux->_sig != nullptr)
				aux = aux->_sig;
			while (aux != nullptr)
			{
				cout << aux->_elem << endl;
				aux = aux->_ant;
			}
		}
	}

private:
	// Clase nodo que almacena internamente el elemento (de tipo T),
	// y un puntero al nodo siguiente.
	class Nodo {
	public:
		Nodo() : _sig(nullptr), _ant(nullptr) {}
		Nodo(const T &elem) : _elem(elem), _sig(nullptr), _ant(nullptr) {}
		Nodo(Nodo* ant, const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig), _ant(ant) {}

		T _elem;
		Nodo* _sig;
		Nodo* _ant;
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
		else if (other->_sig == nullptr) { // Un solo elemento
			Nodo* nuevo = new Nodo(other->_elem);
			return nuevo;
		}
		else {
			Nodo* aux = copia(other->_sig);
			Nodo* nuevo = new Nodo(nullptr, other->_elem, aux);
			aux->_ant = nuevo;
			aux = nuevo;
			return aux;
		}
	}

};

class Persona
{
public:
	Persona() : nombre(""), edad(0) {}
	Persona(string nom, int ed) : nombre(nom), edad(ed) {}

	string getNombre(){ return nombre; }
	int getEdad() { return edad; }

	friend istream& operator>>(istream &i, Persona &p);
	friend ostream& operator<<(ostream &o, Persona &p);
private:
	string nombre;
	int edad;
};

istream& operator>>(istream &i, Persona &p)
{
	int edad;
	string nombre;
	i >> edad;
	i.get();
	getline(i, nombre);
	p.edad = edad;
	p.nombre = nombre;
	return i;
}

ostream& operator<<(ostream &o, Persona &p)
{
	o << p.nombre;
	return o;
}

void viaje(int casos)
{
	int edadMinima;
	int edadMaxima;
	cin >> edadMinima;
	cin >> edadMaxima;
	Persona persona;
	DoubleLinkedList<Persona> lista;
	for (int i = 0; i < casos; i++)
	{
		cin >> persona;
		lista.push_front(persona);
	}
	lista.filtrarLista([edadMinima, edadMaxima](Persona p) {return (p.getEdad() >= edadMinima && p.getEdad() <= edadMaxima);});
	lista.mostrarHaciaAtras();
}

int main()
{
	int casos;
	cin >> casos;
	while (casos != 0)
	{
		viaje(casos);
		cout << "---" << endl;
		cin >> casos;
	}
}