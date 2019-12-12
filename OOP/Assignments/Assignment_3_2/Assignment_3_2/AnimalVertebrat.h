#pragma once
#include "Animal.h"

class AnimalVertebrat : public Animal
{
public:
	// Constructor & assignment operator
	AnimalVertebrat(std::string nume = "", int picioare = 0, float lungime = 1.0f, float greutate = 1.0f, std::vector<Mediu> m = {}, float ani = 0.0f, float luni = 0.0f, float zile = 1.0f, int pericol = 0, std::string tip = "inteligent");
	AnimalVertebrat& operator=(const AnimalVertebrat& animal);
	AnimalVertebrat(const AnimalVertebrat& animal);

	// Other methods
	virtual void citire(std::istream& is) override;
	virtual void afisare(std::ostream& os) const override;

	// Destructor
	virtual ~AnimalVertebrat();

	// Getters and setters
	void setPericol(int pericol);
	void setTip(std::string tip);

	int getPericol() const;
	std::string getTip() const;

protected:
	int pericol;
	std::string tip;
};