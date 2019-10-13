#pragma once

// Interfata pentru exercitiile 1 - 4
/*
1. Se da o lista simplu inlantuita. Stergeti al k-lea element de la fnal (cu O(1) memorie).

2. Se da o lista simplu inlantuita. Inversati lista (complexitate O(n) timp, O(1) memorie).

3. Se da o lista simplu inlantuita. Gasiti un algoritm de complexitate liniara care afseaza
daca acea lista este palindromica.

4. Implementati o structura de date care poate raspunde rapid la urmatoarele query-uri:
	• inserare element la fnal
	• stergere element de la fnal
	• afsare element maxim
*/
template<class T>
class List
{
public:
	// Add operations - Make a copy and insert it.
	virtual void addFirst(const T& element) = 0;
	virtual void addLast(const T& element) = 0;

	// Check if the list is a palindrome.
	virtual bool isPalindrome() = 0;

	// Remove operations.
	virtual void removeFirst() = 0;
	virtual void removeLast() = 0;
	virtual void removeKth() = 0;

	// Reverse the list.
	virtual void reverse() = 0;

	// Return the value of the maximum element.
	virtual T getMax() = 0;

	// Destructor.
	virtual ~List() = default;
};

