#pragma once
#include "IO_I.h"

template<typename T = float>
class Complex : public IO_I
{
	T re, im;
public:
	Complex(T re = {}, T im = {});
	Complex(const Complex<T>& copy);
	Complex<T>& operator=(const Complex<T>& copy);
	virtual ~Complex();

	// Getters and setters
	T getReal() const;
	T getImaginary() const;
	void setReal(T real) const;
	void setImaginary(T imaginary) const;

	// Inherited from IO_I
	virtual void read(std::istream& is) override;
	virtual void print(std::ostream& os) const override;
};

template<typename T>
inline Complex<T>::Complex(T re, T im)
	: re{ re }, im{ im }
{
}

template<typename T>
inline Complex<T>::Complex(const Complex<T>& copy)
	: re{ copy.re }, im{ copy.im }
{
}

template<typename T>
Complex<T>& Complex<T>::operator=(const Complex<T>& copy)
{
	if (this == &copy) {
		return *this;
	}

	re = copy.re;
	im = copy.im;
	return *this;
}

template<typename T>
inline Complex<T>::~Complex()
{
}

template<typename T>
inline T Complex<T>::getReal() const
{
	return re;
}

template<typename T>
inline T Complex<T>::getImaginary() const
{
	return im;
}

template<typename T>
inline void Complex<T>::setReal(T real) const
{
	re = real;
}

template<typename T>
inline void Complex<T>::setImaginary(T imaginary) const
{
	im = imaginary;
}

template<typename T>
inline void Complex<T>::read(std::istream& is)
{
	is >> re >> im;
}

template<typename T>
inline void Complex<T>::print(std::ostream& os) const
{
	os << re;
	if (im >= 0) {
		os << '+';
	}
	os << im << 'i';
}