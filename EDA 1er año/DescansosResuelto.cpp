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

	Horas(unsigned int s)
	{
		int aux = s;
		segundos = aux % 60;
		aux = aux / 60;
		minutos = aux % 60;
		horas = aux / 60;

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

	const int numSegundos()
	{
		int aux = segundos + (minutos * 60) + (horas * 3600);
		return aux;
	}

	friend istream& operator>>(istream &i, Horas &h);
	friend ostream& operator<<(ostream &o, const Horas &h);

private:
	int horas;
	int minutos;
	int segundos;
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

ostream& operator<<(ostream &o, const Horas &h) // operator<< de Horas.
{
	o << setfill('0') << setw(2) << h.horas << ":"
		<< setfill('0') << setw(2) << h.minutos << ":"
		<< setfill('0') << setw(2) << h.segundos;
	return o;
}

void descanso(int numTrabajos)
{
	vector<int> v;
	Horas aux;
	for (int i = 0; i < numTrabajos; i++)
	{
		cin >> aux;
		v.push_back(aux.numSegundos());
	}
	sort(v.begin(), v.end());
	int mejor = 0;
	int descanso = 0;
	for (unsigned int i = 0; i < v.size() - 1; i++)
	{
		if (descanso < v[i + 1] - v[i])
		{
			mejor = i;
			descanso = v[i + 1] - v[i];
		}
	}
	Horas mejorHora(v[mejor]);
	Horas mejorDescanso(descanso);
	cout << mejorHora << " " << mejorDescanso << endl;
}

int main()
{
	int numTrabajos = 0;
	cin >> numTrabajos;
	while (numTrabajos >= 2)
	{
		descanso(numTrabajos);
		cin >> numTrabajos;
	}
}