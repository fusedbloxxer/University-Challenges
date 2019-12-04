#pragma once
#include <stdexcept>

template<typename T = int>
class Heap
{
	// Dynamic sized-array
	enum Type { MAX = -1, MIN = 1 } type;
	T** ptrs; int index, size;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Heap<U>& heap);

public:
	Heap(Type type = Type::MIN);

	void pop();
	T find() const;
	void insert(T& element);
	void insert(T&& element);

	virtual ~Heap();

private:
	// Memory management:
	void increase();
	void decrease();

	// Heap movement:
	void shiftUp(int k);
	void shiftDown(int k);

	T* get(T* a, T* b) const;
};

template<typename T>
inline Heap<T>::Heap(Type type)
	:type{ type }, size{ 0 }, index{ 0 }, ptrs{ nullptr } {}

template<typename T>
inline T Heap<T>::find() const
{
	if (index <= 0)
	{
		throw std::runtime_error{ "No elements available." };
	}
	return **ptrs;

}

template<typename T>
inline void Heap<T>::insert(T& element)
{
	increase();

	ptrs[index] = &element;
	shiftUp(index);
	++index;
}

template<typename T>
inline void Heap<T>::insert(T&& element)
{
	increase();

	ptrs[index] = &element;
	shiftUp(index);
	++index;
}

template<typename T>
inline void Heap<T>::pop()
{
	if (index <= 0)
	{
		throw std::runtime_error{ "No elements to pop." };
	}
	else if (index == 1)
	{
		--index;
	}
	else
	{
		ptrs[0] = ptrs[--index];
		shiftDown(0);
	}

	decrease();
}

template<typename T>
inline Heap<T>::~Heap()
{
	delete[] ptrs;
}

template<typename T>
inline void Heap<T>::shiftUp(int k)
{
	if (k != 0)
	{
		int parent = (k - 1) / 2;

		if ((*ptrs[k] - *ptrs[parent]) * type < 0)
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
}

template<typename T>
inline T* Heap<T>::get(T* a, T* b) const
{
	if ((*a - *b) * type < 0)
	{
		return a;
	}
	{
		return b;
	}
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
	/*
	if (index < 0.2 * size)
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
	*/
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
