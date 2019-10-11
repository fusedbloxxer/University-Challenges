#pragma once
#include "List_I.h"
#include "LinkedNode.h"

template<class T>
class LinkedList : public List_I<T>
{
	LinkedNode<T>* head, * tail;
	size_t sz;

public:
	// Constructor.
	LinkedList();
	LinkedList(const LinkedList<T>& copy);
	LinkedList(LinkedList<T>&& move) noexcept;
	LinkedList(std::initializer_list<T> initList);

	// Move/Copy operators.
	LinkedList<T>& operator=(const LinkedList<T>& copy);
	LinkedList<T>& operator=(LinkedList<T>&& move) noexcept;

	// Inherited via List_I<T>
	// Add new elements to the resource handle.
	virtual void add(size_t index, const T& element) override;
	virtual void push_front(const T& element) override;
	virtual void push_back(const T& element) override;

	// Check if the list contains the element.
	virtual size_t indexOf(const T& element) const override;
	virtual bool contains(const T& element) const override;

	// Access elements using the subscription.
	virtual T& operator[](size_t o) override;

	// Remove elements from the container.
	virtual void remove(size_t index) override;
	virtual void remove_front() override;
	virtual void remove_back() override;

	// Check if it is empty.
	virtual bool isEmpty() const override;
	virtual size_t size() const override;

	// Clear container.
	virtual void clear() override;

	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	virtual ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList()
	:sz{ 0 }, head{ nullptr }, tail{ nullptr } 
{ 
	// std::cout << "Default constructor for list was called." << std::endl;
}

template<class T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& copy)
	: head{ nullptr }, tail{ nullptr }, sz{ 0 }
{
	// std::cout << "Copy Constructor For List was called." << std::endl;
	for (auto node = copy.head; node; node = node->getNext()) {
		push_back(node->getValue());
	}
}

template<class T>
inline LinkedList<T>::LinkedList(LinkedList<T>&& move) noexcept
	:sz{ move.sz }, head{ move.head }, tail{ move.tail }
{
	// std::cout << "Move Constructor For List was called." << std::endl;
	move.head = nullptr;
	move.tail = nullptr;
	move.size = 0;
}

template<class T>
inline LinkedList<T>::LinkedList(std::initializer_list<T> initList)
	:head{ nullptr }, tail{ nullptr }, sz{ 0 }
{
	// std::cout << "Initializer list" << std::endl;
	for (const auto& elem : initList) {
		push_back(elem);
	}
}

template<class T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& copy)
{
	// std::cout << "Copy Assignment For List was called." << std::endl;

	if (this == &copy) {
		return *this;
	}

	clear();

	for (auto node = copy.head; node; node = node->getNext()) {
		push_back(node->getValue());
	}

	return *this;
}

template<class T>
inline LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& move) noexcept
{
	// std::cout << "Move Assignment For List was called." << std::endl;

	if (this == &move) {
		return *this;
	}

	clear();

	head = move.head;
	tail = move.tail;
	sz = move.sz;
	move.head = nullptr;
	move.tail = nullptr;
	move.sz = 0;

	return *this;
}

template<class T>
inline bool LinkedList<T>::isEmpty() const
{
	return sz == 0;
}

template<class T>
inline size_t LinkedList<T>::size() const
{
	return sz;
}

template<class T>
inline void LinkedList<T>::clear()
{
	sz = 0;
	tail = nullptr;
	while (head) {
		auto temp = head;
		head = head->getNext();
		delete temp;
	}
}

template<class T>
inline void LinkedList<T>::print(std::ostream& os) const
{
	for (auto node = head; node; node = node->getNext()) {
		os << node->getValue();

		if (node->getNext()) {
			os << ' ';
		}
	}
}

template<class T>
inline void LinkedList<T>::read(std::istream& is)
{
	clear();
	std::cout << "Enter number of elements: ";

	long long number;
	if (is >> number) {
		if (number < 0) {
			throw std::exception{ "Error: negative number of elements." };
		}
		else {
			T dummy;
			while (number) {
				--number;
				is >> dummy;
				push_back(dummy);
			}
		}
	}
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	clear();
}

template<class T>
inline void LinkedList<T>::push_front(const T& element)
{
	if (!head) {
		tail = head = new LinkedNode<T>{ element };
	}
	else {
		auto temp = new LinkedNode<T>{ element, nullptr, head };
		head->setPrev(temp);
		head = temp;
	}
	++sz;
}

template<class T>
inline void LinkedList<T>::push_back(const T& element)
{
	if (!tail) {
		head = tail = new LinkedNode<T>{ element };
	}
	else {
		auto temp = new LinkedNode<T>{ element, tail };
		tail->setNext(temp);
		tail = temp;
	}
	++sz;
}

template<class T>
inline void LinkedList<T>::add(size_t index, const T& element)
{
	if (index == 0) {
		push_front(element);
	}
	else if (index == sz) {
		push_back(element);
	}
	else {
		auto node = head;

		// Traverse the list.
		while (--index >= 1) {
			node = node->getNext();
		}

		// Insert the new node.
		node->getNext()->setPrev(new LinkedNode<T>{ element , node, node->getNext() });
		node->setNext(node->getNext()->getPrev());

		++sz;
	}
}

template<class T>
inline size_t LinkedList<T>::indexOf(const T& element) const
{
	size_t index{ 0 };
	for (auto node = head; node; node = node->getNext()) {
		if (node->getValue() == element) {
			return index;
		}
		++index;
	}
	throw std::exception{ "Element was not found." };
}

template<class T>
inline bool LinkedList<T>::contains(const T& element) const
{
	try {
		indexOf(element);
		return true;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << "\nThe element is: " << element << std::endl;
		return false;
	}
}

template<class T>
inline T& LinkedList<T>::operator[](size_t o)
{
	if (o >= sz) {
		throw std::exception{ "List index out of bounds." };
	}

	auto node = head;
	while (o-- > 0) {
		node = node->getNext();
	}

	return node->getValue();
}

template<class T>
inline void LinkedList<T>::remove(size_t index)
{
	if (index == 0) {
		remove_front();
	}
	else if (index == sz - 1) {
		remove_back();
	}
	else {
		auto node = head;

		// Traverse the list.
		while (--index >= 1) {
			node = node->getNext();
		}

		// Remove the node.
		node->setNext(node->getNext()->getNext());
		delete node->getNext()->getPrev();
		node->getNext()->setPrev(node);

		--sz;
	}
}

template<class T>
inline void LinkedList<T>::remove_front()
{
	if (head) {
		if (head == tail) {
			delete head;
			tail = head = nullptr;
		}
		else {
			head = head->getNext();
			delete head->getPrev();
			head->setPrev(nullptr);
		}
		--sz;
	}
}

template<class T>
inline void LinkedList<T>::remove_back()
{
	if (tail) {
		if (head == tail) {
			delete tail;
			head = tail = nullptr;
		}
		else {
			tail = tail->getPrev();
			delete tail->getNext();
			tail->setNext(nullptr);
		}
		--sz;
	}
}
