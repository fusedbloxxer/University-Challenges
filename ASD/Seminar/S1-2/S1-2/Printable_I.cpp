#include "Printable_I.h"

std::ostream& operator<<(std::ostream& os, const Printable_I& obj)
{
	obj.print(os);
	return os;
}
