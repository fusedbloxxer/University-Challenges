#include "Utils.h"

void Utils::toLowerCase(std::string& str)
{
	for (auto& ch : str)
	{
		ch = ::tolower(ch);
	}
}
