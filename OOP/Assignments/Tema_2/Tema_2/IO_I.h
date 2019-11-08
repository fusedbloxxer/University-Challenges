#pragma once
#include "Printable_I.h"
#include "Readable_I.h"

class IO_I : public Printable_I, public Readable_I
{
public:
	virtual ~IO_I() = default;
};

