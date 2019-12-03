#pragma once
#include "SortStrategy.h"

template<typename T = int>
class DivideStrategy : public virtual SortStrategy<T>
{
public:
	virtual void sort(T* elements, int length) const override
	{
		divide(elements, 0, length - 1);
	}
	virtual ~DivideStrategy() = default;
protected:
	virtual void divide(T* elements, int left, int right) const = 0;
};