#include "AnimalVertebrat.h"
#include <stdexcept>
#include "Utils.h"

AnimalVertebrat::AnimalVertebrat(std::string nume, int picioare, float lungime, float greutate, std::vector<Mediu> m, float ani, float luni, float zile, int pericol, std::string tip)
	:Animal{ nume, picioare, lungime, greutate, m , ani, luni, zile }
{
	setPericol(pericol);
	setTip(tip);
}

AnimalVertebrat& AnimalVertebrat::operator=(const AnimalVertebrat& animal)
{
	if (this == &animal)
	{
		return *this;
	}

	Animal::operator=(animal);
	pericol = animal.pericol;
	tip = animal.tip;

	return *this;
}

AnimalVertebrat::AnimalVertebrat(const AnimalVertebrat& animal)
	:Animal(animal), pericol{ animal.pericol }, tip{ animal.tip }
{
}

void AnimalVertebrat::citire(std::istream& is)
{
	Animal::citire(is);
	is >> pericol >> tip;
}

void AnimalVertebrat::afisare(std::ostream& os) const
{
	Animal::afisare(os);

	os << ", periculos: " <<
		(pericol <= 10 ? "nu" :
		(pericol <= 20 ? "putin" :
			(pericol <= 40 ? "da" :
			(pericol <= 55 ? "cam periculos" :
				(pericol <= 80 ? "foarte periculos" : "moarte instantanee")))));

	os << ", tip: " << tip;
}

AnimalVertebrat::~AnimalVertebrat()
{
}

void AnimalVertebrat::setPericol(int pericol)
{
	if (pericol < 0 || pericol > 100)
	{
		throw std::out_of_range{ "Pericolul trebuie sa fie intre 0 si 100 !" };
	}

	this->pericol = pericol;
}

void AnimalVertebrat::setTip(std::string tip)
{
	Utils::toLowerCase(tip);
	if (tip == "inteligent")
	{
		this->tip = tip;
	}
	else if (tip == "agil")
	{
		this->tip = tip;
	}
	else if (tip == "puternic")
	{
		this->tip = tip;
	}
	else
	{
		throw std::domain_error{ "Nu exista acest tip de animal vertebrat !" };
	}
}

int AnimalVertebrat::getPericol() const
{
	return pericol;
}

std::string AnimalVertebrat::getTip() const
{
	return tip;
}
