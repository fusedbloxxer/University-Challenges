#pragma once
#include "IO_I.h"
#include <cmath>

class pol {
	int gr, coef;
	pol* next;
public:
	pol(int gr = 0, int coef = 0, pol * next = nullptr);

	int getGr() const;
	int getCoef() const;
	pol* getNext() const;

	void setGr(int gr);
	void setCoef(int coef);
	void setNext(pol* next);
};

class polinom : public IO_I {
	pol* head, * tail;
	// 6. Inmultirea cu un scalar.
	friend polinom operator*(const polinom&, int);
	friend polinom operator*(int, const polinom&);
public:
	// Constructors.
	polinom();
	polinom(const polinom& copy);
	polinom(polinom&& move) noexcept;
	
	// Operators.
	polinom& operator=(const polinom& copy);
	polinom& operator=(polinom&& move) noexcept;
	// 8. Suma a doua polinoame.
	polinom& operator+=(const polinom& poli);
	polinom operator+(const polinom& poli);

	// 6. Inmultirea cu un scalar interna.
	polinom& operator*=(int a);

	// 7. Valoare polinomului in x0, P(x0). 
	long double operator()(int x0) const;

	// Add methods.
	void add(int gr = 0, int coef = 0);

	pol* begin();
	pol* end();

	void clean();

	virtual ~polinom();

	// Inherited from IO_I
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;
};