#pragma once
#include "DivideStrategy.h"

template<typename T = int>
class MergeSort : public DivideStrategy<T>
{
public:
	virtual ~MergeSort() = default;

protected:
	void merge(T* elements, int left, int middle, int right) const;
	virtual void divide(T* elements, int left, int right) const override;
};

template<typename T>
inline void MergeSort<T>::divide(T* elements, int left, int right) const
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		divide(elements, left, middle);
		divide(elements, middle + 1, right);
		merge(elements, left, middle, right);
	}
}

template<typename T>
inline void MergeSort<T>::merge(T* elements, int left, int middle, int right) const
{
	int leftSize = middle - left + 1;
	int rightSize = right - middle;

	T* leftArr = new T[leftSize];
	T* rightArr = new T[rightSize];

	for (int i = 0; i < leftSize; ++i)
	{
		leftArr[i] = elements[i + left];
	}

	for (int i = 0; i < rightSize; ++i)
	{
		rightArr[i] = elements[i + middle + 1];
	}

	int k = left, i = 0, j = 0;

	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i] < rightArr[j])
		{
			elements[k++] = leftArr[i++];
		}
		else
		{
			elements[k++] = rightArr[j++];
		}
	}

	while (i < leftSize)
	{
		elements[k++] = leftArr[i++];
	}

	while (j < rightSize)
	{
		elements[k++] = rightArr[j++];
	}

	delete[] leftArr;
	delete[] rightArr;
}
