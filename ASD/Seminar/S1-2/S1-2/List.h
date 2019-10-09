#pragma once
#include "IO_I.h"

template<class T>
class List : public Printable_I
{
public:
	// Add methods.
	virtual void addFirst(T element) = 0;
	virtual void addLast(T element) = 0;

	// Search methods.
	virtual T& get(size_t index) = 0;
	virtual T& front() {
		return get(0);
	}

	// Remove methods.
	virtual void removeFirst() = 0;
	virtual void removeLast() = 0;

	// Other methods.
	virtual bool empty() const = 0;

	// Virtual destructor.
	virtual ~List() = default;
};