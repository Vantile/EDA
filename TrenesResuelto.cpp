#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>

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

	bool operator< (const Horas &a)
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

	bool operator==(const Horas &a)
	{
		bool aux = false;
		if (a.horas == horas && a.minutos == minutos && a.segundos == segundos)
			aux = true;
		return aux;
	}

	bool operator<= (const Horas &a)
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

	friend istream& operator>>(istream &i, Horas &h);
	friend ostream& operator<<(ostream &o, const Horas &h);

private:
	int horas;
	int minutos;
	int segundos;
};

int busqBinaria(vector<Horas> v, Horas x, int a, int b)
{
	int p, m;
	if (a == b + 1)
		p = a - 1;
	else
	{
		m = (a + b) / 2;
		if (v[m] < x)
			p = busqBinaria(v, x, m + 1, b);
		else
			p =busqBinaria(v, x, a, m - 1);
	}
	return p;
}

istream& operator>>(istream &i, Horas &h)
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

ostream& operator<<(ostream &o, const Horas &h)
{
	o << setfill('0') << setw(2) << h.horas << ":" 
		<< setfill('0') << setw(2) << h.minutos << ":" 
		<< setfill('0') << setw(2) << h.segundos;
	return o;
}

void viajes(int numTrenes, int numViajes)
{
	vector<Horas> v1(0);
	Horas aux(0, 0, 0);
	if (numTrenes != 0 && numViajes != 0)
	{
		int i = 0;
		while (i < numTrenes && v1.size() < 100000)
		{
			try {
				cin >> aux;
				v1.push_back(aux);
				i++;
			}
			catch (...) { i++; }
		}
		i = 0;
		int p = 0;
		while (i < numViajes)
		{
			try {
				cin >> aux;
				p = busqBinaria(v1, aux, 0, v1.size() - 1);
				if (p + 1 >= v1.size())
					cout << "NO" << endl;
				else
					cout << v1[p + 1] << endl;
				//v2.push_back(aux);
				i++;
			}
			catch (...)
			{
				cout << "ERROR" << endl;
				i++;
			}
		}
		cout << "---" << endl;
	}
}

int main()
{
	//vector<Horas> v2(0);
	int numTrenes = 0;
	int numViajes = 0;
	cin >> numTrenes;
	cin >> numViajes;
	while (numTrenes != 0 && numViajes != 0)
	{
		viajes(numTrenes, numViajes);
		cin.sync();
		cin >> numTrenes;
		cin >> numViajes;
	}
	cin.sync();
	cin.get();
}