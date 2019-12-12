#include "NegativeSizeException.h"
#include <string>

NegativeSizeException::NegativeSizeException()
	:NegativeSizeException(ERROR_MESSAGE)
{
}

NegativeSizeException::NegativeSizeException(char const* const message) noexcept
	:std::exception((std::string("NegativeSizeException: ") + message).c_str())
{
}

char const* NegativeSizeException::what() const
{
	return std::exception::what();
}