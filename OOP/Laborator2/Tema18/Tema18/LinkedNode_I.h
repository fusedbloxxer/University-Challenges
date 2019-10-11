#pragma once
#include "InputOutput_I.h"

template<class Type>
class LinkedNode_I : public InputOutput_I
{
public:
	virtual LinkedNode_I<Type>* getNext() const = 0;
	virtual LinkedNode_I<Type>* getPrev() const = 0;
	virtual void setNext(LinkedNode_I<Type>* next) = 0;
	virtual void setPrev(LinkedNode_I<Type>* prev) = 0;
	virtual void setValue(Type value) = 0;
	virtual Type& getValue() = 0;
	virtual ~LinkedNode_I() = default;
};

