#include "Complex.h"

using namespace std;

//default constructor
Complex::Complex(double real, double imagin)
{
	setComplex(real, imagin);
}

//methods
void Complex::setComplex(double real, double imagin)
{
	setRealPart(real);
	setImaginaryPart(imagin);
}

void Complex::getComplex(double& real, double& imagin) const
{
	real = realNum;
	imagin = imaginNum;
}

void Complex::setRealPart(double real)
{
	realNum = real;
}

double Complex::getRealPart() const
{
	return realNum;
}

void Complex::setImaginaryPart(double imagin)
{
	imaginNum = imagin;
}

double Complex::getImaginaryPart()const
{
	return imaginNum;
}

Complex &Complex::operator+(const Complex& complex) const
{
	double a, b;
	getComplex(a, b);

	double c, d;
	complex.getComplex(c, d);

	return *new Complex(a + c, b + d);
}

Complex &Complex::operator*(const Complex& rhs) const
{
	double a, b;
	getComplex(a, b);

	double c, d;
	rhs.getComplex(c, d);

	return *new Complex((a*c) - (b*d), (a*d) + (b*c));
}

bool Complex::operator==(const Complex& rhs) const
{
	double a, b;
	getComplex(a, b);

	double c, d;
	rhs.getComplex(c, d);

	return (a == c && b == d);
}

//functions
ostream & operator<<(ostream &lhs, const Complex &rhs)
{
	lhs << '('
		<< rhs.realNum
		<< ','
		<< rhs.imaginNum
		<< ')';
	return lhs;
}

istream & operator>>(istream &lhs, Complex &rhs)
{
	string ch;
	lhs >> ch;//(
	lhs >> rhs.realNum;
	lhs >> ch;//,
	lhs >> rhs.imaginNum;
	lhs >> ch;//

	return lhs;
}

