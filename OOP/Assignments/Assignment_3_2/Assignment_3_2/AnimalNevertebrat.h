#pragma once
#include "Animal.h"

class AnimalNevertebrat : public Animal
{
public:
	// Constructors & assignment operator
	AnimalNevertebrat(std::string nume = "", int picioare = 0, float lungime = 1.0f, float greutate = 1.0f, std::vector<Mediu> m = {}, float ani = 0.0f, float luni = 0.0f, float zile = 1.0f, bool unicelular = true);
	AnimalNevertebrat& operator=(const AnimalNevertebrat& animal);
	AnimalNevertebrat(const AnimalNevertebrat& animal);

	// Other methods
	virtual void citire(std::istream& is) override;
	virtual void afisare(std::ostream& os) const override;

	// Destructor
	virtual ~AnimalNevertebrat();

	// Getters and setters
	void setUnicelular(bool unicelular);
	bool getUnicelular() const;

protected:
	bool unicelular;
};

