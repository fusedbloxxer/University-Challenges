#pragma once
#include "Vector.h"
#include "PureImag_I.h"

template<typename T = float>
class Stiva : public Vector<Complex<T>>, public PureImag_I
{
	using Type = Complex<T>;
public:
	// Standard
	Stiva();
	Stiva(int dim, Type* v);
	Stiva(const Stiva& copy);
	Stiva(Stiva&& move) noexcept;
	Stiva<T>& operator=(const Stiva& copy);
	Stiva<T>& operator=(Stiva&& move) noexcept;
	virtual ~Stiva() = default;

	// Inherited from PureImag_I
	virtual bool isPure() const override;

	// Inherited from Vector
	virtual Stiva<T>::Type pop() override;
	virtual void push(Stiva<T>::Type element) override;
};

template<typename T>
inline Stiva<T>::Stiva()
	:Vector<Type>{}
{
}

template<typename T>
inline Stiva<T>::Stiva(int dim, Type* v)
	: Vector<Type>{ dim, v }
{
}

template<typename T>
inline Stiva<T>::Stiva(const Stiva& copy)
	: Vector<Type>{ copy }
{
}

template<typename T>
inline Stiva<T>::Stiva(Stiva&& move) noexcept
	:Vector<Type>{ std::move(move) }
{
}

template<typename T>
inline Stiva<T>& Stiva<T>::operator=(const Stiva& copy)
{
	if (this == &copy) {
		return *this;
	}

	Vector<Type>::operator=(copy);

	return *this;
}

template<typename T>
inline Stiva<T>& Stiva<T>::operator=(Stiva&& move) noexcept
{
	if (this == &move) {
		return *this;
	}

	Vector<Type>::operator=(std::move(move));

	return *this;
}

template<typename T>
inline bool Stiva<T>::isPure() const
{
	for (int i = 0; i < Vector<Type>::size; ++i) {
		if (Vector<Type>::v[i].getReal() != decltype(Vector<Type>::v[i].getReal())()) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline Complex<T> Stiva<T>::pop()
{
	if (Vector<Type>::size <= 0) {
		throw PopException{};
	}

	Stiva<T>::Type copy = Vector<Type>::v[0];

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
inline void Stiva<T>::push(Type element)
{
	Type* temp = new Type[Vector<Type>::size + 1];
	for (int i = 0; i < Vector<Type>::size; ++i) {
		temp[i + 1] = Vector<Type>::v[i];
	}

	temp[0] = element;

	delete[] Vector<Type>::v;

	Vector<Type>::v = temp;
	
	++Vector<Type>::size;
}