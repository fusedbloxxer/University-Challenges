#pragma once
#include <regex>
#include <cctype>
#include "LinkedList.h"

class BigInteger : public InputOutput_I
{
	friend class Vector;
	using T = int;
	LinkedList<T>* list;
	bool isNegative;
	// 25 - 7
	// 75 + 7 = 82 -> 18
public:
	// Constructor initializing with your own type of list.
	BigInteger();
	BigInteger(long long longNumber);
	BigInteger(const BigInteger& copy);
	BigInteger(BigInteger&& move) noexcept;

	// Copy / Move Assignments.
	BigInteger& operator=(const BigInteger& copy);
	BigInteger& operator=(BigInteger&& move) noexcept;

	// Other operators
	BigInteger maxAbs(const BigInteger& numberTwo);
	BigInteger& operator+=(const BigInteger& big);
	BigInteger& operator-=(const BigInteger& big);
	BigInteger& operator*=(const BigInteger& big);
	bool operator==(const BigInteger& big) const;
	bool operator!=(const BigInteger& big) const;
	BigInteger operator+(const BigInteger& big);
	BigInteger operator-(const BigInteger& big);
	BigInteger operator*(const BigInteger& big);
	bool isZero() const;

	// Inherited from InputOutput_I
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	// Destructor.
	virtual ~BigInteger();

	// Static Method
	static BigInteger maxAbs(const BigInteger& numberOne, const BigInteger& numberTwo);

private:
	LinkedList<BigInteger::T>& omitTheCarry(LinkedList<T>&);
	LinkedList<BigInteger::T>& complementOfTen(LinkedList<T>&, size_t digits);
	LinkedList<BigInteger::T>& addition(LinkedList<T>& firstList, const LinkedList<T>& secondList);
	LinkedList<BigInteger::T>& complementOfNine(LinkedList<T>&, size_t digits);
	LinkedList<BigInteger::T>& subtraction(LinkedList<T>& firstList, const LinkedList<T>& secondList);
};