#pragma once
#include "Node.h"

template<class T>
class Iterator
{
private:
	Node<T>* current;
public:
	Iterator(Node<T>* ptr)
		:current{ ptr } {}

	Iterator(const Iterator<T>& it)
		:current{ it.current } {}

	Iterator<T>& operator++() {
		if (current) {
			current = current->getNext();
		}
		return *this;
	}

	T& getValue() {
		if (current) {
			return current->getValue();
		}
		throw std::out_of_range{ "Item doesn't exist." };
	}

	Node<T>* getNext() {
		if (current) {
			return current->getNext();
		}
		throw std::out_of_range{ "Item doesn't exist." };
	}

	Node<T>* getNode() {
		if (current) {
			return current;
		}
		throw std::out_of_range{ "Item doesn't exist." };
	}

	Node<T>* setNext(Node<T>* next) {
		if (current) {
			current->setNext(next);
		}
		throw std::out_of_range{ "Item doesn't exist." };
	}

	bool operator==(const Iterator<T>& it) {
		return (this == &it) || (current == it.current);
	}

	bool operator!=(const Iterator<T>& it) {
		return !(*this == it);
	}
};

