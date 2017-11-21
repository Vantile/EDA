#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

using namespace std;

class Horas
{
public:

	Horas()
	{
		horas = 0;
		minutos = 0;
		segundos = 0;
	}

	Horas(int h, int m, int s)
	{
		if (h <= 23 && h >= 0 && m >= 0 && m <= 59 && s >= 0 && s <= 59)
		{
			horas = h;
			minutos = m;
			segundos = s;
		}
		else
			throw invalid_argument("ERROR");
	}

	bool operator< (const Horas &a) const
	{
		bool aux = false;
		if (horas < a.horas)
			aux = true;
		else if (horas == a.horas)
		{
			if (minutos < a.minutos)
				aux = true;
			else if (minutos == a.minutos)
			{
				if (segundos < a.segundos)
					aux = true;
			}
		}
		return aux;
	}

	const bool operator==(const Horas &a)
	{
		bool aux = false;
		if (a.horas == horas && a.minutos == minutos && a.segundos == segundos)
			aux = true;
		return aux;
	}

	const bool operator<= (const Horas &a)
	{
		bool aux = false;
		if (horas < a.horas)
			aux = true;
		else if (horas == a.horas)
		{
			if (minutos < a.minutos)
				aux = true;
			else if (minutos == a.minutos)
			{
				if (segundos < a.segundos)
					aux = true;
				else if (segundos == a.segundos)
					aux = true;
			}
		}
		return aux;
	}

	const Horas& operator+(const Horas &a)
	{
		this->segundos += a.segundos;
		if (this->segundos >= 60)
		{
			this->minutos++;
			this->segundos = this->segundos % 60;
		}
		this->minutos += a.minutos;
		if (this->minutos >= 60)
		{
			this->horas++;
			this->minutos = this->minutos % 60;
		}
		this->horas += a.horas;
		if (this->horas >= 24)
			throw "Error";
		return *this;
	}

	void copiar(const Horas &h)
	{
		horas = h.horas;
		minutos = h.minutos;
		segundos = h.segundos;
	}

	friend istream& operator>>(istream &i, Horas &h);
	friend ostream& operator<<(ostream &o, const Horas &h);

private:
	int horas;
	int minutos;
	int segundos;
};

class Peliculas
{
public:

	Peliculas()
	{
		finaliz = Horas();
		titulo = "";
	}

	Peliculas(Horas f, string t)
	{
		finaliz = Horas();
		finaliz.copiar(f);
		titulo = t;
	}

	Peliculas(Horas i, Horas d, string t)
	{
		finaliz = Horas(0, 0, 0);
		finaliz.copiar(i + d);
		titulo = t;
	}

	bool operator<(const Peliculas& a) const
	{
		bool aux = false;
		if (this->finaliz < a.finaliz)
			aux = true;
		return aux;
	}

	const bool operator==(const Peliculas &a)
	{
		bool aux = false;
		if (this->finaliz == a.finaliz && this->titulo == a.titulo)
			aux = true;
		return aux;
	}

	void copiar(Peliculas &p)
	{
		this->finaliz = p.finaliz;
		this->titulo = p.titulo;
	}

	friend istream& operator>>(istream &i, Peliculas &p);
	friend ostream& operator<<(ostream &o, const Peliculas &p);
	friend void ordAlpha(vector<Peliculas> &v);

private:
	Horas finaliz;
	string titulo;
};

istream& operator>>(istream &i, Horas &h) // operator>> de Horas.
{
	char aux;
	int hs, m, s;
	i >> hs >> aux >> m >> aux >> s;
	if (hs <= 23 && hs >= 0 && m <= 59 && m >= 0 && s <= 59 && s >= 0)
	{
		h.horas = hs;
		h.minutos = m;
		h.segundos = s;
	}
	else
		throw invalid_argument("ERROR extractor");
	i.ignore();
	return i;
}

istream& operator>>(istream &i, Peliculas &p) // operator>> de Peliculas.
{
	Horas ini, dur;
	string titulo;
	i >> ini;
	i >> dur;
	getline(i, titulo);
	p.finaliz = ini + dur;
	p.titulo = titulo;
	return i;
}

ostream& operator<<(ostream &o, const Horas &h) // operator<< de Horas.
{
	o << setfill('0') << setw(2) << h.horas << ":"
		<< setfill('0') << setw(2) << h.minutos << ":"
		<< setfill('0') << setw(2) << h.segundos;
	return o;
}

ostream& operator<<(ostream &o, const Peliculas &p) // operator<< de Peliculas.
{
	o << p.finaliz << " " << p.titulo;
	return o;
}

void ordAlpha(vector<Peliculas> &v)
{
	unsigned int i = 0;
	Peliculas aux;
	while (i < v.size() - 1)
	{
		if (v[i].finaliz == v[i + 1].finaliz && v[i].titulo > v[i + 1].titulo)
		{
			aux.copiar(v[i]);
			v[i].copiar(v[i + 1]);
			v[i + 1].copiar(aux);
		}
		i++;
	}
}

void cine(unsigned const int numPelis)
{
	vector<Peliculas> v;
	Peliculas pelicula;
	unsigned int i = 0;
	while (i < numPelis)
	{
		try {
			cin >> pelicula;
			v.push_back(pelicula);
		}
		catch (...)
		{
		}
		i++;
	}
	sort(v.begin(), v.end());
	ordAlpha(v);
	i = 0;
	while (i < v.size())
	{
		cout << v[i] << endl;
		i++;
	}
	cout << "---" << endl;
}

int main()
{
	unsigned int numPelis = 0;
	cin >> numPelis;
	while (numPelis != 0)
	{
		cine(numPelis);
		cin >> numPelis;
	}
}
