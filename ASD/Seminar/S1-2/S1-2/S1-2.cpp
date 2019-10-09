#include <iostream>
#include "List.h"
#include "SimpleList.h"
#include "TreeMap.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

namespace UMethod {
	using std::vector;

	template<class T>
	long long binSearch(const vector<T>& v, const T& e, size_t start, size_t end) {
		if (start < end) {
			size_t m = start + (end - start) / 2;
			if (v[m] == e) {
				return m;
			}
			else if (v[m] > e) {
				return binSearch(v, e, start, m - 1);
			}
			else {
				return binSearch(v, e, m + 1, end);
			}
		}
		else 
		{
			return -1;
		}
	}

	template<class T>
	long long linSearch(const vector<T>& v, const T& e, size_t start, size_t end) {
		for (size_t i{ start }; i < end; ++i) {
			if (v[i] == e) {
				return i;
			}
		}
		return -1;
	}
}

template<class Container, class SortType>
void sort(Container& container) {
	std::unique_ptr<Sort_I<Container>> strategy = std::make_unique<SortType>();
	strategy->sort(container);
}

template<class Container>
void print(const Container& container) {
	for (const auto& element : container) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}

template<class Container, class SortType>
void test(Container& container, std::default_random_engine& rng) {
	// Shuffle elements.
	std::shuffle(container.begin(), container.end(), rng);

	// Print elements.
	std::cout << "The shuffled container is: ";
	print(container);

	// Sort elements.
	std::cout << "The sorted container is: ";
	sort<Container, SortType>(container);
	print(container);

	// Print new line.
	std::cout << std::endl;
}

int main()
{
	using std::vector;
	std::default_random_engine rng{};
	vector<int> vec{ 0, 5,4,3,2,1,1,2,3,4,5,9,8,8,8,8,7 };

	test<vector<int>, BubbleSort<vector<int>>>(vec, rng);
	test<vector<int>, InsertionSort<vector<int>>>(vec, rng);
	test<vector<int>, SelectionSort<vector<int>>>(vec, rng);
	test<vector<int>, MergeSort<vector<int>>>(vec, rng);
	test<vector<int>, QuickSort<vector<int>>>(vec, rng);

	std::cout << UMethod::linSearch(vec, 9, 0, vec.size());
	std::cout << UMethod::binSearch(vec, 9, 0, vec.size());
}