#pragma once
#include <iostream>

class Readable
{
	friend std::istream& operator>>(std::istream& is, Readable& obj);
public:
	virtual void read(std::istream& is) = 0;
	virtual ~Readable() = default;
};

