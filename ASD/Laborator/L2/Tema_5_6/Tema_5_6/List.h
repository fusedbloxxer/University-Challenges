#pragma once
#include "IO_I.h"

template<class T>
class List : public IO_I
{
public:
	// Insertion.
	virtual void addFirst(const T&) = 0;
	virtual void addLast(const T&) = 0;
	virtual void insert(const T&, size_t) = 0;

	// Find methods.
	virtual size_t findByValue(const T& value) const = 0;
	virtual T findByPos(size_t pos) const = 0;
	
	// Remove methods.
	virtual void removeByPos(size_t pos) = 0;
	virtual void removeByValue(const T& value) = 0;

	// Other methods.
	virtual size_t size() const = 0;

	// Cleaning Method
	virtual void clean() = 0;

	// Destructor.
	virtual ~List() = default;
};

