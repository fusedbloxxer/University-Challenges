#include "Readable_I.h"

std::istream& operator>>(std::istream& is, Readable_I& obj)
{
	obj.read(is);
	return is;
}