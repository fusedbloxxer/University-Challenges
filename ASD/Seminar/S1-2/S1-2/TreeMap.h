#pragma once
#include "Tree.h"
#include "TreeNode.h"
#include "SimpleList.h"

template<class T>
class TreeMap : public Tree<T>
{
private:
	std::unique_ptr<TreeNode<T>> root;
	size_t count;
public:
	TreeMap()
		:root{ nullptr }, count{ 0 } {}

	~TreeMap() = default;

	// Inherited via Tree<T>
	virtual void add(T element) {
		if (!root)
		{
			root = std::unique_ptr<TreeNode<T>>(new TreeNode<T>{ element });
		}
		else
		{
			add(element, root.get());
		}
		++count;
	}

private:
	void add(T element, TreeNode<T>* node)
	{
		if (element < node->getValue())
		{
			if (node->getFirst()) {
				add(element, node->getFirst());
			}
			else
			{
				node->setFirst(new TreeNode<T>{ element });
			}
		}
		else
		{
			if (node->getSecond()) {
				add(element, node->getSecond());
			}
			else
			{
				node->setSecond(new TreeNode<T>{ element });
			}
		}
	}

	void rsd(TreeNode<T>* ptr)
	{
		std::cout << ptr->getValue() << ' ';

		if (ptr->getFirst()) {
			rsd(ptr->getFirst());
		}

		if (ptr->getSecond()) {
			rsd(ptr->getSecond());
		}
	}

	void srd(TreeNode<T>* ptr)
	{
		if (ptr->getFirst()) {
			srd(ptr->getFirst());
		}

		std::cout << ptr->getValue() << ' ';

		if (ptr->getSecond()) {
			srd(ptr->getSecond());
		}
	}

	void sdr(TreeNode<T>* ptr)
	{
		if (ptr->getFirst()) {
			sdr(ptr->getFirst());
		}

		if (ptr->getSecond()) {
			sdr(ptr->getSecond());
		}

		std::cout << ptr->getValue() << ' ';
	}

	T search(T element, TreeNode<T>* node) {
		if (node) {
			if (element < node->getValue()) {
				search(element, node->getFirst());
			}
			else if (element > node->getValue()) {
				search(element, node->getSecond());
			}
			else {
				return node->getValue();
			}
		}
	}

public:

	virtual T find(T element) {
		return search(element, root.get());
	}

	// Use a queue
	virtual void BFS() const override {
		List<TreeNode<T>*>* list = new SimpleList<TreeNode<T>*>();
		list->addFirst(root.get());

		while (!list->empty())
		{
			std::cout << list->front()->getValue() << ' ';

			if (list->front()->getFirst()) {
				list->addLast(list->front()->getFirst());
			}

			if (list->front()->getSecond()) {
				list->addLast(list->front()->getSecond());
			}

			list->removeFirst();
		}

		delete list;
	}

	// Use a stack - Fix this.
	virtual void DFS() const override {
		SimpleList<TreeNode<T>*> list = SimpleList<TreeNode<T>*>();
		list.addFirst(root.get());

		while (!list.empty())
		{
			std::cout << list.front()->getValue() << ' ';

			if (list.front()->getFirst()) {
				list.addFirst(list.front()->getFirst());
			}

			if (list.front()->getSecond()) {
				list.addFirst(list.front()->getSecond());
			}

			list.removeLast();
		}
	}

	virtual void SRD() override {
		srd(root.get());
	}

	virtual void RSD() override {
		rsd(root.get());
	}

	virtual void SDR() override {
		sdr(root.get());
	}

	bool empty() const {
		return count;
	}
};

