#pragma once
#include "SingleNode.h"
#include <iostream>

// Forward declaration to use template friends
template<typename T>
class SingleNode;

template<typename T>
class Stack
{
	SingleNode<T>* head;

	template<typename U>
	friend std::istream& operator>>(std::istream& is, Stack<U>& stack);
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Stack<U>& stack);

public:
	Stack();
	Stack(const Stack<T>& stack);
	Stack(Stack<T>&& stack) noexcept;
	Stack<T>& operator=(const Stack<T>& stack);
	Stack<T>& operator=(Stack<T>&& stack) noexcept;

	bool empty() const;
	void push(const T& value);
	T pop();

	virtual ~Stack();

private:
	void freeMemory();
};

template<typename T>
std::istream& operator>>(std::istream& is, Stack<T>& stack)
{
	T element; is >> element;
	stack.push(element);
	return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
{
	os << '[';
	for (SingleNode<T>* node = stack.head; node; node = node->getNext())
	{
		os << *node;
		if (node->getNext() != nullptr)
		{
			os << ", ";
		}
	}
	os << ']';
	return os;
}

template<typename T>
inline Stack<T>::Stack()
	:head{ nullptr }
{
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& stack)
	:head{ new SingleNode{ stack.head } } {}

template<typename T>
inline Stack<T>::Stack(Stack<T>&& stack) noexcept
	:head{ stack.head }
{
	stack.head = nullptr;
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& stack)
{
	if (this == &stack)
	{
		return *this;
	}

	freeMemory();
	head = new SingleNode<T>{ *(stack.head) };

	return *this;
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(Stack<T>&& stack) noexcept
{
	if (this == &stack)
	{
		return *this;
	}

	freeMemory();
	head = stack.head;
	stack.head = nullptr;

	return *this;
}

template<typename T>
inline bool Stack<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void Stack<T>::push(const T& value)
{
	head = new SingleNode(value, head);
}

template<typename T>
inline T Stack<T>::pop()
{
	if (head)
	{
		SingleNode<T>* ptr = head;
		head = head->next;
		T value = ptr->value;
		delete ptr;
		return value;
	}
	else
	{
		throw std::runtime_error{ "POP EXCEPTION" };
	}
}

template<typename T>
inline Stack<T>::~Stack()
{
	freeMemory();
}

template<typename T>
inline void Stack<T>::freeMemory()
{
	while (head)
	{
		SingleNode<T>* temp = head;
		head = head->next;
		delete temp;
	}
}