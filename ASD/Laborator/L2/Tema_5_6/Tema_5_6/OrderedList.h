#pragma once
#include "SimpleList.h"

template<class T>
class OrderedList : private SimpleList<T>
{
public:
	using SimpleList<T>::sz;
	using SimpleList<T>::head;
	using SimpleList<T>::clean;
	using SimpleList<T>::findByValue;
	using SimpleList<T>::findByPos;
	using SimpleList<T>::removeLast;
	using SimpleList<T>::removeFirst;
	using SimpleList<T>::removeByPos;
	using SimpleList<T>::removeByValue;

	void add(const T& element);
	void print();
	void read();
};

template<class T>
inline void OrderedList<T>::add(const T& element)
{
	if (!head) {
		SimpleList<T>::addFirst(element);
	}
	else {
		if (element < head->getValue()) {
			SimpleList<T>::addFirst(element);
		}
		else {
			for (auto var = head; var->getNext(); var = var->getNext()) {
				if (element < var->getNext()->getValue()) {
					var->setNext(new SimpleNode<T>{ element, var->getNext() });
					++sz;
					return;
				}
			}
			SimpleList<T>::addLast(element);
		}
	}
}

template<class T>
inline void OrderedList<T>::print()
{
	SimpleList<T>::print(std::cout);
}

template<class T>
inline void OrderedList<T>::read()
{
	clean();
	std::cout << "Enter number of elements: ";
	decltype(sz) temp; std::cin >> temp; T element;

	for (decltype(sz) i{ 0 }; i < temp; ++i) {
		std::cin >> element;
		add(element);
	}
}
