#pragma once
#include "Constants.h"
#include "Prajitura.h"
#include <cmath>

template<class T>
class TriunghiDrept : public Prajitura<T>
{
private:
	T cmica, cmare;
public:
	TriunghiDrept(T cmica = 0, T cmare = 0, T h = 0)
		:cmica{ cmica }, cmare{ cmare }, Prajitura<T>{ h } {}

	TriunghiDrept(const TriunghiDrept& copy)
		:cmica{ copy.cmica }, cmare{ copy.cmare }, Prajitura<T>{copy.h} {}

	TriunghiDrept& operator=(const TriunghiDrept& copy)
	{
		cmica = copy.cmica;
		cmare = copy.cmare;
		Prajitura<T>::h = copy.h;
		return *this;
	}

	Prajitura<T>* clone() const override {
		return new TriunghiDrept<T>{ *this };
	}

	T getSurface() const override
	{
		return cmica * cmare / 2;
	}

	T getFrisca() const override
	{
		return MUtil::frisca * (Prajitura<T>::h * (cmica + cmare + sqrt(cmica * cmica + cmare * cmare)) + getSurface());
	}

	virtual void read(std::istream& is) override {
		std::cout << "Cateta 1 = "; is >> cmica;
		std::cout << "Cateta 2 = "; is >> cmare;
		Prajitura<T>::read(is);
	}

	virtual void print(std::ostream& os) const override {
		os << "Cateta 1 = " << cmica << std::endl;
		os << "Cateta 2 = " << cmare << std::endl;
		Prajitura<T>::print(os);
	}
};

