#include "AnimalFactory.h"

Animal* AnimalFactory::newInstance(std::string tip)
{
	toLowerCase(tip);

	if (tip == "animal")
	{
		return new Animal;
	}
	else
	{
		throw std::runtime_error{ "Could not create instance." };
	}
}

Animal* AnimalFactory::newInstance(std::istream& is)
{
	std::string str; is >> str; char ch; is.get(ch);

	auto animal = AnimalFactory::newInstance(str);

	is >> *animal;

	return animal;
}

void AnimalFactory::toLowerCase(std::string& str)
{
	for (auto& ch : str)
	{
		ch = ::tolower(ch);
	}
}
