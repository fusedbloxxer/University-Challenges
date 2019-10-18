#pragma once
#include "Prajitura.h"
#include "Constants.h"

template<class T>
class Patrat : public Prajitura<T>
{
private:
	T latura;
public:
	Patrat(T latura = 0, T h = 0)
		:latura{ latura }, Prajitura<T>{ h } {}

	Patrat(const Patrat& copy)
		:latura{ copy.latura }, Prajitura<T>{copy.h} {}

	Patrat& operator=(const Patrat& copy)
	{
		latura = copy.latura;
		Prajitura<T>::h = copy.h;
		return *this;
	}

	Prajitura<T>* clone() const override {
		return new Patrat<T>{ *this };
	}

	T getSurface() const override
	{
		return latura * latura;
	}

	T getFrisca() const override
	{
		return MUtil::frisca * (4 * latura * Prajitura<T>::h + latura * latura);
	}

	virtual void print(std::ostream& os) const override {
		os << "Latura = " << latura << std::endl;
		Prajitura<T>::print(os);
	}

	virtual void read(std::istream& is) override {
		std::cout << "Latura = "; is >> latura;
		Prajitura<T>::read(is);
	}
};

