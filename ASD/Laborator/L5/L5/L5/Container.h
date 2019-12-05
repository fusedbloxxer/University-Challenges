#pragma once

template<typename T>
class Container
{
public:
	virtual T pop() = 0;
	virtual bool empty() const = 0;
	virtual void push(const T& value) = 0;

	virtual ~Container() = default;
};