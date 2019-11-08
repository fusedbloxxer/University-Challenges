#pragma once
#include "IO_I.h"

class Complex : public IO_I
{
	float re, im;
public:
	Complex(float re = 0.0f, float im = 0.0f);
	Complex(const Complex& copy);
	Complex& operator=(const Complex& copy);
	virtual ~Complex();

	// Inherited from IO_I
	virtual void read(std::istream& is) override;
	virtual void print(std::ostream& os) const override;
};