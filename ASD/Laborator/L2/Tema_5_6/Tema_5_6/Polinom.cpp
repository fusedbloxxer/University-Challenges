#include "Polinom.h"
#include <iostream>
#include <sstream>
#include <regex>

pol::pol(int gr, int coef, pol* next)
	:gr{ gr }, coef{ coef }, next{ next }
{
}

inline int pol::getGr() const
{
	return gr;
}

inline int pol::getCoef() const
{
	return coef;
}

inline pol* pol::getNext() const
{
	return next;
}

inline void pol::setGr(int gr)
{
	this->gr = gr;
}

inline void pol::setCoef(int coef)
{
	this->coef = coef;
}

inline void pol::setNext(pol* next)
{
	this->next = next;
}

polinom::polinom()
	:head{ nullptr }, tail{ nullptr }
{
}

polinom::polinom(const polinom& copy)
	: head{ nullptr }, tail{ nullptr }
{
	for (auto var = copy.head; var; var = var->getNext()) {
		add(var->getGr(), var->getCoef());
	}
}

polinom::polinom(polinom&& move) noexcept
	:head{ move.head }, tail{ move.tail }
{
	move.tail = nullptr;
	move.head = nullptr;
}

polinom& polinom::operator=(const polinom& copy)
{
	if (this == &copy) {
		return *this;
	}

	clean();

	for (auto var = copy.head; var; var = var->getNext()) {
		add(var->getGr(), var->getCoef());
	}

	return *this;
}

polinom& polinom::operator=(polinom&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	clean();

	head = move.head;
	tail = move.tail;
	move.tail = nullptr;
	move.head = nullptr;

	return *this;
}

polinom& polinom::operator+=(const polinom& poli)
{
	for (auto var = poli.head; var; var = var->getNext()) {
		add(var->getGr(), var->getCoef());
	}

	return *this;
}

polinom polinom::operator+(const polinom& poli)
{
	return polinom{ *this } += poli;
}

void polinom::print(std::ostream& os) const
{
	for (auto val = head; val; val = val->getNext()) {
		if (val != head && val->getCoef() >= 0) {
			os << " + ";
		}
		else {
			os << ' ';
		}

		os << val->getCoef();

		switch (val->getGr())
		{
		case 0:
			break;
		case 1:
			os << "X";
			break;
		default:
			os << "X^" << val->getGr();
			break;
		}
	}
}

void polinom::read(std::istream& is)
{
	std::cout << "Enter polinom(coef, gr): "; int coef, gr;
	std::string buf; std::getline(is, buf);
	std::stringstream ss{ buf };
	while (!ss.eof()) {
		ss >> coef >> gr;
		add(gr, coef);
	}
}

polinom& polinom::operator*=(int a)
{
	for (auto var = head; var; var = var->getNext()) {
		var->setCoef(var->getCoef() * a);
	}
	return *this;
}

long double polinom::operator()(int x0) const
{
	long double sum{ 0 };
	for (auto var = head; var; var = var->getNext()) {
		sum += var->getCoef() * double(pow(x0, var->getGr()));
	}
	return sum;
}

void polinom::add(int gr, int coef)
{
	// Sorted insertions.
	if (!head) {
		// No nodes. Add a new one !
		head = tail = new pol{ gr, coef, nullptr };
	}
	else {
		// Add at head.
		if (gr > head->getGr()) {
			head = new pol{ gr, coef, head };
		}
		else if (gr == head->getGr()) {
			head->setCoef(head->getCoef() + coef);
		}
		else {
			// Add in middle.
			for (auto var = head; var->getNext(); var = var->getNext()) {
				if (gr > var->getNext()->getGr()) {
					var->setNext(new pol{ gr, coef, var->getNext() });
					return;
				}
				else if (gr == var->getNext()->getGr()) {
					var->getNext()->setCoef(var->getNext()->getCoef() + coef);
					return;
				}
			}
			// Add at tail.
			tail->setNext(new pol{ gr, coef, nullptr });
			tail = tail->getNext();
		}
	}
}

pol* polinom::begin()
{
	return head;
}

pol* polinom::end()
{
	return tail;
}

void polinom::clean()
{
	tail = nullptr;
	while (head) {
		auto temp = head;
		head = head->getNext();
		delete temp;
	}
}

polinom::~polinom()
{
	clean();
}

polinom operator*(const polinom& p, int a)
{
	return polinom{ p } *= a;
}

polinom operator*(int a, const polinom& p)
{
	return polinom{ p } *= a;
}
