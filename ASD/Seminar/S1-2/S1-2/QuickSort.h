#pragma once
#include "Sort_I.h"

template<class Container>
class QuickSort : public Sort_I<Container>
{
public:
	virtual void sort(Container& container) const override {
		quick(container, 0, container.size() - 1);
	}

	virtual ~QuickSort() = default;

private:
	size_t part(Container& container, size_t st, size_t en) const {
		long long start = st, end = en;
		signed i{ 0 }, j{ -1 };
		while (start < end) {
			if (container[start] >= container[end]) {
				std::swap(container[start], container[end]);
				signed temp = j;
				i = -j;
				j = -temp;
			}
			start += i;
			end += j;
		}
		return start;
	}

	void quick(Container& container, size_t start, size_t end) const {
		if (start < end) {
			// Sort 1 element and return the position of the pivot.
			size_t piv = part(container, start, end);

			// Sort outside the pivot.
			quick(container, start, piv - 1);
			quick(container, piv + 1, end);
		}
	}
};

