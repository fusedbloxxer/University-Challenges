#pragma once
#include "Readable_I.h"
#include "Printable_I.h"
class IO_I :
	public Readable_I, public Printable_I
{
public:
	virtual ~IO_I() = default;
};

