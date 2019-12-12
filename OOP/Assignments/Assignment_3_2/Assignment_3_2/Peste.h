#pragma once
#include "AnimalVertebrat.h"

class Peste : public AnimalVertebrat
{
public:
	// Constructors
	Peste(std::string nume = "", int picioare = 0, float lungime = 1.0f, float greutate = 1.0f, std::vector<Mediu> m = {}, float ani = 0.0f, float luni = 0.0f, float zile = 1.0f, int pericol = 0, std::string tip = "inteligent");
	Peste& operator=(const Peste& peste);
	Peste(const Peste& peste);

	// TODO; inot

	// Destructor
	virtual ~Peste();
};

