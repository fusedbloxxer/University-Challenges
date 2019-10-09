#include <iostream>
#include <random>
#include <memory>
#include <iomanip>
#include <algorithm>
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "BinarySearch.h"
#include "SequentialSearch.h"

template<class Container, class SortStrategy>
void trySort(Container& container, std::default_random_engine rng) {
	// Shuffle the container if needed.
	std::shuffle(container.begin(), container.end(), rng);
	std::cout << "The container is: ";
	std::for_each(container.cbegin(), container.cend(),
		[](const auto& element) { std::cout << element << ' '; });
	std::cout << std::endl;

	// Sort the container.
	std::unique_ptr<Sort_I<Container>> strategy = std::make_unique<SortStrategy>();
	strategy->sort(container);

	// Print  the elements of the container.
	std::cout << "The sorted container is: ";
	std::for_each(container.cbegin(), container.cend(),
		[](const auto& element) { std::cout << element << ' '; });
	std::cout << std::endl << std::endl;
}

template<class Container, class Type, class FinderStrategy>
void tryFind(const Container& container, const Type element) {
	std::unique_ptr<Finder_I<Container, Type>> findStrategy = std::make_unique<FinderStrategy>();
	std::cout << findStrategy->find(container, element) << std::endl;
}

int main()
{
	// selection sort, bubble sort, insertion sort, cautare secventiala si cautare binara
	using ints = std::vector<int>;
	std::default_random_engine rng{};

	ints vec{ 9,6,3,4,5,1,2,3,6,4,4,5,6 };
	trySort<ints, SelectionSort<ints>>(vec, rng);
	trySort<ints, BubbleSort<ints>>(vec, rng);
	trySort<ints, InsertionSort<ints>>(vec, rng);

	ints arr{ 1, 2, 3, 4, 5, 6, 7 };
	tryFind<ints, int, BinarySearch<ints, int>>(arr, 5);
	tryFind<ints, int, SequentialSearch<ints, int>>(arr, 5);

	using std::string;
	using str = std::vector<string>;
	str strs{ "cumparaturi", "am", "facut", "astazi", "nu" };
	tryFind<str, string, SequentialSearch<str, string>>(strs, "cumparaturi");

	trySort<str, SelectionSort<str>>(strs, rng);
	trySort<str, BubbleSort<str>>(strs, rng);
	trySort<str, InsertionSort<str>>(strs, rng);
	tryFind<str, string, BinarySearch<str, string>>(strs, "cumparaturi");
}