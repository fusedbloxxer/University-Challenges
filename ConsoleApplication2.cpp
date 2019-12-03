// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
void print(T* elements, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << elements[i] << ' ';
	}
	std::cout << std::endl;
}

template<typename T = int>
class SortStrategy
{
public:
	virtual void sort(T* elements, int length) const = 0;
	virtual ~SortStrategy() = default;
};

template<typename T = int>
class DivideStrategy : public SortStrategy<T>
{
public:
	virtual void sort(T* elements, int length) const override
	{
		sort(elements, 0, length - 1);
	}

protected:
	virtual void sort(T* elements, int left, int right) const = 0;
};

template<typename T = int>
class MergeSort : public DivideStrategy<T>
{
protected:
	virtual void sort(T* elements, int left, int right) const override
	{
		if (left < right)
		{
			int middle = left + (right - left) / 2;
			sort(elements, left, middle);
			sort(elements, middle + 1, right);
			merge(elements, left, middle, right);
		}
	}
private:
	void merge(T* elements, int left, int middle, int right) const
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
};

int main()
{
	std::string words[] = { "andrei", "a", "cules", "mai", "multe", "a", "cules", "mu", "mere", "astazi", "delicios" };
	int v[] = { 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1 };

	SortStrategy<int>* strategy = new MergeSort<int>;
	strategy->sort(v, 14);
	print(v, 14);
	delete strategy;
}