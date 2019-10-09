#pragma once
#include "Sort_I.h"

template<class Container>
class BubbleSort : public Sort_I<Container>
{
public:
	virtual void sort(Container& container) const override;
	virtual ~BubbleSort() = default;
};

template<class Container>
void BubbleSort<Container>::sort(Container& container) const {
	bool isSorted;
	do {
		isSorted = true;
		for (size_t i{ 0 }; i < container.size() - 1; ++i) {
			if (container[i] > container[i + 1]) {
				std::swap(container[i], container[i + 1]);
				isSorted = false;
			}
		}
	} while (!isSorted);
}
