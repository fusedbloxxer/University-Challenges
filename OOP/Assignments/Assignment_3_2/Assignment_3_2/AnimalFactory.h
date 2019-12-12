#pragma once
#include "Animal.h"
#include <string>
#include <cctype>

class  AnimalFactory final
{
	AnimalFactory();

public:
	static Animal* newInstance(std::string);
	static Animal* newInstance(std::istream& is);
};

