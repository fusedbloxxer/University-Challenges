#pragma once
#include "List.h"
#include "Iterator.h"

template<class T>
class SimpleList : public List<T>
{
private:
	size_t count;
	Node<T>* first, * last;
public:
	SimpleList()
		:first{ nullptr }, last{ nullptr }, count{ 0 } {}

	Iterator<T> begin() {
		// The first node.
		return Iterator<T>(first);
	}

	Iterator<T> end() {
		// One past the last element.
		if (last) {
			return Iterator<T>(last->getNext());
		}
		return Iterator<T>{last};
	}

	// Add methods.
	virtual void addFirst(T element) override {
		if (!first) {
			first = new Node<T>{ element };
			first->setNext(nullptr);
			last = first;
		}
		else {
			Node<T>* temp = new Node<T>{ element };
			temp->setNext(first);
			first = temp;
		}
		++count;
	}

	virtual void addLast(T element) override {
		if (!last) {
			first = new Node<T>{ element };
			first->setNext(nullptr);
			last = first;
		}
		else {
			Node<T>* temp = new Node<T>{ element };
			temp->setNext(nullptr);
			last->setNext(temp);
			last = temp;
		}
		++count;
	}

	// Search methods.
	virtual T& get(size_t index) {
		if (index < 0 || index >= count) {
			throw std::out_of_range{ "Out of bounds." };
		}
		size_t curr{ 0 };
		auto it = first;
		while (it != last && curr != index) {
			it = it->getNext(); ++curr;
		}
		return it->getValue();
	}

	// Remove methods.
	virtual void removeFirst() {
		if (first) {
			Node<T>* temp = first;
			if (first == last) {
				last = last->getNext();
			}
			first = first->getNext();
			delete temp;
		}
		--count;
	}

	virtual void removeLast() {
		if (first == last) {
			delete first;
			first = last = nullptr;
		}
		else if (first->getNext() == last) {
			first->setNext(nullptr);
			delete last;
			last = first;
		}
		else
		{
			auto ptr = first;
			while (ptr->getNext()->getNext()) {
				ptr = ptr->getNext();
			}
			delete last;
			ptr->setNext(nullptr);
			last = ptr;
		}
		--count;
	}

	// Other methods.
	virtual bool empty() const override {
		return count == 0;
	}

	virtual void print(std::ostream& os) const override {
		for (Node<T>* pt = first; pt != nullptr; pt = pt->getNext()) {
			os << pt->getValue() << ' ';
		}
		os << std::endl;
	}

	virtual ~SimpleList() {
		// Free allocated memory.
		while (first != nullptr) {
			Node<T>* temp = first;
			first = first->getNext();
			delete temp;
		}
	}
};