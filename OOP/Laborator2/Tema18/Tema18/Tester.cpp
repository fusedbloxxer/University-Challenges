#include "Tester.h"
#include <iostream>
#include <assert.h>

class TestUtil::TesterClass {
	int id;
	friend std::ostream& operator<<(std::ostream& os, const TesterClass& obj);
	friend std::istream& operator>>(std::istream& is, TesterClass& obj);
public:
	TesterClass(int id = 0)
		:id{ id }
	{
		// std::cout << "Constructor was called for " << id << std::endl;
	}

	TesterClass(const TesterClass& copy)
		:id{ copy.id }
	{
		// std::cout << "Copy constructor was called." << std::endl;
	}

	TesterClass(TesterClass&& move) noexcept
		:id{ move.id }
	{
		// std::cout << "Move constructor was called." << std::endl;
	}

	TesterClass& operator=(const TesterClass& copy) {
		// std::cout << "Copy assignmentd was called." << std::endl;
		if (this == &copy) {
			return *this;
		}
		id = copy.id;
		return *this;
	}

	TesterClass& operator=(TesterClass&& move) noexcept {
		// std::cout << "Move assignmentd was called." << std::endl;
		if (this == &move) {
			return *this;
		}
		id = move.id;
		return *this;
	}

	bool operator<(const TesterClass& test) {
		return id < test.id;
	}

	bool operator>(const TesterClass& test) {
		return id > test.id;
	}

	bool operator==(const TesterClass& obj) {
		return id == obj.id;
	}
	bool operator!=(const TesterClass& obj) {
		return !(*this == obj);
	}

	~TesterClass() {
		// std::cout << "Destructor was called for " << id << std::endl;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}
};

std::ostream& TestUtil::operator<<(std::ostream& os, const TestUtil::TesterClass& obj) {
	os << obj.getId();
	return os;
}

std::istream& TestUtil::operator>>(std::istream& is, TestUtil::TesterClass& obj) {
	int id;
	is >> id;
	obj.setId(id);
	return is;
}


void TestUtil::testLinkedList() {
	auto list = std::make_unique<LinkedList<TesterClass>>();

	list->push_back(1);
	list->push_back(2);
	list->push_front(1);
	list->push_front(2);

	list->clear();

	list->push_front(1);
	list->push_front(2);
	list->push_front(1);
	list->push_front(2);

	list->push_back(1);
	list->push_back(2);
	list->push_back(3);
	list->push_back(4);

	list->push_front(1);
	list->push_front(2);
	list->push_front(3);
	list->push_front(4);

	list->remove(list->size() - 1);
	list->remove(1);
	list->remove(2);
	list->remove(3);
	list->remove(1);
	list->remove(0);
	list->remove(0);
	list->remove(list->size() - 1);

	/*
	std::cout << "\nContains 2: " << std::boolalpha << list->contains(2) << '\n';
	std::cout << "\nContains 3: " << list->contains(3) << '\n';
	std::cout << "\nContains 1: " << list->contains(1) << '\n';
	std::cout << "\nContains 4: " << list->contains(4) << '\n';
	std::cout << "\nIS EMPTY: " << list->isEmpty() << '\n';
	*/

	list->add(0, 1);
	list->add(1, 2);
	list->add(1, 3);
	list->add(1, 4);
	list->add(3, 5);
	list->add(4, 6);

	list->push_front(1);
	list->push_back(8);
	list->push_back(9);
	list->push_back(10);

	/*
	std::cout << "\nINDEX IS: " << list->indexOf(8) << '\n';
	std::cout << "\nINDEX IS: " << list->indexOf(9) << '\n';
	std::cout << "\nINDEX IS: " << list->indexOf(1) << '\n';
	std::cout << "\nINDEX IS: " << list->indexOf(10) << '\n';
	*/


	{
		/*
		std::cout << "Basic O(n^2) print :))" << std::endl;
		for (size_t i{ 0 }; i < list->size(); ++i) {
			std::cout << (*list)[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << *list << std::endl;
		std::cout << std::endl << list->size() << std::endl;
		clearScreen();
		*/
	}

	{
		// Test Copy - Constructor
		auto copyList = *list;

		copyList.remove_front();
		copyList.remove_front();
		copyList.remove_front();
		list->remove_back();
		list->remove_back();
		list->remove_back();

		// std::cout << "COPY: " << copyList << std::endl;
		// std::cout << "REAL: " << *list << std::endl;
		// clearScreen();
	}

	{
		// Test Initializer List
		LinkedList<TesterClass> copyList = { 1,2,3,4,5 };
		// std::cout << copyList;
		// clearScreen();
	}

	{
		LinkedList<TesterClass> copyList;
		copyList = LinkedList<TesterClass>{ 1,2,3,4,5 };
		// std::cout << copyList;
		// clearScreen();
	}

	{
		LinkedList<TesterClass> copyList;
		copyList = *list;
		copyList.clear();
		// std::cout << copyList;
		// std::cout << *list;
		// clearScreen();
	}
}

void TestUtil::read()
{
	Vector v;
	std::cin >> v;
	std::cout << v << std::endl;
}

void TestUtil::clearScreen() {
	for (int i = 0; i < 30; ++i) {
		std::cout << '\n';
	}
}

void TestUtil::testManual()
{
	BigInteger sum, var;
	char operation;

	for (;;) {
		std::cout << "Enter BigInteger operation BigInteger: ";
		std::cin >> sum >> operation >> var;
		std::cout << "Result = ";

		switch (operation)
		{
		case '+':
			std::cout << sum + var << '\n';
			break;
		case '-':
			std::cout << sum - var << '\n';
			break;
		case '*':
			std::cout << sum * var << '\n';
			break;
		case '<':
			std::cout << BigInteger::maxAbs(sum, var) << '\n';
			break;
		case 'x':	/* EXIT */
			break;
		default:
			std::cout << std::endl << "Invalid case. Retry." << std::endl;
			break;
		}
	}
}

BigInteger TestUtil::shouldAdd(BigInteger a, BigInteger b) {
	return a + b;
}

BigInteger TestUtil::shouldSubtract(BigInteger a, BigInteger b) {
	return a - b;
}

BigInteger TestUtil::shouldMultiply(BigInteger a, BigInteger b) {
	return a * b;
}

BigInteger TestUtil::shouldReturnMax(BigInteger a, BigInteger b) {
	return BigInteger::maxAbs(a, b);
}

BigInteger TestUtil::shouldCalculateScalar(Vector a, Vector b)
{
	return a * b;
}

BigInteger TestUtil::shouldCalculateMaxAbs(Vector a)
{
	return a.maxAbs();
}

void TestUtil::testAddition() {
	// Testing addition
	// +A + +B
	assert(BigInteger{ 5 } == shouldAdd(BigInteger{}, 5));
	assert(BigInteger{ 5'399 } == shouldAdd(1'522, 3'877));
	assert(BigInteger{ 10'7597 } == shouldAdd(98'841, 8'756));
	assert(BigInteger{ 13'742 } == shouldAdd(6'871, 6'871));
	assert(BigInteger{ 0 } == shouldAdd(0, 0));

	// +A + -B
	assert(BigInteger{ -280 } == shouldAdd(20, -300));
	assert(BigInteger{ 42'772 } == shouldAdd(64'528, -21'756));
	assert(BigInteger{ 0 } == shouldAdd(0, -0));

	// -A + +B
	assert(BigInteger{ 91'941 } == shouldAdd(-6'516, 98'457));
	assert(BigInteger{ -3'854'385'438'543'854'385 } == shouldAdd(-3'854'385'438'543'854'385, 0));
	assert(BigInteger{ 0 } == shouldAdd(-0, 0));

	// -A + -B
	assert(BigInteger{ -9'331 } == shouldAdd(-8512, -819));
	assert(BigInteger{ -95'365 } == shouldAdd(-8'211, -87'154));
	assert(BigInteger{ -9'024 } == shouldAdd(-4512, -4512));
}

void TestUtil::testSubtraction()
{
	// Testing subtraction
	// +A - +B
	assert(BigInteger{ -799'996 } == shouldSubtract(56'315, 856'311));
	assert(BigInteger{ 251'883 } == shouldSubtract(465'124, 213'241));
	assert(BigInteger{ 0 } == shouldSubtract(8'888, 8'888));

	// +A - +B
	assert(BigInteger{ 246'444'246 } == shouldSubtract(123'123'123, -123'321'123));
	assert(BigInteger{ 76'096 } == shouldSubtract(54'561, -21'535));
	assert(BigInteger{ 0 } == shouldSubtract(0, -0));

	// -A - +B
	assert(BigInteger{ -61'989 } == shouldSubtract(-7'865, 54'124));
	assert(BigInteger{ -111'252'162'153'253 } == shouldSubtract(-111'110'020'011'111, 142'142'142'142));
	assert(BigInteger{ 0 } == shouldSubtract(-0, 0));

	// -A - -B
	assert(BigInteger{ 73'092 } == shouldSubtract(-8'152, -81'244));
	assert(BigInteger{ -49'000 } == shouldSubtract(-54'413, -5'413));
	assert(BigInteger{ 0 } == shouldSubtract(-111, -111));

	// Special cases:
	assert(BigInteger{ 98 } == shouldSubtract(99, 1));
	assert(BigInteger{ 90 } == shouldSubtract(91, 1));
	assert(BigInteger{ 99 } == shouldSubtract(100, 1));
}

void TestUtil::testMultiplication()
{
	// Testing multiplications.
	// +A * +B
	assert(BigInteger{ 241'956'881'121'015'584 } == shouldMultiply(981'275'489, 246'573'856));
	assert(BigInteger{ 105'647'508'128'982'200 } == shouldMultiply(412'450'820, 256'145'710));
	assert(BigInteger{ 15'129'078'966'103'041 } == shouldMultiply(123'000'321, 123'000'321));

	// +A * -B
	assert(BigInteger{ -50'800 } == shouldMultiply(254, -200));
	assert(BigInteger{ -6'400 } == shouldMultiply(40, -160));
	assert(BigInteger{ -10'000'000'000 } == shouldMultiply(100'000, -100'000));

	// -A * +B
	assert(BigInteger{ -44'500 } == shouldMultiply(-445, 100));
	assert(BigInteger{ -15 } == shouldMultiply(-1, 15));
	assert(BigInteger{ -64 } == shouldMultiply(-8, 8));

	// -A * -B
	assert(BigInteger{ 32 } == shouldMultiply(-8, -4));
	assert(BigInteger{ 81 } == shouldMultiply(-3, -27));
	assert(BigInteger{ 0 } == shouldMultiply(-0, -0));
}

void TestUtil::testAbsoluteMaximum()
{
	// Testing maxAbs function.
	// +A >= +B
	assert(BigInteger{ 981'275'489 } == shouldReturnMax(981'275'489, 246'573'856));
	assert(BigInteger{ 981'275'489 } == shouldReturnMax(981'275'489, 981'275'489));

	// +A >= -B
	assert(BigInteger{ 15'129'078'966'103'041 } == shouldReturnMax(15'129'078'966'103'041, -10'000'000'000));
	assert(BigInteger{ 15'129'078'966'103'041 } == shouldReturnMax(15'129'078'966'103'041, 15'129'078'966'103'041));

	// -A >= -B
	assert(BigInteger{ 111'252'162'153'253 } == shouldReturnMax(-111'252'162'153'253, -111'110'020'011'111));
	assert(BigInteger{ 111'252'162'153'253 } == shouldReturnMax(-111'252'162'153'253, -111'252'162'153'253));
}

void TestUtil::testBigInteger()
{
	testAddition();

	testSubtraction();

	testMultiplication();

	testAbsoluteMaximum();
}

void TestUtil::testScalar()
{
	// Empty Cases
	assert(BigInteger{  } == shouldCalculateScalar({  }, {  }));
	assert(BigInteger{ 0 } == shouldCalculateScalar({ 0, 0 }, { 0, -0 }));
	assert(BigInteger{ 0 } == shouldCalculateScalar({ -0, -0 }, { -0, 0 }));
	assert(BigInteger{ 0 } == shouldCalculateScalar({ 0 }, { -0 }));
	assert(BigInteger{ 0 } == shouldCalculateScalar({ -0, -0, -0, -0 }, { -0, 0, 0, 0 }));
	assert(BigInteger{ -0 } == shouldCalculateScalar({ 0 }, { 0 }));
	assert(BigInteger{ -0 } == shouldCalculateScalar({ -0 }, { 0 }));
	assert(BigInteger{ -0 } == shouldCalculateScalar({ 0 }, { -0 }));
	assert(BigInteger{ -0 } == shouldCalculateScalar({ -0 }, { -0 }));

	// Set 1
	assert(BigInteger{ -5 } == shouldCalculateScalar({ 1, 2, 3 }, { -1, -2, 0 }));
	assert(BigInteger{ 9 } == shouldCalculateScalar({ 2, -4, 5 }, { -3, 5, 7 }));
	assert(BigInteger{ 8 } == shouldCalculateScalar({ 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }));

	// Set 2
	assert(BigInteger{ 0 } == shouldCalculateScalar({ 0, -2, 0, 5, -0 }, { -5, -0, 44, 0, -0 }));
	assert(BigInteger{ 25 } == shouldCalculateScalar({ -5, 1 }, { 5, 50 }));
	assert(BigInteger{ 0 } == shouldCalculateScalar({ -234 }, { -0 }));

	// Set 3
	assert(BigInteger{ 16 } == shouldCalculateScalar({ 2, 2, 2, 2 }, { 2, 2, 2, 2 }));
	assert(BigInteger{ 16 } == shouldCalculateScalar({ -2, -2, -2, -2 }, { -2, -2, -2, -2 }));
	assert(BigInteger{ -8 } == shouldCalculateScalar({ 0, -2, 2, 0, -2, 2 }, { 2, 0, -2, 2, 0, -2 }));
}

void TestUtil::testMax()
{
	// Empty Cases
	assert(BigInteger{  } == shouldCalculateMaxAbs({  }));
	assert(BigInteger{  } == shouldCalculateMaxAbs({ 0, 0, -0, -0 }));
	assert(BigInteger{  } == shouldCalculateMaxAbs({ -0 }));
	assert(BigInteger{ 0 } == shouldCalculateMaxAbs({ 0 }));
	assert(BigInteger{ -0 } == shouldCalculateMaxAbs({ -0 }));

	// Set 1
	assert(BigInteger{ 5 } == shouldCalculateMaxAbs({ 1, 2, 3, 4, 5 }));
	assert(BigInteger{ 5 } == shouldCalculateMaxAbs({ -1, 2, -3, 4, -5 }));
	assert(BigInteger{ 99 } == shouldCalculateMaxAbs({ 49, -37, -99, -45, 98, -93, -98, 23, 55, -44 }));

	// Set 2
	assert(BigInteger{ 2'376 } == shouldCalculateMaxAbs({ 27, 1'294, 333, -2'376, -23, -556, 2'375 }));
	assert(BigInteger{ 5 } == shouldCalculateMaxAbs({ -1, 2, -3, 4, -5 }));
	assert(BigInteger{ 123 } == shouldCalculateMaxAbs({ -77, -37, -99, -45, 123, -0, -44, 23, 55, -44 }));
}

void TestUtil::testVector()
{
	testScalar();

	testMax();
}

void TestUtil::testAutomat()
{
	testLinkedList();
	testBigInteger();
	testVector();
}
