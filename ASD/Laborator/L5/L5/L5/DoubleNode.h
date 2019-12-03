#pragma once
#include "AVL.h"
#include <iostream>

template<typename T>
class AVL;

template<typename T>
class DoubleNode
{
	int bal;
	T value;
	DoubleNode<T>* left, * right;

	friend class AVL<T>;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const DoubleNode<U>& node);
	template<typename U>
	friend std::istream& operator>>(std::istream& is, DoubleNode<U>& node);

public:
	DoubleNode(T value, DoubleNode<T>* left = nullptr, DoubleNode<T>* right = nullptr);
	DoubleNode(const DoubleNode<T>& copy);
	DoubleNode(DoubleNode<T>&& move) noexcept;

	DoubleNode<T>& operator=(const DoubleNode<T>& copy);
	DoubleNode<T>& operator=(DoubleNode<T>&& move) noexcept;

	T getValue() const;
	int getBalance() const;
	DoubleNode<T>* getLeft();
	DoubleNode<T>* getRight();

	void setBalance(int balance);
	void setValue(const T& value);
	void setLeft(DoubleNode<T>* left);
	void setRight(DoubleNode<T>* right);

	// Deletes all children
	virtual ~DoubleNode();
};

template<typename T>
DoubleNode<T>::DoubleNode(T value, DoubleNode<T>* left, DoubleNode<T>* right)
	:value{ value }, left{ left }, right{ right }, bal{ 0 } {}

template<typename T>
DoubleNode<T>::DoubleNode(const DoubleNode<T>& copy)
	: value{ copy.value }, left{ nullptr }, right{ nullptr }
{
	// COPY
}

template<typename T>
DoubleNode<T>::DoubleNode(DoubleNode<T>&& move) noexcept
	:value{ move.value }, left{ move.left }, right{ move.right }
{
	move.left = nullptr;
	move.right = nullptr;
}

template<typename T>
DoubleNode<T>& DoubleNode<T>::operator=(const DoubleNode<T>& copy)
{
	if (this == &copy)
	{
		return *this;
	}

	value = copy.value;
	// COPY

	return *this;
}

template<typename T>
DoubleNode<T>& DoubleNode<T>::operator=(DoubleNode<T>&& move) noexcept
{
	if (this == &move)
	{
		return *this;
	}

	value = move.value;
	left = move.left;
	right = move.right;
	move.left = nullptr;
	move.right = nullptr;

	return *this;
}

template<typename T>
T DoubleNode<T>::getValue() const
{
	return value;
}

template<typename T>
inline int DoubleNode<T>::getBalance() const
{
	return bal;
}

template<typename T>
DoubleNode<T>* DoubleNode<T>::getLeft()
{
	return left;
}
template<typename T>
DoubleNode<T>* DoubleNode<T>::getRight()
{
	return right;
}

template<typename T>
void DoubleNode<T>::setLeft(DoubleNode<T>* left)
{
	this->left = left;
}

template<typename T>
void DoubleNode<T>::setRight(DoubleNode<T>* right)
{
	this->right = right;
}

template<typename T>
inline void DoubleNode<T>::setBalance(int balance)
{
	this->bal = balance;
}

template<typename T>
void DoubleNode<T>::setValue(const T& value)
{
	this->value = value;
}

// Deletes all children
template<typename T>
DoubleNode<T>::~DoubleNode()
{

}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, const DoubleNode<U>& node)
{
	os << "[v: " << node.value << ", b: " << node.bal << "] ";
	return os;
}

template<typename U>
inline std::istream& operator>>(std::istream& is, DoubleNode<U>& node)
{
	is >> node.value;
	return is;
}
