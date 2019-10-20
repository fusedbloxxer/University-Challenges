#include "BigNumber.h"
#include <cctype>
#include <regex>

BigNumber::BigNumber()
	:isNegative{ false }, list{ new SimpleList<int> }
{
}

BigNumber::BigNumber(long long num)
	: isNegative{ num < 0 }, list{ new SimpleList<int> }
{
	if (num < 0) {
		num *= -1;
	}

	while (num) {
		list->addLast(num % 10);
		num /= 10;
	}
}

BigNumber::BigNumber(const BigNumber& copy)
	: isNegative{ copy.isNegative }, list{ new SimpleList<int> }
{
	*list = *copy.list;
}

BigNumber::BigNumber(BigNumber&& move) noexcept
	:isNegative{ move.isNegative }, list{ move.list }
{
	move.list = nullptr;
}

BigNumber& BigNumber::operator=(const BigNumber& copy)
{
	if (this == &copy) {
		return *this;
	}

	if (list) {
		delete list;
	}

	isNegative = copy.isNegative;
	list = new SimpleList<int>;
	*list = *copy.list;

	return *this;
}

BigNumber& BigNumber::operator=(BigNumber&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	if (list) {
		delete list;
	}

	isNegative = move.isNegative;
	list = move.list;
	move.list = nullptr;

	return *this;
}

BigNumber& BigNumber::operator+=(const BigNumber& num)
{
	/*
		+A + +B
		+A + -B
		-A + +B
		-A + -B
	*/
	if (isNegative == num.isNegative) {
		// Cases:
		// 1. A > B 2. A = B 3. A < B
		addition(list, num.list);
	}
	else {
		// subtraction, change sign.
		if (list->size() < num.list->size()) {
			isNegative = num.isNegative;
		}
		else if (list->size() == num.list->size()) {
			int a, b; bool comp{ false };
			for (long long i{ long long(list->size()) - 1}; i >= 0; --i) {
				a = list->findByPos(i);
				b = num.list->findByPos(i);
				if (a < b) {
					isNegative = num.isNegative;
					comp = true;
					break;
				}
				else if(a > b) {
					comp = true;
					break;
				}
			}
			if (!comp) {
				isNegative = false;
			}
		}
		subtraction(list, num.list);
	}

	return *this;
}

BigNumber BigNumber::operator+(const BigNumber& num)
{
	return BigNumber{ *this } += num;
}

bool BigNumber::isZero() const
{
	return !list || !list->begin() || list->end()->getValue() == 0;
}

void BigNumber::read(std::istream& is)
{
	std::cout << "Enter number: ";
	std::string buffer; is >> buffer;
	if (buffer[0] == '0') {
		list->addFirst(0);
	}
	else {
		if (std::regex_match(buffer, std::regex{ "[+-]?[[:digit:]]+" })) {
			isNegative = buffer[0] == '-';
			for (const auto& e : buffer) {
				if (isdigit(e)) {
					list->addFirst(e - '0');
				}
			}
		}
	}
}

void BigNumber::print(std::ostream& os) const
{
	if (!isZero() && isNegative) {
		std::cout << '-';
	}

	if (list) {
		//for (auto var = list->begin(); var; var = var->getNext()) {
		//	std::cout << '|' << var->getValue() << '|';
		//}
		rec(list->begin());
	}
	os << std::endl;
}

void BigNumber::subtraction(List<int>* list, List<int>* num)
{
	/*
		10's Complement
		Addition
		Check if size was modified
			1. Yes, remove carry.
			2. No, 10's complement.
	*/
	size_t initial = list->size();
	complementOfTen(list, std::max(list->size(), num->size()));
	addition(list, num);

	if (initial != list->size()) {
		list->removeByPos(list->size() - 1);
	}
	else {
		complementOfTen(list, list->size());
	}

	while (list && list->end() && list->end()->getValue() == 0) {
		list->removeByPos(list->size() - 1);
	}
}

void BigNumber::addition(List<int>* list, List<int>* num)
{
	if (list->size() >= num->size()) {
		int remainder{ 0 }, temp{ 0 };
		auto var1 = list->begin();
		auto var2 = num->begin();

		while (var2) {
			temp = var1->getValue() + var2->getValue() + remainder;
			var1->setValue(temp % 10);
			remainder = temp / 10;

			var1 = var1->getNext();
			var2 = var2->getNext();
		}

		while (var1 && remainder) {
			temp = var1->getValue() + remainder;
			var1->setValue(temp % 10);
			remainder = temp / 10;
			var1 = var1->getNext();
		}

		if (remainder) {
			list->addLast(remainder);
		}
	}
	else {
		int remainder{ 0 }, temp{ 0 };
		auto var1 = list->begin();
		auto var2 = num->begin();

		while (var1) {
			temp = var1->getValue() + var2->getValue() + remainder;
			var1->setValue(temp % 10);
			remainder = temp / 10;

			var1 = var1->getNext();
			var2 = var2->getNext();
		}

		while (var2) {
			temp = var2->getValue() + remainder;
			list->addLast(temp % 10);
			remainder = temp / 10;

			var2 = var2->getNext();
		}

		if (remainder) {
			list->addLast(remainder);
		}
	}
}

void BigNumber::complementOfNine(List<int>* list, size_t sz)
{
	for (auto var = list->begin(); var; var = var->getNext()) {
		var->setValue(9 - var->getValue());
	}

	if (list->size() < sz) {
		list->addLast(9);
	}
}

void BigNumber::complementOfTen(List<int>* list, size_t sz)
{
	complementOfNine(list, sz);
	List<int>* temp = new SimpleList<int>{ 1 };

	addition(list, temp);

	delete temp;
}

void BigNumber::rec(SimpleNode<int>* var) const {
	if (var) {
		if (var->getNext()) {
			rec(var->getNext());
		}
		std::cout << var->getValue();
	}
}

BigNumber::~BigNumber()
{
	delete list;
}

