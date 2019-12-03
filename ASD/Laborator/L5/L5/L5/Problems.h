#pragma once
#include "OptimMergeSort.h"
#include "OptimQuickSort.h"
#include <typeinfo>
#include "AVL.h"

void problemOne()
{
	AVL<std::string> words;
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::string word; std::cin >> word;
		words.add(word);
	}

	std::cout << '\n';
	words.rsd(); std::cout << '\n';
	words.srd();
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
	constexpr int length = 28;
	int elements[] = { 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1, 5, 6, 9, 11, 3, 12, -2, -2, 4, 3, 2, -2, 1, 1 };

	// Logger::setMode(0);
	// Logger::setMode(8);
	// Logger::setMode(12);
	Logger::e("MergeSort:\n"); testStrategy(elements, length, new MergeSort<int>);
	Logger::e("QuickSort:\n"); testStrategy(elements, length, new QuickSort<int>);
	Logger::e("InsertionSort:\n"); testStrategy(elements, length, new InsertionSort<int>);
	Logger::e("OptimMergeSort:\n"); testStrategy(elements, length, new OptimMergeSort<int>);
	Logger::e("OptimQuickSort:\n"); testStrategy(elements, length, new OptimQuickSort<int>);
}

void problemThree()
{
	AVL<std::string> words;
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::string word; std::cin >> word;
		words.add(word);
	}

	std::cout << '\n';
	words.drs(); std::cout << '\n' << words;
}