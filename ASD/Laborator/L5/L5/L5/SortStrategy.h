#pragma once
#include "Logger.h"

template<typename T>
void print(T* elements, int length, bool show = true)
{
	for (int i = 0; i < length; ++i)
	{
		if (show)
		{
			Logger::v(elements[i]);
			Logger::v(' ');
		}
		else
		{
			Logger::d(elements[i]);
			Logger::d(' ');
		}
	}

	if (show)
	{
		Logger::v('\n');
	}
	else
	{
		Logger::d('\n');
	}
}

template<typename T = int>
class SortStrategy
{
public:
	virtual void sort(T* elements, int length) const = 0;
	virtual ~SortStrategy() = default;
};