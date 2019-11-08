#pragma once
#include "IO_I.h"

template<class E>
class Vector : public IO_I
{
	int size; E* v;
public:
	Vector(int dim, E* v);
	Vector(const Vector& copy);
	Vector(Vector&& move) noexcept;
	Vector& operator=(const Vector& copy);
	Vector& operator=(Vector&& move) noexcept;
	virtual ~Vector();
	// pushback
	// Inherited from IO_I
	// Citirea suprascrie sau adauga ?
	virtual void read(std::istream& is) override;
	virtual void print(std::ostream& os) const override;
};

template<class E>
inline void Vector<E>::print(std::ostream& os) const
{
	os << '[';
	for (int i = 0; i < size; ++i) {
		os << v[i];
		if (i + 1 != size) {
			os << ' ';
		}
	}
	os << ']';
}
