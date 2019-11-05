#pragma once
#include <iostream>
#include <exception>
#include "List.h"
#include "SimpleNode.h"

template<class T>
class SimpleList : public List<T>
{
protected:
	size_t sz;
	SimpleNode<T>* head, * tail;
public:
	// Constructors.
	SimpleList(size_t sz = 0);
	SimpleList(size_t sz, const T& def);
	SimpleList(const SimpleList& copy);
	SimpleList(SimpleList&& move) noexcept;
	SimpleList(std::initializer_list<T> list);

	// Assignments
	SimpleList<T>& operator=(const SimpleList& copy);
	SimpleList<T>& operator=(SimpleList&& move) noexcept;

	// Add methods.
	virtual void addFirst(const T& element) override;
	virtual void addLast(const T& element) override;
	// Pe aceasta pozitie
	virtual void insert(const T& element, size_t index) override;

	// Remove methods.
	virtual void removeByPos(size_t pos) override;
	virtual void removeByValue(const T& element) override;
	void removeLast();
	void removeFirst();

	// Find methods.
	virtual size_t findByValue(const T& element) const override;
	virtual T findByPos(size_t pos) const override;

	// Iterators.
	virtual SimpleNode<T>* begin() override;
	virtual SimpleNode<T>* end() override;

	// Inherited from IO_I
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	// Size operations.
	virtual size_t size() const override;
	virtual bool isEmpty() const override;

	// Clean list.
	virtual void clean() override;

	// Destructor.
	virtual ~SimpleList();
private:
};

template<class T>
inline SimpleList<T>::SimpleList(size_t sz)
	:SimpleList<T>(sz, T())
{
}

template<class T>
inline SimpleList<T>::SimpleList(size_t siz, const T& def)
	: sz{ 0 }, head{ nullptr }, tail{ nullptr }
{
	for (size_t i{ 0 }; i < siz; ++i) {
		addFirst(def);
	}
}

template<class T>
inline SimpleList<T>::SimpleList(const SimpleList& copy)
	:sz{ 0 }, head{ nullptr }, tail{ nullptr }
{
	for (auto var = copy.head; var; var = var->getNext()) {
		addLast(var->getValue());
	}
}

template<class T>
inline SimpleList<T>::SimpleList(SimpleList&& move) noexcept
	:sz{ move.sz }, head{ move.head }, tail{ move.tail }
{
	move.head = nullptr;
	move.tail = nullptr;
	move.sz = 0;
}

template<class T>
inline SimpleList<T>::SimpleList(std::initializer_list<T> list)
	:sz{ 0 }, head{ nullptr }, tail{ nullptr }
{
	for (const auto& e : list) {
		addLast(e);
	}
}

template<class T>
inline SimpleList<T>& SimpleList<T>::operator=(const SimpleList& copy)
{
	if (this == &copy) {
		return *this;
	}

	clean();
	for (auto var = copy.head; var; var = var->getNext()) {
		addLast(var->getValue());
	}

	return *this;
}

template<class T>
inline SimpleList<T>& SimpleList<T>::operator=(SimpleList&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	clean();
	sz = move.sz;
	head = move.head;
	tail = move.tail;

	move.sz = 0;
	move.head = nullptr;
	move.tail = nullptr;

	return *this;
}

template<class T>
inline void SimpleList<T>::addFirst(const T& element)
{
	if (!head) {
		tail = head = new SimpleNode<T>(element);
	}
	else {
		head = new SimpleNode<T>(element, head);
	}
	++sz;
}

template<class T>
inline void SimpleList<T>::addLast(const T& element)
{
	if (!tail) {
		head = tail = new SimpleNode<T>(element);
	}
	else {
		tail->setNext(new SimpleNode<T>(element));
		tail = tail->getNext();
	}
	++sz;
}

template<class T>
inline void SimpleList<T>::insert(const T& element, size_t index)
{
	if (index == 0) {
		addFirst(element);
	}
	else if (index == sz) {
		addLast(element);
	}
	else {
		auto var = head;
		for (decltype(sz) i{ 0 }; i < index - 1; ++i) {
			var = var->getNext();
		}
		var->setNext(new SimpleNode<T>{ element, var->getNext() });
		++sz;
	}
}

template<class T>
inline void SimpleList<T>::removeByPos(size_t pos)
{
	if (pos == 0) {
		removeFirst();
	}
	else if (pos == sz - 1) {
		removeLast();
	}
	else if (pos < sz) {
		auto var = head;
		for (decltype(sz) i{ 0 }; i < pos - 1; ++i) {
			var = var->getNext();
		}

		auto temp = var->getNext();
		var->setNext(temp->getNext());
		delete temp;
		--sz;
	}
}

template<class T>
inline void SimpleList<T>::removeByValue(const T& element)
{
	if (head && head->getValue() == element) {
		removeFirst();
	}
	else {
		for (auto var = head; var && var->getNext(); var = var->getNext()) {
			if (element == var->getNext()->getValue()) {
				auto temp = var->getNext();
				var->setNext(temp->getNext());
				if (tail == temp) {
					tail = var;
				}
				delete temp;
				--sz;
				return;
			}
		}
	}
}

template<class T>
inline void SimpleList<T>::removeLast()
{
	if (head) {

		if (head == tail) {
			head = nullptr;
			delete tail;
		}
		else {
			auto var = head;
			while (var->getNext() != tail) {
				var = var->getNext();
			}
			var->setNext(nullptr);
			delete tail;
			tail = var;
		}
		--sz;
	}
}

template<class T>
inline void SimpleList<T>::removeFirst()
{
	if (head) {
		auto var = head;
		head = head->getNext();
		delete var;
		--sz;
	}
}

template<class T>
inline size_t SimpleList<T>::findByValue(const T& element) const
{
	decltype(sz) i{ 0 };
	for (auto var = head; var; var = var->getNext(), ++i) {
		if (element == var->getValue()) {
			return i;
		}
	}
	throw std::exception{ "element not found" };
}

template<class T>
inline T SimpleList<T>::findByPos(size_t pos) const
{
	if (pos >= sz) {
		throw std::exception("List index is out of bounds.");
	}

	decltype(sz) i{ 0 };
	auto var = head;

	while (var && i < pos) {
		var = var->getNext();
		++i;
	}

	return var->getValue();
}

template<class T>
inline SimpleNode<T>* SimpleList<T>::begin()
{
	return head;
}

template<class T>
inline SimpleNode<T>* SimpleList<T>::end()
{
	return tail;
}

template<class T>
inline void SimpleList<T>::print(std::ostream& os) const
{
	for (auto var = head; var; var = var->getNext()) {
		os << var->getValue() << ' ';
	}
}

template<class T>
inline void SimpleList<T>::read(std::istream& is)
{
	clean();
	std::cout << "Enter number of elements: ";
	decltype(sz) temp; is >> temp; T element;

	for (decltype(sz) i{ 0 }; i < temp; ++i) {
		is >> element;
		addLast(element);
	}
}

template<class T>
inline size_t SimpleList<T>::size() const
{
	return sz;
}

template<class T>
inline bool SimpleList<T>::isEmpty() const
{
	return sz == 0;
}

template<class T>
inline void SimpleList<T>::clean()
{
	sz = 0;
	tail = nullptr;
	while (head) {
		auto x = head;
		head = head->getNext();
		delete x;
	}
}

template<class T>
inline SimpleList<T>::~SimpleList()
{
	clean();
}
