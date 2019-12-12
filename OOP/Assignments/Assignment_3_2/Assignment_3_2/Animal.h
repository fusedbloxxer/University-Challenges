#pragma once
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <array>

#define NUME_VAR(variabila) (#variabila) 

class Animal
{
public:
	// Nested enum
	enum Mediu {
		TERESTRU,
		AERIAN,
		ACVATIC
	};

	// Static conversion functions
	static std::string mediuToStr(Mediu mediu);
	static Mediu strToMediu(std::string str);

	// Constructors & assignment operator
	Animal(const Animal& animal);
	Animal& operator=(const Animal& animal);
	Animal(std::string nume = "", int picioare = 0, float lungime = 1.0f, float greutate = 1.0f, std::vector<Mediu> m = {}, float ani = 0.0f, float luni = 0.0f, float zile = 1.0f);

	// Methods
	virtual void afisare(std::ostream& os) const;
	virtual void citire(std::istream& is);
	virtual void respira() const = 0;
	virtual void mananca() const = 0;
	virtual void sunet() const = 0;

	// Virtual destructor
	virtual ~Animal();

	// Getters and setters
	float getLungime() const;
	float getGreutate() const;
	int getPicioare() const;
	std::string getNume() const;
	std::array<float, 3> getDurataDeViata() const;
	std::unordered_set<Mediu> getMediiDeViata() const;

	void setPicioare(int picioare);
	void setLungime(float lungime);
	void setGreutate(float greutate);
	void setDurataDeViata(float ani, float luni, float zile);
	void setMediiDeViata(const std::vector<Mediu>& medii);

	// Friends
	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
	friend std::istream& operator>>(std::istream& is, Animal& animal);

protected:
	// Data
	std::string nume;
	int numarPicioare;
	float lungime, greutate;
	std::unordered_set<Mediu> medii; 
	std::array<float, 3> durataDeViata;

private:
	std::string gramatica(float substantiv, std::string sing = "", std::string plu = "") const;
};