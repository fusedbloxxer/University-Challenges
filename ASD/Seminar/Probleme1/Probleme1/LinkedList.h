#pragma once
#include "List.h"
#include "SimpleNode.h"

template<class T>
class LinkedList : public List<T>
{
	SimpleNode<T>* first, last, pre, max;
public:
	LinkedList()
		:first{ nullptr }, last{ nullptr }, pre{ nullptr }, max{ nullptr };

	virtual void addFirst(const T& element) override;
	virtual void addLast(const T& element) override;

	virtual void removeFirst() override;
	virtual T getMax() override;

	virtual ~LinkedList() {
		if (first) {
			SimpleNode<T>* temp;
			while (first) {
				temp = first;
				first = first->getNext();
				delete temp;
			}
		}
	}
private:
	void findMax();
};

template<class T>
void LinkedList<T>::addFirst(const T& element)
{
	if (!first) {
		max = last = first = new SimpleNode<T>{ element };
	}
	else {
		first = new SimpleNode<T>{ element, first };
		if (max->getValue() < first->getValue()) {
			max = first;
		}
		if (first->getNext() == last) {
			pre = first;
		}
	}
}

template<class T>
void LinkedList<T>::addLast(const T& element)
{
	if (!first) {
		max = last = first = new SimpleNode<T>{ element };
	}
	else {
		last->next = new SimpleNode<T>{ element };
		pre = last;
		last = last->getNext();
		if (max->getValue() < last->getValue()) {
			max = last;
		}
	}
}

template<class T>
inline void LinkedList<T>::removeFirst()
{
	if (!first) {
		// Do nothing.
	}
	else if (first == last) {
		delete first;
		first = last = max = nullptr;
	}
	else {
		SimpleNode<T>* temp = first;
		first = first->getNext();
		delete temp;

		// Case 1: = 2 elements
		if (first == last) {

		}
		// Case 2: > 2 elements
	}
}

template<class T>
inline T LinkedList<T>::getMax()
{
	if (max) {
		return max->getValue();
	}
	if (first) {
		findMax();
		return *max;
	}
	throw std::exception{ "No max was found." };
}

template<class T>
inline void LinkedList<T>::findMax()
{
	max = first;
	for (SimpleNode<T>* temp = first->getNext(); temp; temp = temp->getNext()) {
		if (max->getValue() < temp->getValue()) {
			max = temp;
		}
	}
}