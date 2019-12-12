#pragma once
#include "InputOutput_I.h"
#include "LinkedNode.h"

template<class T>
class List_I : public InputOutput_I
{
public:
	// Comparator
	virtual bool operator<(const List_I<T>& list) const = 0;
	virtual int compareTo(const List_I<T>& list) const = 0;

	// Equals and !equals.
	virtual bool operator==(const List_I<T>& list) const = 0;
	virtual bool operator!=(const List_I<T>& list) const;

	// Sort of iterator.
	virtual LinkedNode<T>* begin() const = 0;
	virtual LinkedNode<T>* end() const = 0;

	// Add new elements to the resource handle.
	virtual void add(size_t index, const T& element) = 0;
	virtual void push_front(const T& element) = 0;
	virtual void push_back(const T& element) = 0;

	// Check if the list contains the element.
	virtual size_t indexOf(const T& element) const = 0;
	virtual bool contains(const T& element) const = 0;

	// Access elements using the subscription.
	virtual T& operator[](size_t o) = 0;

	// Remove elements from the container.
	virtual void remove(size_t index) = 0;
	virtual void remove_front() = 0;
	virtual void remove_back() = 0;

	// Check if it is empty.
	virtual bool isEmpty() const = 0;
	virtual size_t size() const = 0;

	// Clear container.
	virtual void clear() = 0;

	// Destructor.
	virtual ~List_I() = default;
};

template<class T>
inline bool List_I<T>::operator!=(const List_I<T>& list) const
{
	return !(*this == list);
}
