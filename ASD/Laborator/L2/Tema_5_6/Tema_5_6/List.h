#pragma once
#include "IO_I.h"
#include "SimpleNode.h"

template<class T>
class List : public IO_I
{
public:
	virtual SimpleNode<T>* begin() = 0;
	virtual SimpleNode<T>* end() = 0;

	// Insertion.
	virtual void addFirst(const T&) = 0;
	virtual void addLast(const T&) = 0;
	virtual void insert(const T&, size_t) = 0;

	// Find methods.
	virtual size_t findByValue(const T& value) const = 0;
	virtual T findByPos(size_t pos) const = 0;
	
	// Remove methods.
	virtual void removeByPos(size_t pos) = 0;
	virtual void removeByValue(const T& value) = 0;

	// Other methods.
	virtual size_t size() const = 0;
	virtual bool isEmpty() const = 0;

	// Cleaning Method
	virtual void clean() = 0;

	// Destructor.
	virtual ~List() = default;
};

template<class T>
size_t countPos(List<T>& list) {
	size_t count{ 0 };
	for (auto var = list.begin(); var; var = var->getNext()) {
		if (var->getValue() > 0) {
			++count;
		}
	}
	return count;
}

template<class T>
double avgNeg(List<T>& list) {
	long double count{ 0 }, sum{ 0 };
	for (auto var = list.begin(); var; var = var->getNext()) {
		if (var->getValue() < 0) {
			sum += var->getValue();
			++count;
		}
	}
	return sum / double(count);
}

template<class T>
List<T>& addAvg(List<T>& list) {
	if (list.size() > 1) {
		size_t pos{ 1 };
		for (auto var = list.begin(); var->getNext(); var = var->getNext(), ++pos) {
			list.insert((var->getValue() + var->getNext()->getValue()) / double(2), pos);
			var = var->getNext();
			++pos;
		}
	}
	return list;
}
