#include "BigInteger.h"

BigInteger::BigInteger()
	:list{ new LinkedList<T> }, isNegative{ false }
{
}

BigInteger::BigInteger(long long longNumber)
	: isNegative{ longNumber < 0 }, list{ new LinkedList<T> }
{
	longNumber = (isNegative) ? -longNumber : longNumber;
	do {
		list->push_front(longNumber % 10);
		longNumber /= 10;
	} while (longNumber);
}

BigInteger::BigInteger(const BigInteger& copy)
	: isNegative{ copy.isNegative }, list{ new LinkedList<T> }
{
	// std::cout << "Copy Constructor was called." << std::endl;
	*list = *copy.list;
}

BigInteger::BigInteger(BigInteger&& move) noexcept
	:isNegative{ move.isNegative }, list{ move.list }
{
	move.list = nullptr;
}

BigInteger& BigInteger::operator=(const BigInteger& copy)
{
	if (this == &copy) {
		return *this;
	}

	*list = *copy.list;
	isNegative = copy.isNegative;
	return *this;
}

BigInteger& BigInteger::operator=(BigInteger&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	list->clear();
	list = move.list;
	move.list = nullptr;
	isNegative = move.isNegative;
	return *this;
}

BigInteger& BigInteger::operator+=(const BigInteger& big)
{
	if (isZero() || big.isZero()) {
		isNegative = (isZero()) ? big.isNegative : isNegative;
		addition(*list, *big.list);
		return *this;
	}
	else if (isNegative == big.isNegative) {
		addition(*list, *big.list);
	}
	else {
		int comp = list->compareTo(*big.list);
		subtraction(*list, *big.list);
		isNegative = (comp < 0 && big.isNegative) || (comp > 0 && isNegative);
	}

	return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& big)
{
	if (isZero() || big.isZero()) {
		if (isZero()) {
			if (big.isNegative) {
				isNegative = false;
			}
			else {
				isNegative = true;
			}
		}
		addition(*list, *big.list);
		return *this;
	}
	else if (isNegative != big.isNegative) {
		addition(*list, *big.list);
	}
	else {
		int comp = list->compareTo(*big.list);
		subtraction(*list, *big.list);
		isNegative = (!isNegative && comp < 0) || (isNegative && comp > 0);
	}

	return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& big)
{
	if (isZero() || big.isZero()) {
		isNegative = false;
		list->clear();
		return *this;
	}

	auto ptr = new LinkedList<T>, firstList = list, secondList = big.list;
	if (firstList->size() < secondList->size()) {
		std::swap(firstList, secondList);
	}
	size_t pos{ 0 }, cpos{ 0 };
	T remainder = 0, temp;

	for (auto nodeOne = firstList->end(); nodeOne; nodeOne = nodeOne->getPrev()) {
		auto node = ptr->end();
		for (cpos = 0; cpos < pos; ++cpos) {
			node = node->getPrev();
		}

		for (auto nodeTwo = secondList->end(); nodeTwo; nodeTwo = nodeTwo->getPrev()) {
			temp = nodeOne->getValue() * nodeTwo->getValue() + remainder;

			if (node) {
				temp += node->getValue();
			}

			if (ptr->size() <= cpos) {
				ptr->push_front(temp % 10);
			}
			else if (node) {
				node->setValue(temp % 10);
				node = node->getPrev();
			}

			remainder = temp / 10;
			++cpos;
		}

		while (remainder) {
			ptr->push_front(remainder % 10);
			remainder /= 10;
		}
		++pos;
	}

	this->list->clear();
	this->list = ptr;
	isNegative = !(isNegative == big.isNegative);
	return *this;
}

BigInteger BigInteger::operator-(const BigInteger& big)
{
	return BigInteger{ *this } -= big;
}

BigInteger BigInteger::operator*(const BigInteger& big)
{
	return BigInteger{ *this } *= big;
}

BigInteger BigInteger::maxAbs(const BigInteger& big)
{
	if (*list < *big.list) {
		return big;
	}
	else {
		return *this;
	}
}

LinkedList<BigInteger::T>& BigInteger::omitTheCarry(LinkedList<T>& firstList)
{
	bool removed = false;
	auto node = firstList.begin();

	if (node && node->getValue() == 1) {
		node = node->getNext();
		firstList.remove_front();
		removed = true;
	}

	while (node && node->getValue() == 0) {
		node = node->getNext();
		firstList.remove_front();
		removed = true;
	}

	return firstList;
}

LinkedList<BigInteger::T>& BigInteger::complementOfTen(LinkedList<T>& list, size_t digits)
{
	return addition(complementOfNine(list, digits), LinkedList<T>{1});
}

LinkedList<BigInteger::T>& BigInteger::complementOfNine(LinkedList<T>& list, size_t digits) {
	auto node = list.end();

	while (digits-- > 0) {
		if (node) {
			node->setValue(9 - node->getValue());
			node = node->getPrev();
		}
		else {
			list.push_front(9);
		}
	}
	return list;
}

LinkedList<BigInteger::T>& BigInteger::addition(LinkedList<T>& firstList, const LinkedList<T>& secondList)
{
	bool hasCarry = false;
	T remainder = 0, sum = 0;
	auto nodeOne = firstList.end();
	auto nodeTwo = secondList.end();

	if (firstList.size() == secondList.size()) {
		while (nodeOne) {
			sum = nodeOne->getValue() + nodeTwo->getValue() + remainder;
			nodeOne->setValue(sum % 10);
			remainder = sum / 10;

			nodeOne = nodeOne->getPrev();
			nodeTwo = nodeTwo->getPrev();
		}

		if (remainder) {
			hasCarry = true;
			firstList.push_front(remainder);
		}
	}
	else if (firstList.size() > secondList.size()) {
		while (nodeTwo) {
			sum = nodeOne->getValue() + nodeTwo->getValue() + remainder;
			nodeOne->setValue(sum % 10);
			remainder = sum / 10;

			nodeOne = nodeOne->getPrev();
			nodeTwo = nodeTwo->getPrev();
		}

		while (remainder && nodeOne) {
			sum = nodeOne->getValue() + remainder;
			nodeOne->setValue(sum % 10);
			remainder = sum / 10;

			nodeOne = nodeOne->getPrev();
		}

		if (remainder) {
			hasCarry = true;
			firstList.push_front(remainder);
		}
	}
	else {
		while (nodeOne) {
			sum = nodeOne->getValue() + nodeTwo->getValue() + remainder;
			nodeOne->setValue(sum % 10);
			remainder = sum / 10;

			nodeOne = nodeOne->getPrev();
			nodeTwo = nodeTwo->getPrev();
		}

		while (nodeTwo) {
			sum = nodeTwo->getValue() + remainder;
			firstList.push_front(sum % 10);
			remainder = sum / 10;

			nodeTwo = nodeTwo->getPrev();
		}

		if (remainder) {
			hasCarry = true;
			firstList.push_front(remainder);
		}
	}

	return firstList;
}

LinkedList<BigInteger::T>& BigInteger::subtraction(LinkedList<T>& firstList, const LinkedList<T>& secondList)
{
	/*
		0. Retine dimensiunea initiala a primului element. OK
		1. Complementul lui 10 pe primul element. OK
		2. Suma celor 2 elemente. OK
		3. Verificam daca dimensiumea primului element s-a modificat fata de dimensiunea initala.
			1. Daca da, atunci se va face remove carry.
			2. Daca nu, atunci se va aplica complementul lui 10.
	*/

	size_t size = firstList.size();
	addition(complementOfTen(firstList, std::max(firstList.size(), secondList.size())), secondList);

	if (firstList.size() != size) {
		// std::cout << "Omit the carry." << std::endl;
		omitTheCarry(firstList);
	}
	else {
		// std::cout << "Al doilea complement." << std::endl;
		complementOfTen(firstList, firstList.size());

		auto node = firstList.begin();
		while (node && node->getValue() == 0) {
			node = node->getNext();
			firstList.remove_front();
		}
	}

	return firstList;
}

BigInteger BigInteger::operator+(const BigInteger& big)
{
	return BigInteger{ *this } += big;
}

bool BigInteger::operator==(const BigInteger& big) const
{
	return (isNegative == big.isNegative && *list == *big.list) || (isZero() && big.isZero());
}

bool BigInteger::operator!=(const BigInteger& big) const
{
	return !(*this == big);
}

bool BigInteger::isZero() const
{
	return list->isEmpty() || list->begin()->getValue() == 0;
}

void BigInteger::print(std::ostream& os) const
{
	if (list->isEmpty()) {
		os << '0';
		return;
	}

	if (isNegative) {
		os << '-';
	}

	for (auto node = list->begin(); node; node = node->getNext()) {
		os << node->getValue();
	}
}

void BigInteger::read(std::istream& is)
{
	list->clear();
	std::string buffer; is >> buffer;
	std::regex pattern{ "^[-+\\s]?[1-9][[:digit:]]{0,}$" };

	if (std::regex_match(buffer, pattern) || std::regex_match(buffer, std::regex{ "^[-+\\s]?0$" })) {
		isNegative = buffer[0] == '-';
		for (const auto& e : buffer) {
			if (isdigit(e)) {
				list->push_back(e - '0');
			}
		}
	}
	else {
		throw std::exception{ "Invalid input was detected" };
	}
}

BigInteger::~BigInteger()
{
	delete list;
}

BigInteger BigInteger::maxAbs(const BigInteger& numberOne, const BigInteger& numberTwo)
{
	BigInteger result = (numberOne.list->compareTo(*numberTwo.list) > 0) ? numberOne : numberTwo;

	result.isNegative = false; // Absolute value:
	
	return result;
}
