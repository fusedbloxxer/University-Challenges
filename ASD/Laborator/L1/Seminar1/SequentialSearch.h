#pragma once
#include "Finder_I.h"

template<class Container, class Type>
class SequentialSearch : public Finder_I<Container, Type>
{
public:
	virtual long long find(const Container& contaner, const Type element) const override;
	virtual ~SequentialSearch() = default;
};

template<class Container, class Type>
inline long long SequentialSearch<Container, Type>::find(const Container& container, const Type element) const
{
	for (size_t i{ 0 }; i < container.size(); ++i) {
		if (element == container[i]) {
			return i;
		}
	}
	return -1;
}
