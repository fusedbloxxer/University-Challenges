#pragma once
#include <exception>
#include <string>

class PopException : public std::exception
{
	inline static const char* const ERROR_MESSAGE = "Cannot pop more elements.";
public:
	PopException();
	explicit PopException(char const* const message) noexcept;
	virtual char const* what() const override;
	virtual ~PopException() = default;
};

