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
using namespace std;

int main() {

	

}