#pragma once
#include <exception>

class NegativeSizeException : public std::exception
{
	inline static const char* const ERROR_MESSAGE = "Size cannot be negative !";
public:
	NegativeSizeException();
	explicit NegativeSizeException(char const* const message) noexcept;
	virtual char const* what() const override;
	virtual ~NegativeSizeException() = default;
};

