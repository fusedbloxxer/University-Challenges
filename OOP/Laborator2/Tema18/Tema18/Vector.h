#pragma once
#include "BigInteger.h"

class Vector : public InputOutput_I
{
	BigInteger* container;
	size_t sz, memory;
public:
	// Constructors
	Vector();
	Vector(const Vector& copy);
	Vector(Vector&& move) noexcept;
	Vector(std::initializer_list<BigInteger> init);

	// Copy / Move Assignments
	Vector& operator=(const Vector& copy);
	Vector& operator=(Vector&& move) noexcept;

	// Operators
	BigInteger operator*(const Vector& vector) const;
	Vector& operator+=(const Vector& vector);
	Vector& operator-=(const Vector& vector);
	Vector operator+(const Vector& vector) const;
	Vector operator-(const Vector& vector) const;
	bool operator==(const Vector& vector) const;
	bool operator!=(const Vector& vector) const;

	// Methods
	// Insertion operations
	void insert(size_t index, const BigInteger& num);
	void push_front(const BigInteger& num);
	void push_back(const BigInteger& num);
	BigInteger maxAbs() const;

	// Remove operations
	void remove(size_t index);
	void remove_front();
	void remove_back();

	// Size operations
	size_t realSize() const;
	bool isEmpty() const;
	size_t size() const;

	// Inherited from InputOutput_I.
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	// Destructor.
	virtual ~Vector();
};

