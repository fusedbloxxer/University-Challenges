#pragma once
#include "SortStrategy.h"

template<typename T>
class InsertionSort : public SortStrategy<T>
{
public:
	virtual void sort(T* elements, int length) const;
	virtual ~InsertionSort() = default;
};

template<typename T>
inline void InsertionSort<T>::sort(T* elements, int length) const
{
	for (int i = 1; i < length; ++i)
	{
		int x = elements[i];
		int j = i - 1;

		while (j >= 0 && elements[j] > x)
		{
			elements[j + 1] = elements[j];
			--j;
		}

		elements[j + 1] = x;
	}
}