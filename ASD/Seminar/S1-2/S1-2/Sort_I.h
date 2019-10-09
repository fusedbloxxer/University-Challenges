#pragma once

template<class Container>
class Sort_I
{
public:
	virtual void sort(Container&) const = 0;
	virtual ~Sort_I() = default;
};

