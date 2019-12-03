#pragma once
#include "InsertionSort.h"
#include "QuickSort.h"
#include "Optim.h"

template<typename T, typename SecondStrategy = InsertionSort<T>>
class OptimQuickSort : public QuickSort<T>, public Optim<T, SecondStrategy>
{
public:
	OptimQuickSort(int seqLen = 11);
	virtual ~OptimQuickSort() = default;

protected:
	virtual void divide(T* elements, int left, int right) const override
	{
		int length = right - left + 1;

		if (length <= Optim<T, SecondStrategy>::seqLen)
		{
			Logger::d("BEFORE INSERTION: ");
			print(elements + left, right - left + 1, false);

			Optim<T, SecondStrategy>::strategy.sort(elements + left, length);

			Logger::d("AFTER INSERTION: ");
			print(elements + left, right - left + 1, false);
		}
		else if (left < right)
		{
			Logger::d("BEFORE OptimQuickSort: ");
			print(elements + left, right - left + 1, false);

			int pivot = QuickSort<T>::piv(elements, left, right);

			Logger::d("AFTER OptimQuickSort: ");
			print(elements + left, right - left + 1, false);

			divide(elements, left, pivot - 1);
			divide(elements, pivot, right);
		}
	}
};

template<typename T, typename SecondStrategy>
inline OptimQuickSort<T, SecondStrategy>::OptimQuickSort(int seqLen)
	:Optim<T, SecondStrategy>{ seqLen } {}
