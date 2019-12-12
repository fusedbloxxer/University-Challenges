#include "AnimalNevertebrat.h"

AnimalNevertebrat::AnimalNevertebrat(std::string nume, int picioare, float lungime, float greutate, std::vector<Mediu> m, float ani, float luni, float zile, bool unicelular)
	:Animal{ nume, picioare, lungime, greutate, m, ani, luni, zile }, unicelular{ unicelular }
{
}

AnimalNevertebrat& AnimalNevertebrat::operator=(const AnimalNevertebrat& animal)
{
	if (this == &animal)
	{
		return *this;
	}

	Animal::operator=(animal);
	unicelular = animal.unicelular;

	return *this;
}

AnimalNevertebrat::AnimalNevertebrat(const AnimalNevertebrat& animal)
	:Animal(animal), unicelular{ animal.unicelular }
{
}

void AnimalNevertebrat::citire(std::istream& is)
{
	Animal::citire(is);
	std::string uni;
	is >> uni;

	if (std::strcmp(uni.c_str(), "unicelular") == 0)
	{
		this->unicelular = true;
	}
	else if (std::strcmp(uni.c_str(), "pluricelular") == 0)
	{
		this->unicelular = false;
	}
	else
	{
		throw std::domain_error{ "Tipul celular nu a putut fi determinat !" };
	}
}

void AnimalNevertebrat::afisare(std::ostream& os) const
{
	Animal::afisare(os);
	os << ", tip: " << (unicelular ? "unicelular" : "pluricelular");
}

AnimalNevertebrat::~AnimalNevertebrat()
{
}

void AnimalNevertebrat::setUnicelular(bool unicelular)
{
	this->unicelular = unicelular;
}

bool AnimalNevertebrat::getUnicelular() const
{
	return unicelular;
}
