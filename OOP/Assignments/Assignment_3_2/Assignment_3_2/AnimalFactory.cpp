#include "AnimalFactory.h"
#include "AnimalVertebrat.h"
#include "AnimalNevertebrat.h"
#include <stdexcept>
#include "Utils.h"

AnimalFactory::AnimalFactory()
{}

Animal* AnimalFactory::newInstance(std::string tip)
{
	Utils::toLowerCase(tip);

	if (tip == "animal")
	{
		return new Animal;
	}
	else if (tip == "vertebrat")
	{
		return new AnimalVertebrat;
	}
	else if (tip == "nevertebrat")
	{
		return new AnimalNevertebrat;
	}
	else
	{
		throw std::domain_error{ "Could not create instance." };
	}
}

Animal* AnimalFactory::newInstance(std::istream& is)
{
	std::string str; is >> str; char ch; is.get(ch);
	 
	auto animal = AnimalFactory::newInstance(str);

	is >> *animal;

	return animal;
}
