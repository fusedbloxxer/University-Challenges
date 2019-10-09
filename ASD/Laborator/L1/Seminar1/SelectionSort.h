#pragma once
#include "Sort_I.h"

template<class Container>
class SelectionSort : public Sort_I<Container>
{
public:
	virtual void sort(Container& container) const override;
	virtual ~SelectionSort() = default;
};

template<class Container>
void SelectionSort<Container>::sort(Container& container) const
{
	for (size_t i{ 0 }; i < container.size() - 1; ++i) {
		size_t p{ i };
		for (size_t j{ i + 1 }; j < container.size(); ++j) {
			if (container[p] > container[j]) {
				p = j;
			}
		}
		std::swap(container[p], container[i]);
	}
}