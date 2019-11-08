#include "Complex.h"
#include "Complex.h"

Complex::Complex(float re, float im)
	:re{ re }, im{ im }
{
}

Complex::Complex(const Complex& copy)
	: re{ copy.re }, im{ copy.im }
{
}

Complex& Complex::operator=(const Complex& copy)
{
	if (this == &copy) {
		return *this;
	}

	re = copy.re;
	im = copy.im;
	return *this;
}

Complex::~Complex()
{
}

void Complex::read(std::istream& is)
{
	is >> re >> im;
}

void Complex::print(std::ostream& os) const
{
	os << re;
	if (im >= 0) {
		os << '+';
	}
	os << im << 'i';
}
