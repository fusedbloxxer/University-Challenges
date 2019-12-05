#pragma once
#include "Stack.h"

template<typename T>
class Queue : public Container<T>
{
	Stack<T> stack1;
	Stack<T> stack2;

public:
	Queue();

	virtual T pop() override;
	virtual bool empty() const override;
	virtual void push(const T& value) override;

	virtual ~Queue();
};

template<typename T>
inline Queue<T>::Queue()
	:stack1{}, stack2{}
{
}

template<typename T>
inline T Queue<T>::pop()
{
	if (!stack2.empty())
	{
		return stack2.pop();
	}
	
	while (!stack1.empty())
	{
		stack2.push(stack1.pop());
	}

	return stack2.pop();
}

template<typename T>
inline bool Queue<T>::empty() const
{
	return stack1.empty() && stack2.empty();
}

template<typename T>
inline void Queue<T>::push(const T& value)
{
	stack1.push(value);
}

template<typename T>
inline Queue<T>::~Queue()
{
}
