#pragma once
#include "Animal.h"
#include <string>
#include <cctype>

class AnimalFactory
{
public:
	static Animal* newInstance(std::string);
	static Animal* newInstance(std::istream& is);

private:
	static void toLowerCase(std::string& str);
};

