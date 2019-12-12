#pragma once
#include "PureImag_I.h"
#include "Vector.h"

template<typename T = float>
class Queue : public Vector<Complex<T>>,public PureImag_I
{
	using Type = Complex<T>;
public:
	// Standard
	Queue();
	Queue(int dim, Type* v);
	Queue(const Queue& copy);
	Queue(Queue&& move) noexcept;
	Queue<T>& operator=(const Queue& copy);
	Queue<T>& operator=(Queue&& move) noexcept;
	virtual ~Queue() = default;

	// Inherited from PureImag_I
	virtual bool isPure() const override;

	// Inherited from Vector
	virtual Queue<T>::Type pop() override;
	virtual void push(Queue<T>::Type element) override;
};

template<typename T>
inline Queue<T>::Queue()
	:Vector<Type>{}
{
}

template<typename T>
inline Queue<T>::Queue(int dim, Type* v)
	: Vector<Type>{ dim, v }
{
}

template<typename T>
inline Queue<T>::Queue(const Queue& copy)
	: Vector<Type>{ copy }
{
}

template<typename T>
inline Queue<T>::Queue(Queue&& move) noexcept
	:Vector<Type>{ std::move(move) }
{
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& copy)
{
	if (this == &copy) {
		return *this;
	}

	Vector<Type>::operator=(copy);

	return *this;
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(Queue&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	Vector<Type>::operator=(std::move(move));

	return *this;
}

template<typename T>
inline bool Queue<T>::isPure() const
{
	for (int i = 0; i < Vector<Type>::size; ++i) {
		if (Vector<Type>::v[i].getReal() != decltype(Vector<Type>::v[i].getReal())()) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline Complex<T> Queue<T>::pop()
{
	if (Vector<Type>::size <= 0) {
		throw PopException{};
	}

	Queue<T>::Type copy = Vector<Type>::v[0];

	Type* temp = new Type[Vector<Type>::size - 1];

	for (int i = 1; i < Vector<Type>::size; ++i) {
		temp[i - 1] = Vector<Type>::v[i];
	}

	delete[] Vector<Type>::v;
	Vector<Type>::v = temp;
	--Vector<Type>::size;

	return copy;
}

template<typename T>
inline void Queue<T>::push(Queue<T>::Type element)
{
	// Allocate more memory.
	Type* temp = new Type[Vector<Type>::size + 1];

	// Copy the content.
	for (int i = 0; i < Vector<Type>::size; ++i) {
		temp[i] = Vector<Type>::v[i];
	}

	// Insert the new element.
	temp[Vector<Type>::size++] = element;

	// Free old memory.
	delete[] Vector<Type>::v;

	// Retain a pointer to the new array.
	Vector<Type>::v = temp;
}
