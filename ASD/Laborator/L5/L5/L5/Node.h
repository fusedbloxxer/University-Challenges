#pragma once

template<typename T>
class DoubleNode
{
	T value;
	DoubleNode<T>* left, * right;
public:
	DoubleNode(T value, DoubleNode<T>* left = nullptr, DoubleNode<T>* right = nullptr);
	DoubleNode(const DoubleNode<T>& copy);
	DoubleNode(DoubleNode<T>&& move) noexcept;

	DoubleNode<T>& operator=(const DoubleNode<T>& copy);
	DoubleNode<T>& operator=(DoubleNode<T>&& move) noexcept;

	T getValue() const;
	DoubleNode<T>* getLeft();
	DoubleNode<T>* getRight();

	void setLeft(DoubleNode<T>* left);
	void setRight(DoubleNode<T>* right);
	void setValue(const T& value);

	// Deletes all children
	virtual ~DoubleNode();
};

template<typename T>
DoubleNode<T>::DoubleNode(T value, DoubleNode<T>* left, DoubleNode<T>* right)
	:value{ value }, left{ left }, right{ right } {}

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
void DoubleNode<T>::setValue(const T& value)
{
	this->value = value;
}

// Deletes all children
template<typename T>
DoubleNode<T>::~DoubleNode()
{

}