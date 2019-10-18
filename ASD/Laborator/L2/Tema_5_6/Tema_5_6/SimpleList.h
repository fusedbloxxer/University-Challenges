#pragma once
#include "List.h"
#include "SimpleNode.h"

template<class T>
class SimpleList : public List<T>
{
	size_t sz;
	SimpleNode<T>* head, * tail;
public:
	// Constructors.
	SimpleList(size_t sz = 0);
	SimpleList(size_t sz, const T& def);

	// Add methods.
	virtual void addFirst(const T& element) override;
	virtual void addLast(const T& element) override;
	virtual void insert(const T& element, size_t index) override;

	// Remove methods.
	virtual void removeByPos(size_t pos) override;
	virtual void removeByValue(const T& element) override;
	void removeLast();
	void removeFirst();

	// Find methods.
	virtual size_t findByValue(const T& element) const override;
	virtual T findByPos(size_t pos) const override;

	// Inherited from IO_I
	virtual void print(std::ostream& os) const override;
	virtual void read(std::istream& is) override;

	// Clean list.
	virtual void clean() override;

	// Destructor.
	virtual ~SimpleList();
};

template<class T>
inline SimpleList<T>::SimpleList(size_t sz)
	:SimpleList<T>(sz, T())
{
}

template<class T>
inline SimpleList<T>::SimpleList(size_t sz, const T& def)
	:sz{ sz }
{
	for (size_t i{ 0 }; i < sz; ++i) {
		addFirst(def);
	}
}

template<class T>
inline void SimpleList<T>::addFirst(const T& element)
{
	if (!head) {
		tail = head = new SimpleNode<T>(element);
	}
	else {
		head = new SimpleNode<T>(element, head);
		if (head->getNext() == tail) {
			prev = head;
		}
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
		prev = tail;
		tail->setNext(new SimpleNode<T>( element ));
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
		for (decltype(sz) i{ 0 }; i < index; ++i) {
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
	else {
		decltype(sz) i{ 0 };
		auto var = head;
		while (var && i < pos) {
			var = var->getNext();
			++i;
		}
	}
}

template<class T>
inline void SimpleList<T>::removeByValue(const T& element)
{

}

template<class T>
inline void SimpleList<T>::removeLast()
{
	if (head) {
		if (head == tail) {
			delete tail;
			head = nullptr;
		}
		else {
			auto var = head;
			while (var && var->getNext() != tail) {
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
		if (!head) {
			tail = nullptr;
		}
		delete var;
		--sz;
	}
}

template<class T>
inline T SimpleList<T>::findByPos(size_t pos) const
{
	if (pos >= sz) {
		throw new std::exception{ "List index is out of bounds." };
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
inline void SimpleList<T>::print(std::ostream& os) const
{
	for (auto var = head; var; var = var->getNext()) {
		os << vars->getValue() << ' ';
	}
}

template<class T>
inline void SimpleList<T>::read(std::istream& is)
{
	clean();
	std::cout << "Enter number of elements: ";
	is >> sz; T element;
	
	for (decltype(sz) i{ 0 }; i < sz; ++i) {
		is >> element;
		addLast(element);
	}
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