#pragma once
#include "Printable.h"
#include "Readable.h"

class IO_I : public Printable, public Readable
{
public:
	virtual void print(std::ostream& os) const = 0;
	virtual void read(std::istream& is) = 0;
	virtual ~IO_I() = default;
};