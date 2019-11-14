#include <iostream>
#include <random>
#include <ctime>

class Container {
	int value;
public:
	Container(int def = 0) : value{ def } {}

	void setValue(int value) {
		this->value = value;
	}

	int getValue() const {
		return this->value;
	}
};

void print(const int* const arr, const int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int pivot(const Container* const container, int* const indexes, int start, int end) {
	int i = 1, j = 0;

	while (start < end)
	{
		if (container[indexes[start]].getValue() > container[indexes[end]].getValue())
		{
			int temp = indexes[start];
			indexes[start] = indexes[end];
			indexes[end] = temp;

			int aux = -i;
			i = -j;
			j = aux;
		}

		start += i;
		end += j;
	}

	return start;
}

void step(const Container* const container, int * const indexes, const int start, const int end) {
	if (start < end) {
		int pos = pivot(container, indexes, start, end);
		step(container, indexes, start, pos - 1);
		step(container, indexes, pos + 1, end);
	}
}

void sort(const Container* const container, int * const indexes, const int size) {
	step(container, indexes, 0, size - 1);
}

void methodShouldSort(const Container* const container, const int * const indexes, const int size) {
	for (int i = 0; i < size - 1; ++i) {

		if (container[indexes[i]].getValue() > container[indexes[i + 1]].getValue()) {
			std::cout << "Elements are not sorted: " << container[indexes[i]].getValue() << ", " << container[indexes[i + 1]].getValue() << std::endl;
			abort();
		}

		std::cout << container[indexes[i]].getValue() << ' ';
	}

	std::cout << container[indexes[size - 1]].getValue() << std::endl;
}

int main()
{
	srand(time(NULL));
	const int size = 1 + rand() % 100;
	Container* arr = new Container[size];
	int* const indexes = new int[size];

	std::cout << "Elemente initiale: ";

	for (int i = 0; i < size; ++i) {
		arr[i].setValue(1 + rand() % size);
		std::cout << arr[i].getValue() << ' ';
		indexes[i] = i;
	}


	std::cout << std::endl << "Sortarea indicilor: ";
	sort(arr, indexes, size);
	methodShouldSort(arr, indexes, size);

	delete[] indexes;
	delete[] arr;
}