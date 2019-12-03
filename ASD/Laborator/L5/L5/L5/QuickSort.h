#pragma once
#include "DivideStrategy.h"
#include "InsertionSort.h"
#include <random>
#include <ctime>

template<typename T, typename SecondStrategy = InsertionSort<T>>
class QuickSort : public DivideStrategy<T>
{
public:
	QuickSort();
	virtual ~QuickSort() = default;

protected:
	int piv(T* elements, int left, int right) const;
	virtual void divide(T* elements, int left, int right) const override;
};

template<typename T, typename SecondStrategy>
inline QuickSort<T, SecondStrategy>::QuickSort()
{
	srand(time(NULL));
}

template<typename T, typename SecondStrategy>
inline void QuickSort<T, SecondStrategy>::divide(T* elements, int left, int right) const
{
	if (left < right)
	{
		int pivot = piv(elements, left, right);
		divide(elements, left, pivot - 1);
		divide(elements, pivot, right);
		// Attention here !
	}
}

template<typename T, typename SecondStrategy>
inline int QuickSort<T, SecondStrategy>::piv(T* elements, int left, int right) const
{
	T pivot = elements[left + rand() % (right - left)];
	int i = left, j = right;

	// Attention here !
	while (i <= j)
	{
		while (elements[i] < pivot) { ++i; }
		while (elements[j] > pivot) { --j; }

		// Attention here !
		if (i <= j)
		{
			T aux = elements[i];
			elements[i] = elements[j];
			elements[j] = aux;
			++i;
			--j;
		}
	}

	return i;
}