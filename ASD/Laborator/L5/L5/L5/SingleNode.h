#pragma once
#include "Stack.h"
#include<iostream>

// Forward declaration to use template friends
template<class T>
class Stack;

template<typename T>
class SingleNode
{
	T value;
	SingleNode<T>* next;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const SingleNode<U>& node);
	template<typename U>
	friend std::istream& operator<<(std::istream& is, SingleNode<U>& node);

	friend class Stack<T>;

public:
	SingleNode(T value, SingleNode<T>* next = nullptr);

	SingleNode(const SingleNode<T>& copy);
	SingleNode(SingleNode<T>&& move) noexcept;

	SingleNode<T>& operator=(const SingleNode<T>& copy);
	SingleNode<T>& operator=(SingleNode<T>&& move) noexcept;

	T getValue() const;
	SingleNode<T>* getNext();

	void setNext(SingleNode<T>* next);
	void setValue(const T& value);

	virtual ~SingleNode();
};

template<typename T>
inline SingleNode<T>::SingleNode(T value, SingleNode<T>* next)
	:value{ value }, next{ next } {}

template<typename T>
inline SingleNode<T>::SingleNode(const SingleNode<T>& copy)
	: value{ copy.value }, next{ nullptr }
{
	if (copy.next != nullptr)
	{
		SingleNode<T>* node = next = new SingleNode(copy.next->value);
		for (SingleNode<T>* temp = copy.next->next; temp; temp = temp->next)
		{
			node->next = new SingleNode(temp->value);
			node = node->next;
		}
		node->next = nullptr;
	}
}

template<typename T>
inline SingleNode<T>::SingleNode(SingleNode<T>&& move) noexcept
	:value{ move.value }, next{ move.next }
{
	move.next = nullptr;
}

template<typename T>
inline SingleNode<T>& SingleNode<T>::operator=(const SingleNode<T>& copy)
{
	if (this == &copy)
	{
		return *this;
	}

	while (next != nullptr)
	{
		SingleNode<T>* temp = next;
		next = next->next;
		delete temp;
	}

	value = copy.value;
	if (copy.next != nullptr)
	{
		next = new SingleNode(copy.next->value);
		SingleNode<T>* copy = next->next;
		for (SingleNode<T>* temp = copy->next->next; temp; temp = temp->next)
		{
			copy->next = new SingleNode(temp->value);
			copy = copy->next;
		}
		copy->next = nullptr;
	}

	return *this;
}

template<typename T>
inline SingleNode<T>& SingleNode<T>::operator=(SingleNode<T>&& move) noexcept
{
	if (this == &move)
	{
		return *this;
	}

	value = move.value;
	next = move.next;
	move.next = nullptr;

	return *this;
}

template<typename T>
inline T SingleNode<T>::getValue() const
{
	return value;
}

template<typename T>
inline SingleNode<T>* SingleNode<T>::getNext()
{
	return next;
}

template<typename T>
inline void SingleNode<T>::setNext(SingleNode<T>* next)
{
	this->next = next;
}

template<typename T>
inline void SingleNode<T>::setValue(const T& value)
{
	this->value = value;
}

template<typename T>
inline SingleNode<T>::~SingleNode()
{

}

template<typename T>
std::ostream& operator<<(std::ostream& os, const SingleNode<T>& node)
{
	os << node.value;
	return os;
}

template<typename T>
std::istream& operator<<(std::istream& is, SingleNode<T>& node)
{
	is >> node.value;
	return is;
}
