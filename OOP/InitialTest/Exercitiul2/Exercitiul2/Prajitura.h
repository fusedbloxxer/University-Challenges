#pragma once
#include <exception>
#include "Constants.h"
#include "IO_I.h"

template<class T>
class Prajitura : public IO_I
{
protected:
	T h;
public:
	Prajitura(T h)
		:h{ h }
	{
	}

	// TEMPLATE PATTERN
	virtual T getGem() const {
		return getSurface() * h * MUtil::gem;
	}

	virtual T getFrisca() const = 0;
	virtual T getSurface() const = 0;
	virtual Prajitura* clone() const = 0;

	virtual void read(std::istream& is) override {
		std::cout << "Intaltimea = ";
		is >> h;
	}

	virtual void print(std::ostream& os) const override {
		os << "Inaltimea = " << h << std::endl;
	}

	virtual ~Prajitura() = default;

};

