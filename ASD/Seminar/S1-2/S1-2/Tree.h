#pragma once

template<class T>
class Tree
{
public:
	virtual void add(T element) = 0;
	virtual T find(T element) = 0;

	virtual void BFS() const = 0;
	virtual void DFS() const = 0;
	
	virtual void SRD() = 0;
	virtual void RSD() = 0;
	virtual void SDR() = 0;

	virtual bool empty() const = 0;

	virtual ~Tree() = default;
};

