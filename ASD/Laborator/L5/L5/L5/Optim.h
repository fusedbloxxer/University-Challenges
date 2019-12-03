#pragma once
#include "InsertionSort.h"

template<typename T, typename SecondStrategy = InsertionSort<T>>
class Optim : public virtual SortStrategy<T>
{
protected:
	int seqLen;
	SecondStrategy strategy;

public:
	Optim(int seqLen = 10);
	virtual ~Optim() = 0;
	
	// Getters and setters
	void setSeq(int len);
	int getSeq() const;
};

template<typename T, typename SecondStrategy>
inline Optim<T, SecondStrategy>::Optim(int seqLen)
	:strategy{}, seqLen{ seqLen } {}

template<typename T, typename SecondStrategy>
inline Optim<T, SecondStrategy>::~Optim() {}

template<typename T, typename SecondStrategy>
inline void Optim<T, SecondStrategy>::setSeq(int len)
{
	this->seqLen;
}

template<typename T, typename SecondStrategy>
inline int Optim<T, SecondStrategy>::getSeq() const
{
	return seqLen;
}

/*

	-> Optim
	if (seq)
	{
		sorteaza cu metoda specificata
	}
	else 
	{
		Divide
	}

*/

//
// 
// 