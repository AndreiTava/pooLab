#include <iostream>
#include <cmath>
namespace lab1
{
	class Complex
	{
	private:
		double real, imaginary;
	public:
		Complex(double re = 0, double im = 0) : real(re), imaginary(im) {};
		Complex(Complex& cpy) : Complex(cpy.real, cpy.imaginary) {};
		double getReal() const
		{
			return real;
		}
		void setReal(double re)
		{
			real = re;
		}
		double getImaginary() const
		{
			return imaginary;
		}
		void setImaginary(double im)
		{
			imaginary = im;
		}
		void print()
		{
			if (real != 0)
				std::cout << real;
			if (imaginary != 0)
			{

				if (imaginary < 0)
					std::cout << "-";
				else if (real != 0)
					std::cout << "+";
				std::cout << "i*" << abs(imaginary) << std::endl;

			}
		}

		double getMagnitude() const
		{
			return sqrt(real * real + imaginary * imaginary);
		}

		Complex operator+(Complex& rhs)
		{
			Complex res(real + rhs.real, imaginary + rhs.imaginary);
			return res;
		}
		Complex operator*(Complex& rhs)
		{
			Complex res(real * rhs.real - imaginary * rhs.imaginary, real * rhs.imaginary + rhs.real * imaginary);
			return res;
		}
		Complex operator/(Complex& rhs)
		{
			double mag = rhs.getMagnitude();
			Complex inverse(rhs.real / (mag * mag), (-1) * rhs.imaginary / (mag * mag));
			inverse.print();
			return *this * inverse;
		}

	};
}

class persoana
{
private:
	std::string nume;
	int an_nastere;
	char sex;
public:
	persoana(std::string pnum, int an, char s)
	{
		nume = pnum;
		an_nastere = (an >= 0) ? an : 0;
		sex = (s == 'M' || s == 'F') ? s : 'F';
	}
	std::string getNume()
	{
		return nume;
	}
	void setNume(std::string pnum)
	{
		nume = pnum;
	}
	int getAn()
	{
		return an_nastere;
	}
	void setAn(int an)
	{
		an_nastere = an_nastere = (an >= 0) ? an : 0;
	}
	char getSex()
	{
		return sex;
	}
	void setSex(char s)
	{
		sex = (s == 'M' || s == 'F') ? s : 'F';
	}

};

class baza_de_date
{
private:
	persoana** persoane;
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
	baza_de_date(int nr)
	{
		nr_pers = 0;
		persoane = new persoana*[nr];
		for (int i = 0; i < nr; ++i)
			persoane[i] = nullptr;
	}
	~baza_de_date()
	{
		for (int i = 0; i < nr_pers; ++i)
			delete persoane[i];
		delete[] persoane;
	}
	void addPers(std::string pnum, int an, char s)
	{
		persoana* pers = new persoana(pnum, an, s);
		persoane[nr_pers] = pers;
		++nr_pers;
	}
	void removePers(std::string pnum)
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->getNume() == pnum)
				remPers(i);
		}
	}
	void removePers(int an)
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->getAn() == an)
				remPers(i);
		}
	}
	void removePers(char s)
	{
		for (int i = 0; i < nr_pers; ++i)
		{
			if (persoane[i]->getSex() == s)
				remPers(i);
		}
	}

};

using namespace std;

int main() {

	

}