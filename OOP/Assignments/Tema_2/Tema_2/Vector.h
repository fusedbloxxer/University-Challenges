#pragma once
#include "IO_I.h"
#include "Complex.h"
#include "PopException.h"
#include "NegativeSizeException.h"

template<class E = Complex<>>
class Vector : public IO_I
{
protected:
	int size; E* v;

public:
	// Standard
	Vector();
	Vector(int dim, E* v);
	Vector(const Vector& copy);
	Vector(Vector&& move) noexcept;
	Vector<E>& operator=(const Vector<E>& copy);
	Vector<E>& operator=(Vector<E>&& move) noexcept;
	virtual ~Vector();

	// Other methods
	int getSize() const;
	bool empty() const;
	virtual E pop();
	virtual void push(E element);

	// Inherited from IO_I
	virtual void read(std::istream& is) override;
	virtual void print(std::ostream& os) const override;
};

template<class E>
inline Vector<E>::Vector()
	:Vector(0, nullptr)
{
}

template<class E>
inline Vector<E>::Vector(int dim, E* v)
	: size{ dim }
{
	if (size < 0) {
		throw NegativeSizeException{ "Size cannot be negative !" };
	}

	this->v = new E[dim];
	for (int i = 0; i < size; ++i) {
		(this->v)[i] = v[i];
	}
}

template<class E>
inline Vector<E>::Vector(const Vector& copy)
	:size{ copy.size }, v{ new E[copy.size] }
{
	for (int i = 0; i < size; ++i) {
		v[i] = copy.v[i];
	}
}

template<class E>
inline Vector<E>::Vector(Vector&& move) noexcept
	:size{ move.size }, v{ move.v }
{
	move.v = nullptr;
	move.size = 0;
}

template<class E>
inline Vector<E>& Vector<E>::operator=(const Vector<E>& copy)
{
	if (this == &copy) {
		return *this;
	}

	if (v) {
		delete[] v;
	}

	size = copy.size;
	v = new E[size];
	for (int i = 0; i < size; ++i) {
		v[i] = copy.v[i];
	}

	return *this;
}

template<class E>
inline Vector<E>& Vector<E>::operator=(Vector<E>&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	if (v) {
		delete[] v;
	}

	size = move.size;
	v = move.v;
	move.v = nullptr;
	move.size = 0;

	return *this;
}

template<class E>
inline Vector<E>::~Vector()
{
	delete[] v;
}

template<class E>
inline int Vector<E>::getSize() const
{
	return size;
}

template<class E>
inline bool Vector<E>::empty() const
{
	return size == 0;
}

template<class E>
inline E Vector<E>::pop()
{
	if (size <= 0) {
		throw PopException{};
	}

	E copy = v[--size];

	if (size) {
		E* temp = new E[size];
		for (int i = 0; i < size; ++i) {
			temp[i] = v[i];
		}

		delete[] v;
		v = temp;
	}
	else {
		v = nullptr;
	}

	return copy;
}

template<class E>
inline void Vector<E>::push(E element)
{
	// Allocate more memory.
	E* temp = new E[size + 1];

	// Copy the content.
	for (int i = 0; i < size; ++i) {
		temp[i] = v[i];
	}

	// Insert the new element.
	temp[size++] = element;

	// Free old memory.
	delete[] v;

	// Retain a pointer to the new array.
	v = temp;
}

template<class E>
inline void Vector<E>::read(std::istream& is)
{
	if (v) {
		delete[] v;
	}

	is >> size; v = new E[size];
	for (int i = 0; i < size; ++i) {
		is >> v[i];
	}
}

template<class E>
inline void Vector<E>::print(std::ostream& os) const
{
	os << '[';
	for (int i = 0; i < size; ++i) {
		os << v[i];
		if (i + 1 != size) {
			os << ", ";
		}
	}
	os << ']';
}