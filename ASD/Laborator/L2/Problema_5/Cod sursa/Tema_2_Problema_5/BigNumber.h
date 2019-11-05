#pragma once
#include "SimpleList.h"
#include "IO_I.h"

class BigNumber : public IO_I
{
	SimpleList<int>* list;
	bool isNegative;
public:
	BigNumber();
	BigNumber(long long);
	BigNumber(const BigNumber& copy);
	BigNumber(BigNumber&& move) noexcept;

	BigNumber& operator=(const BigNumber& copy);
	BigNumber& operator=(BigNumber&& move) noexcept;
	BigNumber& operator+=(const BigNumber& num);
	BigNumber operator+(const BigNumber&);

	bool isZero() const;

	// Inherited via IO_I
	virtual void read(std::istream& is) override;

	virtual void print(std::ostream& os) const override;

	~BigNumber();
private:
	void subtraction(List<int>*, List<int>*);
	void addition(List<int>*, List<int>*);
	void complementOfNine(List<int>*, size_t);
	void complementOfTen(List<int>*, size_t);
	void rec(SimpleNode<int>*) const;
};