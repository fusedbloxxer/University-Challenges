#include "Animal.h"

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
	animal.afisare(os);
	return os;
}

std::istream& operator>>(std::istream& is, Animal& animal)
{
	animal.citire(is);
	return is;
}

Animal::Animal(std::string nume, int picioare, float lungime, float greutate, std::vector<Mediu> m, float ani, float luni, float zile)
	:nume{ nume }
{
	setPicioare(picioare);
	setLungime(lungime);
	setGreutate(greutate);
	setMediiDeViata(m);
	setDurataDeViata(ani, luni, zile);
}

Animal::Animal(const Animal& animal)
	:nume{ animal.nume }, numarPicioare{ animal.numarPicioare }, lungime{ animal.lungime }, greutate{ animal.greutate }, medii{ animal.medii }, durataDeViata{ animal.durataDeViata } {}

Animal& Animal::operator=(const Animal& animal)
{
	if (this == &animal)
	{
		return *this;
	}

	nume = animal.nume;
	numarPicioare = animal.numarPicioare;
	lungime = animal.lungime;
	greutate = animal.greutate;
	medii = animal.medii;
	durataDeViata = animal.durataDeViata;

	return *this;
}

std::string Animal::mediuToStr(Mediu mediu)
{
	switch (mediu)
	{
	case TERESTRU:
		return NUME_VAR(TERESTRU);
	case AERIAN:
		return NUME_VAR(AERIAN);
	case ACVATIC:
		return NUME_VAR(ACVATIC);
	default:
		throw std::runtime_error{ "Conversie invalida mediu -> sir de caractere !" };
	}
}

Animal::Mediu Animal::strToMediu(std::string str)
{
	if (str == NUME_VAR(TERESTRU))
	{
		return Mediu::TERESTRU;
	}
	else if (str == NUME_VAR(AERIAN))
	{
		return Mediu::AERIAN;
	}
	else if (str == NUME_VAR(ACVATIC))
	{
		return Mediu::ACVATIC;
	}
	else
	{
		throw std::runtime_error{ "Converia sir de caractere -> mediu a esuat !" };
	}
}

void Animal::afisare(std::ostream& os) const
{
	os << "Numele animalului: " << nume << ", lungimea: " << gramatica(lungime, "metru", "metri")
		<< "greutate: " << greutate << " kg, durata de viata: " << gramatica(24, "an", "ani")
		<< gramatica(durataDeViata[1], "luna", "luni") << gramatica(durataDeViata[2], "zi", "zile")
		<< " numar picioare: " << numarPicioare << ", medii de viata: ";

	if (medii.size() == 0)
	{
		os << "nu are";
	}
	else
	{
		decltype(medii.size()) count = 0;
		for (std::unordered_set<Mediu>::iterator it = medii.begin(); it != medii.end(); ++it, ++count)
		{
			os << mediuToStr(*it);

			if (count + 1 != medii.size())
			{
				os << ", ";
			}
		}
	}
}

void Animal::citire(std::istream& is)
{
	// Read name
	std::getline(is, nume);

	// Read some data
	is >> numarPicioare; setPicioare(numarPicioare);
	is >> lungime; setLungime(lungime);
	is >> greutate; setGreutate(greutate);

	// Read medii de viata
	int m; is >> m; if (m < 0) { throw std::runtime_error{ "Numar de medii invalid !" }; }
	for (std::string temp; m && is >> temp; --m)
	{
		medii.insert(Animal::strToMediu(temp));
	}

	// Read durata de viata
	float ani, luni, zile; 
	is >> ani >> luni >> zile;
	setDurataDeViata(ani, luni, zile);
}

Animal::~Animal() {}

void Animal::setPicioare(int picioare)
{
	if (picioare < 0) { throw std::runtime_error{ "Animalul nu poate avea numar negativ de picioare." }; }
	this->numarPicioare = picioare;
}

void Animal::setLungime(float lungime)
{
	if (lungime <= 0) { throw std::runtime_error{ "Animalul nu poate avea lungime <= 0 !" }; }
	this->lungime = lungime;
}

void Animal::setGreutate(float greutate)
{
	if (greutate <= 0) { throw std::runtime_error{ "Animalul nu poate avea greutate <= 0 !" }; }
	this->greutate = greutate;
}

void Animal::setDurataDeViata(float ani, float luni, float zile)
{
	if (ani < 0.0f || luni < 0.0f || zile < 0.0f || ani + luni + zile == 0.0f)
	{
		throw std::runtime_error{ "Varsta este invalida !" };
	}

	durataDeViata[0] = ani;
	durataDeViata[1] = luni;
	durataDeViata[2] = zile;
}

void Animal::setMediiDeViata(const std::vector<Mediu>& medii)
{
	for (const auto& e : medii)
	{
		this->medii.insert(e);
	}
}

std::string Animal::getNume() const
{
	return nume;
}

int Animal::getPicioare() const
{
	return numarPicioare;
}

float Animal::getLungime() const
{
	return lungime;
}

float Animal::getGreutate() const
{
	return greutate;
}

std::unordered_set<Animal::Mediu> Animal::getMediiDeViata() const
{
	return this->medii;
}

std::array<float, 3> Animal::getDurataDeViata() const
{
	return this->durataDeViata;
} 

inline std::string Animal::gramatica(float substantiv, std::string sing, std::string plu) const
{
	return std::to_string(substantiv) + " " + ((substantiv == 1.0f) ? sing : plu) + ", ";
}