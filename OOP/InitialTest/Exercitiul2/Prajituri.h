#pragma once
#include <vector>
#include <iomanip>
#include "Printable.h"

template<class T>
class Prajituri : public Printable
{
private:
	long double totalGem, totalFrisca;
	std::vector<T*>* pr;

public:
	Prajituri() :pr{ new std::vector<T*> }, totalGem{ 0 }, totalFrisca{ 0 } {}

	Prajituri(const Prajituri& copy)
		:pr{ new std::vector<T*> }
	{

		pr->reserve(copy.pr->size() + 1);
		for (const auto& element : *(copy.pr)) {
			// Allocate space on heap and copy the values of the elements.
			pr->push_back(element->clone());
			// Increase quantities.
			totalGem += element->getGem();
			totalFrisca += element->getFrisca();
		}
	}

	Prajituri(Prajituri&& move)
		:pr{ move.pr }, totalFrisca{}
	{
		move.pr = nullptr;
	}

	Prajituri& operator=(const Prajituri& copy)
	{
		if (this == &copy) {
			return *this;
		}

		if (pr) {
			cleanContainer();
			// Making sure. DO SOME TESTING !!!
			pr->clear();
		}

		for (const auto& element : *copy.pr) {
			pr->push_back(element->clone());
		}
		totalFrisca = copy.totalFrisca;
		totalGem = copy.totalGem;

		return *this;
	}

	Prajituri& operator=(Prajituri&& move)
	{
		if (this == &move) {
			return *this;
		}

		if (pr) {
			cleanContainer();
			pr->clear();
		}

		delete pr;
		pr = move.pr;
		move.pr = nullptr;

		return *this;
	}

	~Prajituri() {
		cleanContainer();
		delete pr;
	}

	void cleanContainer()
	{
		if (pr) {
			for (auto& elem : *pr) {
				delete elem;
			}
		}
	}

	void add(T* elem) {
		pr->push_back(elem);

		const auto gem = elem->getGem();
		const auto frisca = elem->getFrisca();

		// Add gem and frisca to the total.
		totalGem += gem;
		totalFrisca += frisca;

		std::cout << "\nNecesarul de gem este de " << gem << " grame\n";
		std::cout << "Necesarul de frisca este de " << frisca << " grame\n";
	}

	void remove(size_t index) {
		if (index >= 0 && index < pr->size()) {
			// Remove gem and frisca as well.
			totalGem -= pr->at(index)->getGem();
			totalFrisca -= pr->at(index)->getFrisca();

			pr->erase(pr->begin() + index);

			std::cout << "Prajitura a " << index << "-a a fost eliminata." << std::endl;
			std::cout << std::endl;
		}
	}

	void total(std::ostream& os) const {
		os << "Necesarul de gem este " << totalGem << " de grame." << std::endl;
		os << "Necesarul de frisca este " << totalFrisca << " de frisca." << std::endl;
	}

	// Inherited from Readable
	virtual void print(std::ostream& os) const override {
		os << "Prajituri -> [\n";
		for (const auto& elem : *pr) {
			os << *elem << std::endl;
		}
		os << "]\n";
		
		total(os);
	}
};

