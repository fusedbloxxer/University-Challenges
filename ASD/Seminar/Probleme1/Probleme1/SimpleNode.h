#pragma once
#include <memory>

template<class T>
class SimpleNode
{
	std::unique_ptr<T> ptrValue;
	SimpleNode<T>* next;
public:
	SimpleNode(const T& element, SimpleNode<T>* next = nullptr);
	SimpleNode(const SimpleNode<T>& copy) = delete;
	SimpleNode(SimpleNode<T>&& move);
	SimpleNode<T>& operator=(const SimpleNode<T>& copy) = delete;
	SimpleNode<T>& operator=(SimpleNode&& move);
	SimpleNode<T>& operator++();
	T getValue() const override;
	SimpleNode<T>* getNext() override;
	void setValue(const T& element) override;
	void setNext(const SimpleNode<T>* next) override;
};

template<class T>
inline SimpleNode<T>::SimpleNode(const T& element, SimpleNode<T>* next)
	:ptrValue{ new T{element} }, next{ next }
{

}

template<class T>
inline SimpleNode<T>::SimpleNode(SimpleNode<T>&& move)
	:ptrValue{ std::move(move.ptrValue) }, next{ move.next }
{
	move.next = nullptr;
}

template<class T>
inline SimpleNode<T>& SimpleNode<T>::operator=(SimpleNode&& move)
{
	if (this == &move) {
		return *this;
	}

	ptrValue.reset(std::move(move.ptrValue));
	next = move.next;
	move.next = nullptr;
}

template<class T>
inline SimpleNode<T>& SimpleNode<T>::operator++()
{
	if (next) {
		next = next->getNext();
	}
}

template<class T>
inline T SimpleNode<T>::getValue() const
{
	return *ptrValue;
}

template<class T>
inline SimpleNode<T>* SimpleNode<T>::getNext()
{
	return next;
}

template<class T>
inline void SimpleNode<T>::setValue(const T& element)
{
	// Replace old element with the new one.
	ptrValue.reset(new T{ element });
}

template<class T>
inline void SimpleNode<T>::setNext(const SimpleNode<T>* next)
{
	this->next = next;
}
