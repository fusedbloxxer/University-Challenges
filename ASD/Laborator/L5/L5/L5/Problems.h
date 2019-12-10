#pragma once
#include "OptimMergeSort.h"
#include "OptimQuickSort.h"
#include "HeapSort.h"
#include <typeinfo>
#include "AVL.h"

void problemOne()
{
	AVL<int> numbers;
	numbers.add(50);
	numbers.add(40);
	numbers.add(30);
	numbers.add(35);
	numbers.add(37);
	numbers.add(39);
	numbers.add(45);
	numbers.add(55);
	numbers.add(42);

	numbers.rsd();
	std::cout << std::endl;
	numbers.srd();
}

void testStrategy(int* elements, int length, SortStrategy<int>* strategy)
{
	int copy[] = { 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1, 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1 };

	for (int i = 0; i < length; ++i)
	{
		elements[i] = copy[i];
	}

	strategy->sort(elements, length);
	print(elements, length);
	delete strategy;
}

void sortingMethods()
{
	constexpr int length = 28, length2 = 7;
	int elements[] = { 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1, 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1 };
	int elements2[] = { 5, 6, 9, 11, 3, 12, -2 };

	// Logger::setMode(0);
	// Logger::setMode(8);
	// Logger::setMode(12);
	Logger::e("HeapSort:\n"); testStrategy(elements2, length2, new HeapSort<int>);
	Logger::e("MergeSort:\n"); testStrategy(elements2, length2, new MergeSort<int>);
	Logger::e("QuickSort:\n"); testStrategy(elements2, length2, new QuickSort<int>);
	Logger::e("OptimMergeSort:\n"); testStrategy(elements, length, new OptimMergeSort<int, InsertionSort<int>>);
	Logger::e("OptimQuickSort:\n"); testStrategy(elements2, length2, new OptimQuickSort<int>);
}

void problemFive()
{
	AVL<std::string> words;
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::string word;
		std::cin >> word;
		words.add(word);
	}

	std::cout << '\n';
	words.drs();
}

template<typename T>
bool mountain(T* elements, int length);

template<typename T>
bool valley(T* elements, int length);

template<typename T>
void bitonic(T* elements, int length)
{
	// Works for mountain: . . . / \ . . .
	if (!mountain(elements, length))
	{
		print(elements, length);

		// Works for valley: . . . \ / . . .
		if (!valley(elements, length))
		{
			throw std::runtime_error{ "Vector is not bitonic !" };
		}
	}
}

void problemSeven()
{
	int v1[] = { 1, 1, 1, 1, 1, 1, 1, 5, 7, 12, 12, 12, 12, 6, 6, 4, 2, 2, 0, -1, -1, -10, -12 };
	int v2[] = { 2, 2, 2, 1, 1, 0, 0, -1, -2, -3, -4, -5, -5, -5, -3, -2, 0, 0, 1, 1, 1, 2, 2 };
	int v3[] = { 1, 2, 3, 4 };
	int v4[] = { 4, 3, 2, 1 };
	int v5[] = { 5, 5, 5, 5 };
	int v6[] = { 1, 2, -3, -4 };

	bitonic(v1, sizeof(v1) / sizeof(v1[0]));
	print(v1, sizeof(v1) / sizeof(v1[0]));

	bitonic(v2, sizeof(v2) / sizeof(v2[0]));
	print(v2, sizeof(v2) / sizeof(v2[0]));

	bitonic(v3, sizeof(v3) / sizeof(v3[0]));
	print(v3, sizeof(v3) / sizeof(v3[0]));

	bitonic(v4, sizeof(v4) / sizeof(v4[0]));
	print(v4, sizeof(v4) / sizeof(v4[0]));

	bitonic(v5, sizeof(v5) / sizeof(v5[0]));
	print(v5, sizeof(v5) / sizeof(v5[0]));

	bitonic(v6, sizeof(v6) / sizeof(v6[0]));
	print(v6, sizeof(v6) / sizeof(v6[0]));
}

template<typename T>
bool valley(T* elements, int length)
{
	T* temporary = new T[length];
	int k = length - 1, i = 0, j = length - 1;

	while (i <= j)
	{
		if (elements[j] < elements[i])
		{
			temporary[k--] = elements[i++];
		}
		else
		{
			temporary[k--] = elements[j--];
		}

		if (k < length - 2 && temporary[k + 1] > temporary[k + 2])
		{
			print(temporary + k + 1, length - k - 1);
			delete[] temporary;
			return false;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		elements[i] = temporary[i];
	}

	delete[] temporary;
	return true;
}

template<typename T>
bool mountain(T* elements, int length)
{
	T* temporary = new T[length];
	int k = 0, i = 0, j = length - 1;

	while (i <= j)
	{
		if (elements[i] < elements[j])
		{
			temporary[k++] = elements[i++];
		}
		else
		{
			temporary[k++] = elements[j--];
		}

		if (k > 1 && temporary[k - 2] > temporary[k - 1])
		{
			std::cout << "TEMPORARY: ";
			print(temporary, length);
			delete[] temporary;
			return false;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		elements[i] = temporary[i];
	}

	delete[] temporary;
	return true;
}