#include "Tester.h"
#include <iostream>

class TestUtil::BigInt {
	int id;
	friend std::ostream& operator<<(std::ostream& os, const BigInt& obj);
	friend std::istream& operator>>(std::istream& is, BigInt& obj);
public:
	BigInt(int id = 0)
		:id{ id }
	{
		std::cout << "Constructor was called for " << id << std::endl;
	}

	BigInt(const BigInt& copy)
		:id{ copy.id }
	{
		std::cout << "Copy constructor was called." << std::endl;
	}

	BigInt(BigInt&& move) noexcept
		:id{ move.id }
	{
		std::cout << "Move constructor was called." << std::endl;
	}

	BigInt& operator=(const BigInt& copy) {
		std::cout << "Copy assignmentd was called." << std::endl;
		if (this == &copy) {
			return *this;
		}
		id = copy.id;
		return *this;
	}

	BigInt& operator=(BigInt&& move) noexcept {
		std::cout << "Move assignmentd was called." << std::endl;
		if (this == &move) {
			return *this;
		}
		id = move.id;
		return *this;
	}

	bool operator==(const BigInt& obj) {
		return id == obj.id;
	}

	~BigInt() {
		std::cout << "Destructor was called for " << id << std::endl;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}
};

std::ostream& TestUtil::operator<<(std::ostream& os, const TestUtil::BigInt& obj) {
	os << obj.getId();
	return os;
}

std::istream& TestUtil::operator>>(std::istream& is, TestUtil::BigInt& obj) {
	int id;
	is >> id;
	obj.setId(id);
	return is;
}

void TestUtil::testLinkedList() {
	auto list = std::make_unique<LinkedList<BigInt>>();

	list->push_back(1);
	std::cout << std::endl;
	list->push_back(2);
	list->push_front(1);
	std::cout << std::endl;
	list->push_front(2);

	list->clear();

	list->push_front(1);
	std::cout << std::endl;
	list->push_front(2);
	list->push_front(1);
	std::cout << std::endl;
	list->push_front(2);

	list->push_back(1); // 4 3 2 1 1
	std::cout << std::endl;
	list->push_back(2); // 4 3 2 1 1 2
	std::cout << std::endl;
	list->push_back(3); // 4 3 2 1 1 2 3
	std::cout << std::endl;
	list->push_back(4); // 4 3 2 1 1 2 3 4
	std::cout << std::endl;

	list->push_front(1); // 1
	std::cout << std::endl;
	list->push_front(2); // 2 1
	std::cout << std::endl;
	list->push_front(3); // 3 2 1
	std::cout << std::endl;
	list->push_front(4); // 4 3 2 1
	std::cout << std::endl;

	list->remove(list->size() - 1);
	list->remove(1);
	list->remove(2);
	list->remove(3);
	list->remove(1);
	list->remove(0);
	list->remove(0);
	list->remove(list->size() - 1);

	std::cout << "\nContains 2: " << std::boolalpha << list->contains(2) << '\n';
	std::cout << "\nContains 3: " << list->contains(3) << '\n';
	std::cout << "\nContains 1: " << list->contains(1) << '\n';
	std::cout << "\nContains 4: " << list->contains(4) << '\n';
	std::cout << "\nIS EMPTY: " << list->isEmpty() << '\n';

	list->add(0, 1); // 1 4 3 2 1 1 2 3 4 
	list->add(1, 2); // 1 2 4 3 2 1 1 2 3 4
	list->add(1, 3); // 1 3 2 4 3 2 1 1 2 3 4
	list->add(1, 4); // 1 4 3 2 4 3 2 1 1 2 3 4
	list->add(3, 5); // 1 4 3 5 2 4 3 2 1 1 2 3 4
	list->add(4, 6); // 1 4 3 5 6 2 4 3 2 1 1 2 3 4

	list->push_front(1); // 1 1 4 3 5 6 2 4 3 2 1 1 2 3 4
	list->push_back(8);  // 1 1 4 3 5 6 2 4 3 2 1 1 2 3 4 8
	list->push_back(9);  // 1 1 4 3 5 6 2 4 3 2 1 1 2 3 4 8 9
	list->push_back(10); // 1 1 4 3 5 6 2 4 3 2 1 1 2 3 4 8 9 10

	std::cout << "\nINDEX IS: " << list->indexOf(8) << '\n';
	std::cout << "\nINDEX IS: " << list->indexOf(9) << '\n';
	std::cout << "\nINDEX IS: " << list->indexOf(1) << '\n';
	std::cout << "\nINDEX IS: " << list->indexOf(10) << '\n';

	std::cout << "Basic O(n^2) print :))" << std::endl;
	for (size_t i{ 0 }; i < list->size(); ++i) {
		std::cout << (*list)[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << *list << std::endl;
	std::cout << std::endl << list->size() << std::endl;
	clr();

	{
		// Test Copy - Constructor
		auto copyList = *list;

		copyList.remove_front();
		copyList.remove_front();
		copyList.remove_front();
		list->remove_back();
		list->remove_back();
		list->remove_back();

		std::cout << "COPY: " << copyList << std::endl;
		std::cout << "REAL: " << *list << std::endl;
	}
	clr();

	{
		// Test Initializer List
		LinkedList<BigInt> copyList = { 1,2,3,4,5 };
		std::cout << copyList;
	}
	clr();

	{
		LinkedList<BigInt> copyList;
		copyList = LinkedList<BigInt>{ 1,2,3,4,5 };
		std::cout << copyList;
	}
	clr();

	{
		LinkedList<BigInt> copyList;
		copyList = *list;
		copyList.clear();
		std::cout << copyList;
		std::cout << *list;
	}
	clr();
}

void TestUtil::clr() {
	for (int i = 0; i < 30; ++i) {
		std::cout << '\n';
	}
}