#pragma once
#include "Constants.h"
#include "Prajitura.h"

template<class T>
class Dreptunghi : public Prajitura<T>
{
private:
	T mic, mare;
public:
	Dreptunghi(T mic = 0, T mare = 0, T h = 0)
		:mic{ mic }, mare{ mare }, Prajitura<T>{ h } {}

	Dreptunghi(const Dreptunghi& copy)
		:mic{ copy.mic }, mare{ copy.mare }, Prajitura<T>{ copy.h } {}

	Dreptunghi& operator=(const Dreptunghi& copy)
	{
		mic = copy.mic;
		mare = copy.mare;
		Prajitura<T>::h = copy.h;
		return *this;
	}

	Prajitura<T>* clone() const override {
		return new Dreptunghi<T>{ *this };
	}

	T getSurface() const override
	{
		return mic * mare;
	}

	T getFrisca() const override
	{
		return MUtil::frisca * (2 * (mic + mare) * Prajitura<T>::h + mic * mare);
	}

	virtual void print(std::ostream& os) const override {
		os << "Latura mica = " << mic << std::endl;
		os << "Latura mare = " << mare << std::endl;
		Prajitura<T>::print(os);
	}

	virtual void read(std::istream& is) override {
		std::cout << "Latura mica = "; is >> mic;
		std::cout << "Latura mare = "; is >> mare;
		Prajitura<T>::read(is);
	}
};

