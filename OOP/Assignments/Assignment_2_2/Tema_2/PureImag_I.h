#pragma once
#include <ostream>

class PureImag_I
{
public:
	virtual bool isPure() const = 0;
	virtual ~PureImag_I() = default;
};