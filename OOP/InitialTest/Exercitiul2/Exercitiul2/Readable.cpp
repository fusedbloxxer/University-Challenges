#include "Readable.h"

std::istream& operator>>(std::istream& is, Readable& obj)
{
	obj.read(is);
	return is;
}