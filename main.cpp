#include <iostream>
#include <string.h>
//namespace lab1
//{
//	class Complex
//	{
//	private:
//		double real, imaginary;
//	public:
//		Complex(double re = 0, double im = 0) : real(re), imaginary(im) {};
//		Complex(Complex& cpy) : Complex(cpy.real, cpy.imaginary) {};
//		double getReal() const
//		{
//			return real;
//		}
//		void setReal(double re)
//		{
//			real = re;
//		}
//		double getImaginary() const
//		{
//			return imaginary;
//		}
//		void setImaginary(double im)
//		{
//			imaginary = im;
//		}
//		void print()
//		{
//			if (real != 0)
//				cout << real;
//			if (imaginary != 0)
//			{
//
//				if (imaginary < 0)
//					cout << "-";
//				else if (real != 0)
//					cout << "+";
//				cout << "i*" << abs(imaginary) << endl;
//
//			}
//		}
//
//		double getMagnitude() const
//		{
//			return sqrt(real * real + imaginary * imaginary);
//		}
//
//		Complex operator+(Complex& rhs)
//		{
//			Complex res(real + rhs.real, imaginary + rhs.imaginary);
//			return res;
//		}
//		Complex operator*(Complex& rhs)
//		{
//			Complex res(real * rhs.real - imaginary * rhs.imaginary, real * rhs.imaginary + rhs.real * imaginary);
//			return res;
//		}
//		Complex operator/(Complex& rhs)
//		{
//			double mag = rhs.getMagnitude();
//			Complex inverse(rhs.real / (mag * mag), (-1) * rhs.imaginary / (mag * mag));
//			inverse.print();
//			return *this * inverse;
//		}
//
//	};
//}

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
		nume = new char[strlen(pnum)];
		strcpy_s(nume,strlen(pnum),pnum);
		an_nastere = (an >= 0) ? an : 0;
		sex = (s == 'M' || s == 'F') ? s : 'F';
	}
	char* getNume() const 
	{
		return nume;
	}
	void setNume(const char pnum[])
	{
		delete[] nume;
		nume = new char[strlen(pnum)];
		strcpy_s(nume,strlen(pnum),pnum);
	}
	int getAn() const
	{
		return an_nastere;
	}
	void setAn(int an)
	{
		an_nastere = an_nastere = (an >= 0) ? an : 0;
	}
	char getSex() const
	{
		return sex;
	}
	void setSex(char s)
	{
		sex = (s == 'M' || s == 'F') ? s : 'F';
	}
	friend ostream& operator<<(ostream& out ,const Persoana& p)
	{
		out << "Nume: " << p.nume << " An Nastere: " << p.an_nastere << " Sex: " << p.sex << endl << endl;
	}
	friend istream& operator>>(istream& in, Persoana& p)
	{
		char pnum[42];
		cout << "Introduceti Numele: ";
		p.setNume(pnum);
		cout << "\nIntroduceti Anul Nasterii: ";
		in >> p.an_nastere;
		cout << " \nIntroduceti Sexul(M/F): ";
		in >> p.sex;
		cout << endl;
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
		--nr_pers;
		delete persoane[nr_pers];
	}
public:
	Baza_de_date(int nr)
	{
		max_size = nr;
		nr_pers = 0;
		persoane = new Persoana*[max_size];
		for (int i = 0; i < max_size; ++i)
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
		Persoana* pers = new Persoana();
		cin >> *pers;
		persoane[nr_pers] = pers;
		++nr_pers;
	}
	void removePers(const char pnum[])
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (strcmp(persoane[i]->nume,pnum))
				remPers(i);
		}
	}
	void removePers(int an)
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->an_nastere == an)
				remPers(i);
		}
	}
	void removePers(char s)
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->sex == s)
				remPers(i);
		}
	}
	void afisSortNume();
	void afisSortAn();
};

void Baza_de_date::afisSortNume()
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
	for (int i = 0; i < nr_pers; ++i)
		cout << to_sort[i];

}

void Baza_de_date::afisSortAn()
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
	for (int i = 0; i < nr_pers; ++i)
		cout << to_sort[i];
}

int main() {

	Baza_de_date bd(10);
	bd.addPers();
	bd.addPers();
	bd.addPers();

}