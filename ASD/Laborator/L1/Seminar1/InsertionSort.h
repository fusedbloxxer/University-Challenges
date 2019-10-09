#pragma once
#include "Sort_I.h"
template<class Container>
class InsertionSort :
	public Sort_I<Container>
{
public:
	virtual void sort(Container& container) const override;
	virtual ~InsertionSort() = default;
};

template<class Container>
void InsertionSort<Container>::sort(Container& container) const
{
	for (size_t i{ 1 }; i < container.size(); ++i) {
		auto x = container[i];
		long long j = i - 1;
		while (j >= 0 && x < container[j]) {
			container[j + 1] = container[j];
			--j;
		}
		container[j + 1] = x;
	}
}
