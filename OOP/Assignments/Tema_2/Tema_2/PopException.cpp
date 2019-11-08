#include "PopException.h"

PopException::PopException()
	:PopException(ERROR_MESSAGE)
{
}

PopException::PopException(char const* const message) noexcept
	:std::exception((std::string("PopException: ") + message).c_str())
{
}

char const* PopException::what() const
{
	return std::exception::what();
}
