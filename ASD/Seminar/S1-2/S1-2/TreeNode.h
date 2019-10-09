#pragma once
#include <memory>

template<class T>
class TreeNode
{
private:
	std::unique_ptr<T> ptr;
	std::unique_ptr<TreeNode<T>> first, second;
public:
	TreeNode(T value, TreeNode<T>* first = nullptr, TreeNode<T>* second = nullptr)
		:ptr{ new T{value} }, first{ first }, second{ second } {}

	T& getValue() const {
		return *ptr;
	}

	void setFirst(TreeNode<T>* ptr) {
		first = std::unique_ptr<TreeNode<T>>(ptr);
	}

	void setSecond(TreeNode<T>* ptr) {
		second = std::unique_ptr<TreeNode<T>>(ptr);
	}

	TreeNode<T>* getFirst() const {
		return first.get();
	}

	TreeNode<T>* getSecond() const {
		return second.get();
	}

	~TreeNode() = default;
};

