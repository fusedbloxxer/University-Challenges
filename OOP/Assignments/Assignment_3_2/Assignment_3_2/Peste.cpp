#include "Peste.h"

Peste::Peste(std::string nume, int picioare, float lungime, float greutate, std::vector<Mediu> m, float ani, float luni, float zile, int pericol, std::string tip)
	:AnimalVertebrat{ nume, picioare, lungime, greutate, m, ani, luni, zile, pericol, tip }
{
}

Peste& Peste::operator=(const Peste& peste)
{
	if (this == &peste)
	{
		return *this;
	}

	AnimalVertebrat::operator=(peste);

	return *this;
}

Peste::Peste(const Peste& peste)
	: AnimalVertebrat(peste)
{
}

Peste::~Peste()
{
}
