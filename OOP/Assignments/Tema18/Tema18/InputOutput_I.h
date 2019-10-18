#pragma once
#include "Readable_I.h"
#include "Printable_I.h"

class InputOutput_I : public Readable_I, public Printable_I
{
public:
	virtual ~InputOutput_I() = 0;
};

