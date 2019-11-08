#pragma once
#include <ostream>

class Printable_I
{
	friend std::ostream& operator<<(std::ostream& os, const Printable_I& obj);
public:
	virtual void print(std::ostream& os) const = 0;
	virtual ~Printable_I() = default;
};