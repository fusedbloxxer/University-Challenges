#pragma once
#include <stdexcept>
#include "Container.h"

template<typename T = int>
class Heap : public Container<T>
{
	// Dynamic sized-array
	T** ptrs; int index, size;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Heap<U>& heap);

public:
	enum Type { MAX = -1, MIN = 1 } type;

	Heap(Type type = Type::MIN);

	T find();
	virtual T pop() override;
	virtual bool empty() const override;
	void push(T& value);
	virtual void push(const T& value) override;

	virtual ~Heap();

private:
	// Memory management:
	void increase();
	void decrease();

	// Heap movement:
	void shiftUp(int k);
	void shiftDown(int k);

	// Comparison
	bool compare(const T* a, const T* b) const;

	int get(const int posA, const int posB) const;
};

template<typename T>
inline Heap<T>::Heap(Type type)
	:type{ type }, size{ 0 }, index{ 0 }, ptrs{ nullptr } {}

template<typename T>
inline void Heap<T>::push(const T& element)
{
	increase();
	ptrs[index] = new T(element);
	shiftUp(index);
	++index;
}

template<typename T>
inline T Heap<T>::find()
{
	if (index <= 0)
	{
		throw std::runtime_error{ "No elements available." };
	}
	return **ptrs;
}

template<typename T>
inline T Heap<T>::pop()
{
	if (index <= 0)
	{
		throw std::runtime_error{ "No elements to pop." };
	}
	else if (index == 1)
	{
		--index;
		delete ptrs[index];
	}
	else
	{
		T* temp = ptrs[0];
		ptrs[0] = ptrs[--index];
		delete temp;

		shiftDown(0);
	}

	decrease();
}

template<typename T>
inline bool Heap<T>::empty() const
{
	return index == 0;
}

template<typename T>
inline Heap<T>::~Heap()
{
	for (int i = 0; i < index; ++i)
	{
		delete ptrs[i];
	}
	delete[] ptrs;
}

template<typename T>
inline void Heap<T>::shiftUp(int k)
{
	if (k != 0)
	{
		int parent = (k - 1) / 2;

		if (compare(ptrs[k], ptrs[parent]))
		{
			// Swap pointers
			T* aux = ptrs[k];
			ptrs[k] = ptrs[parent];
			ptrs[parent] = aux;

			// Repeat
			shiftUp(parent);
		}
	}
}

template<typename T>
inline void Heap<T>::shiftDown(int k)
{
	if (int first = 2 * k + 1; first < index)
	{
		int pos = get(k, first);

		if (int second = 2 * k + 2; second < index)
		{
			pos = get(k, second);
		}

		if (pos != k)
		{
			T* aux = ptrs[k];
			ptrs[k] = ptrs[pos];
			ptrs[pos] = aux;

			shiftDown(pos);
		}
	}
}

template<typename T>
inline bool Heap<T>::compare(const T* a, const T* b) const
{
	return (*a < *b && type == Type::MIN)
		|| (*a > * b && type == Type::MAX);
}

template<typename T>
inline int Heap<T>::get(const int posA, const int posB) const
{
	if (compare(ptrs[posA], ptrs[posB]))
		return posA;
	return posB;
}

template<typename T>
inline void Heap<T>::increase()
{
	if (index == size)
	{
		if (index == 0)
		{
			++size;
		}
		else
		{
			size *= 2;
		}

		// Copy operation into new array;
		T** temporary = new T * [size];

		for (int i = 0; i < index; ++i)
		{
			temporary[i] = ptrs[i];
		}

		delete[] ptrs;

		ptrs = temporary;
	}
}

template<typename T>
inline void Heap<T>::decrease()
{
	if (index < 0.25 * size)
	{
		size /= 2;

		// Copy operation into new array;
		T** temporary = new T * [size];

		for (int i = 0; i < index; ++i)
		{
			temporary[i] = ptrs[i];
		}

		delete[] ptrs;

		ptrs = temporary;
	}
}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, const Heap<U>& heap)
{
	for (int i = 0; i < heap.index; ++i)
	{
		os << *(heap.ptrs[i]) << ' ';
	}
	return os;
}