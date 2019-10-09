#pragma once
#include "Sort_I.h"
#include <vector>

template<class Container>
class MergeSort : public Sort_I<Container>
{
public:
	// Compromis: pentru ca nu am specificat tipul elementului sunt fortat sa folosesc containerul dat.
	virtual void sort(Container& container) const override {
		mergeSort(container, 0, container.size() - 1);
	}
	
	virtual ~MergeSort() = default;

private:
	void merge(Container& container, size_t start, size_t mid, size_t end) const {
		Container c1, c2;

		for (size_t i{ start }; i <= mid; ++i) {
			c1.push_back(container[i]);
		}

		for (size_t i{ mid + 1 }; i <= end; ++i) {
			c2.push_back(container[i]);
		}

		mid = start;
		start = 0;
		end = 0;

		while (start < c1.size() && end < c2.size()) {
			if (c1[start] < c2[end]) {
				container[mid++] = c1[start++];
			}
			else
			{
				container[mid++] = c2[end++];
			}
		}

		while (start < c1.size()) {
			container[mid++] = c1[start++];
		}

		while (end < c2.size()) {
			container[mid++] = c2[end++];
		}
	}

	void mergeSort(Container& container, size_t start, size_t end) const {
		if (start < end) {
			size_t mid = start + (end - start) / 2;

			mergeSort(container, start, mid);
			mergeSort(container, mid + 1, end);

			merge(container, start, mid, end);
		}
	}
};

