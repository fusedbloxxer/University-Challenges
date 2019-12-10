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
	T* aux = new T[right - left + 1];

	int k = 0, i = left, j = middle + 1;

	while (i <= middle && j <= right)
	{
		if (elements[i] < elements[j])
		{
			aux[k++] = elements[i++];
		}
		else
		{
			aux[k++] = elements[j++];
		}
	}

	while (i <= middle)
	{
		aux[k++] = elements[i++];
	}

	while (j <= right)
	{
		aux[k++] = elements[j++];
	}


	for (auto i = left; i <= right; ++i)
	{
		elements[i] = aux[i - left];
	}

	delete[] aux;
}
