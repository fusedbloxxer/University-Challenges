#pragma once
#include "InputOutput_I.h"
#include "LinkedNode_I.h"

template<class Type>
class LinkedNode : public LinkedNode_I<Type>
{
private:
	std::unique_ptr<LinkedNode<Type>> next;
	std::unique_ptr<Type> element;
	LinkedNode<Type>* prev;
public:

	// Inherited from InputOutput_I
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	// Inherited from LinkedNode_I<Type>
	virtual LinkedNode_I<Type>* getNext() const override;
	virtual LinkedNode_I<Type>* getPrev() const override;
	virtual void setNext(LinkedNode_I<Type>* next) override;
	virtual void setPrev(LinkedNode_I<Type>* prev) override;
	virtual void setValue(Type value) override;
	virtual Type& getValue() override;

	virtual ~LinkedNode() = default;
};

template<class Type>
inline void LinkedNode<Type>::print(std::ostream& os) const
{
	if (element) {
		os << *element;
	}
}

template<class Type>
inline void LinkedNode<Type>::read(std::istream& is)
{
	if (element) {
		is >> *element;
	}
	else {
		Type* temp = new Type;
		is >> *temp;
		// Insert and delete old element if necessary.
		element.reset(std::move(std::unique_ptr<Type>(temp)));
	}
}

template<class Type>
inline LinkedNode_I<Type>* LinkedNode<Type>::getNext() const
{
	return next;
}

template<class Type>
inline LinkedNode_I<Type>* LinkedNode<Type>::getPrev() const
{
	return prev;
}

template<class Type>
inline void LinkedNode<Type>::setNext(LinkedNode_I<Type>* next)
{
	this->next.reset(next);
}

template<class Type>
inline void LinkedNode<Type>::setPrev(LinkedNode_I<Type>* prev)
{
	this->prev.reset(prev);
}

template<class Type>
inline void LinkedNode<Type>::setValue(Type value)
{
	element.reset(new Type{ value });
}

template<class Type>
inline Type& LinkedNode<Type>::getValue()
{
	return *element;
}
