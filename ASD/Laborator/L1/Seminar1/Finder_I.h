#pragma once

template<class Container, class Type>
class Finder_I
{
public:
	virtual long long find(const Container& container, const Type element) const = 0;
	virtual ~Finder_I() = default;
};

