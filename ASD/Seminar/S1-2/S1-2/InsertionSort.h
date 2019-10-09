#pragma once
#include "Sort_I.h"

template<class Container>
class InsertionSort : public Sort_I<Container>
{
public:
	virtual void sort(Container& container) const override;
	virtual ~InsertionSort() = default;
};

template<class Container>
void InsertionSort<Container>::sort(Container& container) const
{
	for (size_t i{ 1 }; i < container.size(); ++i) {
		for (size_t j{ i }; j > 0; --j) {
			if (container[j - 1] > container[j]) {
				std::swap(container[j - 1], container[j]);
			}
			else
			{
				break;
			}
		}
	}
}
