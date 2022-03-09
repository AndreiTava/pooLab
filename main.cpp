#include <iostream>
#include <string.h>


using namespace std;
class Persoana
{
private:
	char* nume;
	int an_nastere;
	char sex;
public:
	Persoana(const char pnum[]="", int an = 0, char s = 'F')
	{
		size_t nume_size = strlen(pnum) + 1;
		nume = new char[nume_size];
		strcpy_s(nume,nume_size,pnum);
		an_nastere = (an >= 0) ? an : 0;
		sex = (s == 'M' || s == 'F') ? s : 'F';
	}
	Persoana(const Persoana& pers)
	{
		setNume(pers.nume);
		setAn(pers.an_nastere);
		setSex(pers.sex);
	}
	~Persoana()
	{
		delete[] nume;
	}
	const char* getNume() const 
	{
		return nume;
	}
	void setNume(const char pnum[])
	{
		delete[] nume;
		size_t nume_size = strlen(pnum) + 1;
		nume = new char[nume_size];
		strcpy_s(nume,nume_size,pnum);
	}
	const int getAn() const
	{
		return an_nastere;
	}
	void setAn(int an)
	{
		an_nastere = (an >= 0) ? an : 0;
	}
	const char getSex() const
	{
		return sex;
	}
	void setSex(char s)
	{
		sex = (s == 'M' || s == 'F') ? s : 'F';
	}
	void operator=(const Persoana& pers)
	{
		setNume(pers.nume);
		setAn(pers.an_nastere);
		setSex(pers.sex);
	}
	const bool operator ==(const Persoana& pers)
	{
		return (strcmp(nume, pers.nume)== 0) && (sex == pers.sex && an_nastere == pers.an_nastere);
	}
	friend ostream& operator<<(ostream& out ,const Persoana& p)
	{
		out << "Nume: " << p.nume << ", An Nastere: " << p.an_nastere << ", Sex: " << p.sex << endl << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Persoana& p)
	{
		char pnum[42];
		int an;
		char sex;
		cout << "Introduceti Numele: ";
		in.getline(pnum, 42);
		p.setNume(pnum);
		cout << "\nIntroduceti Anul Nasterii: ";
		in >> an;
		p.setAn(an);
		cout << " \nIntroduceti Sexul(M/F): ";
		in >> sex;
		p.setSex(sex);
		cout << endl;
		in.get();
		return in;
	}
	friend class Baza_de_date;
};

class Baza_de_date
{
private:
	Persoana** persoane;
	int max_size;
	int nr_pers;
	void remPers(int pos)
	{
		delete persoane[pos];
		for (int i = pos; i < nr_pers - 1; i++)
			persoane[i] =persoane[i + 1];
		persoane[nr_pers] = nullptr;
		--nr_pers;
	}
public:
	Baza_de_date(int nr=100)
	{
		max_size = nr;
		nr_pers = 0;
		persoane = new Persoana*[max_size];
		for (int i = 0; i < max_size; ++i)
			persoane[i] = nullptr;
	}
	Baza_de_date(const Baza_de_date& baza)
	{
		max_size = baza.max_size;
		nr_pers = (baza.nr_pers <= max_size)? baza.nr_pers: max_size; // nu era necesar dar voiam sa scap de un warning
		persoane = new Persoana * [max_size];
		for (int i = 0; i < nr_pers; ++i)
			persoane[i] = new Persoana(*baza.persoane[i]);
		for (int i = nr_pers; i < max_size; ++i)
			persoane[i] = nullptr;
	}
	void operator=(const Baza_de_date& baza)
	{
		max_size = baza.max_size;
		nr_pers = nr_pers = (baza.nr_pers <= max_size) ? baza.nr_pers : max_size; // nu era necesar dar voiam sa scap de un warning
		for (int i = 0; i < nr_pers; ++i)
			delete persoane[i];
		delete[] persoane;
		persoane = new Persoana * [max_size];
		for (int i = 0; i < nr_pers; ++i)
			persoane[i] = new Persoana(*baza.persoane[i]);
		for (int i = nr_pers; i < max_size; ++i)
			persoane[i] = nullptr;
	}
	~Baza_de_date()
	{
		for (int i = 0; i < nr_pers; ++i)
			delete persoane[i];
		delete[] persoane;
	}
	void addPers()
	{
		if (nr_pers < max_size)
		{
			Persoana* pers = new Persoana();
			cin >> *pers;
			persoane[nr_pers] = pers;
			++nr_pers;
			cout << "\nPersoana adaugata cu succes!\n";
		}
		else
			cout << "\nAdaugare Imposibila, limita de persoane atinsa\n";
	}
	void addPers(const char pnum[], int an, char s)
	{
		if (nr_pers < max_size)
		{
			Persoana* pers = new Persoana(pnum, an, s);
			persoane[nr_pers] = pers;
			++nr_pers;
			cout << "\nPersoana adaugata cu succes!\n";
		}
		else
			cout << "\nAdaugare imposibila, limita de persoane atinsa!\n";
	}
	void removePers(const char pnum[])
	{
		int pers_gas = 0;
		for (int i = 0; i < nr_pers; ++i)
		{
			if (strcmp(persoane[i]->nume, pnum) == 0)
			{
				++pers_gas;
				remPers(i);
				--i;
			}
		}
		cout << "\nAu fost eliminate " << pers_gas << " persoane din baza de date.\n";
	}
	void removePers(int an)
	{
		int pers_gas = 0;
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->an_nastere == an)
			{
				++pers_gas;
				remPers(i);
				--i;
			}
		}
		cout << "\nAu fost eliminate " << pers_gas << " persoane din baza de date.\n";
	}
	void removePers(char s)
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->sex == s)
				remPers(i);
		}
	}
	const void afisSortNume();
	const void afisSortAn();
};

const void Baza_de_date::afisSortNume()
{
	Persoana** to_sort = new Persoana*[nr_pers];
	to_sort[0] = persoane[0];
	for (int i = 1; i < nr_pers; ++i)
	{
		to_sort[i] = persoane[i];
		int j = i;
		while (j > 0 && strcmp(to_sort[j]->nume, to_sort[j-1]->nume) < 0)
		{
			swap(to_sort[j], to_sort[j - 1]);
			--j;
		}

	}
	cout << "\nPersoanele sortate alfabetic: \n\n";
	for (int i = 0; i < nr_pers; ++i)
		cout << *to_sort[i];

}

const void Baza_de_date::afisSortAn()
{
	Persoana** to_sort = new Persoana * [nr_pers];
	to_sort[0] = persoane[0];
	for (int i = 1; i < nr_pers; ++i)
	{
		to_sort[i] = persoane[i];
		int j = i;
		while (j > 0 && to_sort[j]->an_nastere < to_sort[j - 1]->an_nastere)
		{
			swap(to_sort[j], to_sort[j - 1]);
			--j;
		}

	}
	cout << "\nPersoanele sortate dupa anul nasterii: \n\n";
	for (int i = 0; i < nr_pers; ++i)
		cout << *to_sort[i];
}

class Meniu
{
private:
	Baza_de_date bd;
	char cmd[42]="";
public:
	Meniu()
	{
		cout << "----User Interface V0.02----\n\n";
	}
	void loop()
	{
		while (true)
		{
			cout << "\nIntroduceti Comanda Dorita('HELP' pentru lista de comenzi): ";
			cin.getline(cmd, 42);
			if (strcmp(cmd, "HELP") == 0)
			{
				cout << "\nComenzile acceptate sunt:\n\
ADD - Adauga o persoana in Baza de Date\n\
REMBN - Elimina toate persoanele din baza de date cu numele introdus\n\
REMBY - Elimina toate persoanele din baza de date cu anul introdus\n\
REMBS - Elimina toate persoanele din baza de date cu sexul introdus\n\
AFSN - Afiseaza toata baza de date sortata alfabetic dupa nume\n\
AFSA - Afiseaza toata baza de data sortata dupa an\n\
EXIT - Iesire din program\n";
			}
			else if (strcmp(cmd, "ADD") == 0)
				bd.addPers();
			else if (strcmp(cmd, "REMBN") == 0)
			{
				char nume[42];
				cout << "\nIntroduceti Numele de Eliminat: ";
				cin.getline(nume, 42);
				bd.removePers(nume);
			}
			else if (strcmp(cmd, "REMBA") == 0)
			{
				int an;
				cout << "Introduceti Anul de Eliminat: ";
				cin >> an;
				bd.removePers(an);
			}
			else if (strcmp(cmd, "REMBS") == 0)
			{
				char s;
				cout << "Introduceti Sexul de Eliminat: ";
				cin >> s;
				bd.removePers(s);
			}
			else if (strcmp(cmd, "AFSN") == 0)
				bd.afisSortNume();
			else if (strcmp(cmd, "AFSA") == 0)
				bd.afisSortAn();
			else if (strcmp(cmd, "EXIT") == 0)
				break;
			else
				cout << "\nComanda invalida\n";
		}
	}
};


int main() {

	Meniu m;
	m.loop();
}