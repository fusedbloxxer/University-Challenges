#pragma once
#include "InputOutput_I.h"

template<class T>
class LinkedNode : public InputOutput_I
{
	using link = typename LinkedNode<T>*;
	link prev, next;
	T element;

public:
	// Constructors. Warning ! Some of them should be marked as deleted.
	LinkedNode(const T& element, link prev = nullptr, link next = nullptr);
	LinkedNode(const LinkedNode<T>& copy);
	LinkedNode(LinkedNode<T>&& move) noexcept;

	// Copy/Move Assignments. Warning ! They should be marked as deleted.
	LinkedNode<T>& operator=(const LinkedNode<T>& copy);
	LinkedNode<T>& operator=(LinkedNode<T>&& move) noexcept;

	// Inherited from InputOutput_I
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	// Operations
	virtual void setNext(link next);
	virtual LinkedNode<T>* getNext();
	virtual void setPrev(link prev);
	virtual LinkedNode<T>* getPrev();
	virtual void setValue(T value);
	virtual T& getValue();

	bool operator==(const LinkedNode<T>& linkedNode) {
		return element == linkedNode.element;
	}

	bool operator!=(const LinkedNode<T>& linkedNode) {
		return !(*this == linkedNode);
	}

	// Nothing to free here.
	virtual ~LinkedNode() = default;
};

template<class T>
inline LinkedNode<T>::LinkedNode(const T& element, link prev, link next)
	:element{ element }, prev{ prev }, next{ next }
{
}

template<class T>
inline LinkedNode<T>::LinkedNode(const LinkedNode<T>& copy)
	: element{ copy.element }, prev{ copy.prev }, next{ copy.next }
{
	std::cout << "Warning ! The node " << element << " was copy-constructed. Beware of leaks !" << std::endl;
}

template<class T>
inline LinkedNode<T>::LinkedNode(LinkedNode<T>&& move) noexcept
	:element{ move.element }, prev{ prev }, next{ next }
{
	move.prev = nullptr;
	move.next = nullptr;
}

template<class T>
inline LinkedNode<T>& LinkedNode<T>::operator=(const LinkedNode<T>& copy)
{
	if (this == &copy) {
		return *this;
	}

	if (!prev || !next) {
		throw std::exception{ "Possible leak found." };
	}

	element = copy.element;
	prev = copy.prev;
	next = copy.next;

	std::cout << "Warning ! The node " << copy.element << " was copy-assigned. Beware of leaks !" << std::endl;
}

template<class T>
inline LinkedNode<T>& LinkedNode<T>::operator=(LinkedNode<T>&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	if (!prev || !next) {
		throw std::exception{ "Possible leak found." };
	}

	element = move.element;
	prev = move.prev;
	next = move.next;
	move.prev = nullptr;
	move.next = nullptr;

	std::cout << "Warning ! The node " << move.element << " was move-assigned. Beware of leaks !" << std::endl;
}

template<class T>
inline void LinkedNode<T>::print(std::ostream& os) const
{
	os << element;
}

template<class T>
inline void LinkedNode<T>::read(std::istream& is)
{
	is >> element;
}

template<class T>
inline LinkedNode<T>* LinkedNode<T>::getNext()
// Cauta mai amanuntit de ce nu merge sa retunrez tipul link.
{
	return next;
}

template<class T>
inline LinkedNode<T>* LinkedNode<T>::getPrev()
// Cauta mai amanuntit de ce nu merge sa retunrez tipul link.
{
	return prev;
}

template<class T>
inline void LinkedNode<T>::setNext(link next)
{
	this->next = next;
}

template<class T>
inline void LinkedNode<T>::setPrev(link prev)
{
	this->prev = prev;
}

template<class T>
inline void LinkedNode<T>::setValue(T value)
{
	element = value;
}

template<class T>
inline T& LinkedNode<T>::getValue()
{
	return element;
}
