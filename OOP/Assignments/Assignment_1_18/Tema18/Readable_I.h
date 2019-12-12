#pragma once
#include <iostream>

class Readable_I
{
	friend std::istream& operator>>(std::istream& is, Readable_I& obj);
public:
	virtual void read(std::istream& is) = 0;
	virtual ~Readable_I() = default;
};

