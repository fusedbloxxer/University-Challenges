#pragma once
#include "InsertionSort.h"
#include "MergeSort.h"
#include "Optim.h"
#include <iostream>
#include <typeinfo>

template<typename T, typename SecondStrategy = InsertionSort<T>>
class OptimMergeSort final : public MergeSort<T>, public Optim<T, SecondStrategy>
{
public:
	OptimMergeSort(int seqLen = 9);
	virtual ~OptimMergeSort() = default;

protected:
	virtual void divide(T* elements, int left, int right) const override;
};

template<typename T, typename SecondStrategy>
inline OptimMergeSort<T, SecondStrategy>::OptimMergeSort(int seqLen)
	:Optim<T, SecondStrategy>{ seqLen } {}

template<typename T, typename SecondStrategy>
inline void OptimMergeSort<T, SecondStrategy>::divide(T* elements, int left, int right) const
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
		int middle = left + (right - left) / 2;
		divide(elements, left, middle);
		divide(elements, middle + 1, right);

		Logger::d("BEFORE OptimMergeSort: ");
		print(elements + left, right - left + 1, false);

		MergeSort<T>::merge(elements, left, middle, right);

		Logger::d("AFTER OptimMergeSort: ");
		print(elements + left, right - left + 1, false);
	}
}