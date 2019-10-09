#pragma once
#include <memory>

template<class T>
class Node
{
private:
	std::unique_ptr<T> ptr;
	Node<T>* next;

public:
	Node(T element)
		:ptr{ new T{element} }, next{ nullptr } {}

	bool operator==(const Node<T>& node) {
		return this == &node || ptr == node.ptr;
	}

	T& getValue() {
		return *ptr;
	}

	void setNext(Node<T>* next) {
		this->next = next;
	}

	Node<T>* getNext() {
		return next;
	}

	~Node() = default;
};

