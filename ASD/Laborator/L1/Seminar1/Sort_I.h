#pragma once

template<class Container>
class Sort_I
{
public:
	virtual void sort(Container& container) const = 0;
	virtual ~Sort_I() = default;
};

