#pragma once
#include "SortStrategy.h"
#include "Heap.h"

template<typename T>
class HeapSort : public SortStrategy<T>
{
public:
	virtual void sort(T* elements, int length) const override;
};

template<typename T>
inline void HeapSort<T>::sort(T* elements, int length) const
{
	Heap<T> heap;
	
	for (int i = 0; i < length; ++i)
	{
		heap.push(elements[i]);
	}

	for (int i = 0; !heap.empty(); ++i)
	{
		elements[i] = heap.pop();
	}
}