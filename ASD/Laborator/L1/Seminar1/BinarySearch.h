#pragma once
#include "Finder_I.h"

template<class Container, class Type>
class BinarySearch :
	public Finder_I<Container, Type>
{
public:
	virtual long long find(const Container& container, const Type element) const override {
		return binary(container, element, 0, container.size());
	}

	virtual ~BinarySearch() = default;
private:
	long long binary(const Container& container, const Type& element, size_t start, size_t end) const {
		if (start < end) {
			size_t mid = start + (end - start) / 2;
			if (container[mid] == element) {
				return mid;
			}
			else if (container[mid] > element) {
				return binary(container, element, start, mid);
			}
			else {
				return binary(container, element, mid + 1, end);
			}
		}
		return -1;
	}
};
