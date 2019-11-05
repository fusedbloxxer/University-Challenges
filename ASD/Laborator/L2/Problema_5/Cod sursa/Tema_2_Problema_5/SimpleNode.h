#pragma once

template<class T>
class SimpleNode
{
	SimpleNode<T>* next;
	T value;
public:
	// Constructor
	SimpleNode(const T& value, SimpleNode<T>* = nullptr);

	// Setters.
	void setNext(SimpleNode<T>* next);
	void setValue(const T& value);

	// Getters.
	SimpleNode<T>* getNext() const;
	T& getValue();

	// Destructors.
	virtual ~SimpleNode() = default;
};

template<class T>
inline SimpleNode<T>::SimpleNode(const T& value, SimpleNode<T>* next)
	:value{ value }, next{ next }
{
}

template<class T>
inline void SimpleNode<T>::setNext(SimpleNode<T>* next)
{
	this->next = next;
}
template<class T>
inline void SimpleNode<T>::setValue(const T& value)
{
	this->value = value;
}

template<class T>
inline SimpleNode<T>* SimpleNode<T>::getNext() const
{
	return next;
}

template<class T>
inline T& SimpleNode<T>::getValue()
{
	return value;
}