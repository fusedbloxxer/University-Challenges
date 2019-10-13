#include "Vector.h"

Vector::~Vector()
{
	if (container) {
		delete[] container;
	}
}

Vector::Vector()
	:sz{ 0 }, memory{ 0 }, container{ nullptr }
{
}

Vector::Vector(const Vector& copy)
	: sz{ 0 }, memory{ copy.memory }, container{ (copy.memory) ? new BigInteger[copy.memory] : nullptr }
{
	while (memory && sz < copy.sz) {
		container[sz] = copy.container[sz];
		++sz;
	}
}

Vector::Vector(Vector&& move) noexcept
	:sz{ move.sz }, memory{ move.memory }, container{ move.container }
{
	move.container = nullptr;
}

Vector::Vector(std::initializer_list<BigInteger> init)
	: sz{ 0 }, memory{ init.size() }, container{ new BigInteger[init.size()] }
{
	for (const auto& elem : init) {
		container[sz] = elem;
		++sz;
	}
}

Vector& Vector::operator=(const Vector& copy)
{
	if (this == &copy) {
		return *this;
	}

	if (container) {
		sz = 0;
		delete[] container;
	}

	memory = copy.memory;
	container = new BigInteger[memory];
	while (sz < copy.sz) {
		container[sz] = copy.container[sz];
		++sz;
	}

	return *this;
}

Vector& Vector::operator=(Vector&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	if (container) {
		delete[] container;
	}

	sz = move.sz;
	memory = move.memory;
	container = move.container;
	move.container = nullptr;

	return *this;
}

Vector& Vector::operator+=(const Vector& vector)
{
	if (sz < vector.sz) {
		for (size_t i{ 0 }; i < sz; ++i) {
			container[i] += vector.container[i];
		}

		for (size_t i{ sz }; i < vector.sz; ++i) {
			push_back(vector.container[i]);
		}
	}
	else {
		for (size_t i{ 0 }; i < vector.sz; ++i) {
			container[i] += vector.container[i];
		}
	}

	return *this;
}

Vector& Vector::operator-=(const Vector& vector)
{
	if (sz < vector.sz) {
		for (size_t i{ 0 }; i < sz; ++i) {
			container[i] -= vector.container[i];
		}

		for (size_t i{ sz }; i < vector.sz; ++i) {
			push_back(BigInteger{ 0 } - vector.container[i]);
		}
	}
	else {
		for (size_t i{ 0 }; i < vector.sz; ++i) {
			container[i] -= vector.container[i];
		}
	}

	return *this;
}

Vector Vector::operator+(const Vector& vector) const
{
	return Vector{ *this } += vector;
}

Vector Vector::operator-(const Vector& vector) const
{
	return Vector{ *this } -= vector;
}

bool Vector::operator==(const Vector& vector) const
{
	if (this == &vector) {
		return true;
	}
	else if (sz == vector.sz) {
		for (size_t i{ 0 }; i < sz; ++i) {
			if (container[i] != vector.container[i]) {
				return false;
			}
		}
		return true;
	}

	return false;
}

bool Vector::operator!=(const Vector& vector) const
{
	return !(*this == vector);
}

BigInteger Vector::operator*(const Vector& vector) const
{
	if (sz == vector.sz) {
		BigInteger sum{ 0 };
		for (size_t i{ 0 }; i < sz; ++i) {
			sum += container[i] * vector.container[i];
		}
		return sum;
	}

	throw std::exception{ "Invalid operation for containers of different sizes." };
}

void Vector::insert(size_t index, const BigInteger& num)
{
	if (index > sz) {
		std::cout << "bounds";
		throw std::exception{ "Index out of array bounds." };
	}

	if (!container) {
		container = new BigInteger[++memory];
		container[0] = num;
	}
	else if (sz == memory) {
		auto temp = new BigInteger[memory *= 2];

		// Move elements before the index.
		for (size_t i{ 0 }; i < index; ++i) {
			temp[i].isNegative = container[i].isNegative;
			temp[i].list = container[i].list;
			container[i].list = nullptr;
		}

		// Insert the new element.
		temp[index] = num;

		// Move elements after the index.
		for (size_t i{ index + 1 }; i <= sz; ++i) {
			temp[i].isNegative = container[i - 1].isNegative;
			temp[i].list = container[i - 1].list;
			container[i - 1].list = nullptr;
		}

		// Clean old memory
		delete[] container;

		// Move in the new memory.
		container = temp;
	}
	else {
		// Simple insertion by using move semantics, NOT copying.
		for (size_t i{ sz }; i > index; --i) {
			container[i].isNegative = container[i - 1].isNegative;
			container[i].list = container[i - 1].list;
		}

		// Override current dublicate pointer then copy.
		container[index].list = new LinkedList<BigInteger::T>;
		container[index] = num;
		
	}
	++sz;
}

void Vector::push_front(const BigInteger& num)
{
	insert(0, num);
}

void Vector::push_back(const BigInteger& num)
{
	insert(sz, num);
}

BigInteger Vector::maxAbs() const
{
	if (container && sz > 0) {
		BigInteger maxValue = container[0];
		for (size_t i{ 1 }; i < sz; ++i) {
			maxValue = BigInteger::maxAbs(maxValue, container[i]);
		}
		return maxValue;
	}
	return BigInteger{0};
}

void Vector::remove(size_t index)
{
	if (index >= sz) {
		std::cout << "bounds";
		throw std::exception{ "Index out of vector bounds." };
	}

	if (sz == 1) {
		memory = --sz;
		delete[] container;
		container = nullptr;
	}
	else {
		// New smaller memeory size.
		auto temp = new BigInteger[memory - 1];

		// Move elements by stealing their pointer.
		for (size_t i{ 0 }; i < index; ++i) {
			temp[i].isNegative = container[i].isNegative;
			temp[i].list = container[i].list;
			container[i].list = nullptr;
		}

		// Move elements after the index like before.
		for (size_t i{ index }; i < sz - 1; ++i) {
			temp[i].isNegative = container[i + 1].isNegative;
			temp[i].list = container[i + 1].list;
			container[i + 1].list = nullptr;
		}

		// Delete unused data.
		delete[] container;

		// Store the pointer to the new memory location.
		container = temp;
		--memory;
		--sz;
	}
}

void Vector::remove_front()
{
	remove(0);
}

void Vector::remove_back()
{
	remove(sz - 1);
}

size_t Vector::realSize() const
{
	return memory;
}

bool Vector::isEmpty() const
{
	return sz == 0;
}

size_t Vector::size() const
{
	return sz;
}

void Vector::print(std::ostream& os) const
{
	if (container) {
		for (size_t i{ 0 }; i < sz; ++i) {
			os << container[i] << ' ';
		}
	}
}

void Vector::read(std::istream& is)
{
	if (container) {
		delete[] container;
	}

	std::cout << "Enter number of elements: ";
	is >> sz; memory = sz; container = new BigInteger[sz];
	for (size_t i{ 0 }; i < sz; ++i) {
		is >> container[i];
	}
}
