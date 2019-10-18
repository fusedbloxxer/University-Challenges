#pragma once
#include "Prajitura.h"
#include "Constants.h"

template<class T>
class Cerc : public Prajitura<T>
{
private:
	T raza;
public:
	Cerc(T raza = 0, T h = 0)
		:Prajitura<T>{ h }, raza{ raza } {}

	Cerc(const Cerc& copy)
		:raza{ copy.raza }, Prajitura<T>{copy.h} {}

	Cerc& operator=(const Cerc& copy)
	{
		raza = copy.raza;
		Prajitura<T>::h = copy.h;
		return *this;
	}

	// Wow, PROTOTYPE PATTERN.
	Prajitura<T>* clone() const override {
		return new Cerc<T>{ *this };
	}

	T getSurface() const override
	{
		return MUtil::pi * raza * raza;
	}

	T getFrisca() const override
	{
		return MUtil::frisca * (2 * MUtil::pi * raza * Prajitura<T>::h + MUtil::pi * raza * raza);
	}

	void print(std::ostream& os) const override
	{
		os << "Raza R = " << raza << std::endl;
		Prajitura<T>::print(os);
	}

	void read(std::istream& is) override
	{
		std::cout << "Raza R = "; is >> raza;
		Prajitura<T>::read(is);
	}
};

