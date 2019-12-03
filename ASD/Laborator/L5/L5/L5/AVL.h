#pragma once
#include "DoubleNode.h"
#include "Stack.h"

template<typename T>
class DoubleNode;

template<typename T = int>
class AVL
{
	DoubleNode<T>* root;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const AVL<U>& avl);
	template<typename U>
	friend std::istream& operator>>(std::istream& is, AVL<U>& avl);

public:
	AVL();

	AVL(const AVL& copy) = delete;
	AVL(AVL&& move) noexcept = delete;
	AVL<T>& operator=(const AVL& copy) = delete;
	AVL<T>& operator=(AVL&& move) = delete;

	void add(const T& value);
	void rsd(std::ostream& os = std::cout);
	void srd(std::ostream& os = std::cout);
	void drs(std::ostream& os = std::cout);

	virtual ~AVL();

private:
	bool dsi(int a, int b) const;
	int update(DoubleNode<T>* node);
	void rightToLeft(DoubleNode<T>*& ptr);
	void leftToRight(DoubleNode<T>*& ptr);
	void add(DoubleNode<T>*& node, const T& value);
	void rsd(const DoubleNode<T>* node, std::ostream& os = std::cout);
	void srd(const DoubleNode<T>* node, std::ostream& os = std::cout);
	void drs(const DoubleNode<T>* node, std::ostream& os = std::cout);
};

template<typename T>
inline AVL<T>::AVL()
	:root{ nullptr }
{
}

template<typename T>
inline void AVL<T>::add(const T& value)
{
	add(root, value);
}

template<typename T>
inline void AVL<T>::rsd(std::ostream& os)
{
	rsd(root);
}

template<typename T>
inline void AVL<T>::srd(std::ostream& os)
{
	srd(root);
}

template<typename T>
inline void AVL<T>::drs(std::ostream& os)
{
	drs(root, os);
}

template<typename T>
inline AVL<T>::~AVL()
{
	Stack<DoubleNode<T>*> stack;

	if (root)
	{
		stack.push(root);

		while (!stack.empty())
		{
			DoubleNode<T>* temp = stack.pop();

			if (temp->left)
			{
				stack.push(temp->left);
			}

			if (temp->right)
			{
				stack.push(temp->right);
			}

			delete temp;
		}
	}
}

template<typename T>
inline bool AVL<T>::dsi(int a, int b) const
{
	return a * b < 0;
}

template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
inline int AVL<T>::update(DoubleNode<T>* node)
{
	if (node != nullptr)
	{
		int left = update(node->left);
		int right = update(node->right);
		node->bal = left - right;

		return max(left, right) + 1;
	}
	else
	{
		return 0;
	}
}

template<typename T>
inline void AVL<T>::add(DoubleNode<T>*& node, const T& value)
{
	if (node == nullptr)
	{
		node = new DoubleNode{ value };
	}
	else if (value < node->value)
	{
		++node->bal;

		if (node->left)
		{
			add(node->left, value);
		}
		else
		{
			node->left = new DoubleNode{ value };
		}

		// The node was inserted
		if (abs(node->bal) > 1)
		{
			if (dsi(node->bal, node->left->bal))
			{
				// Double rotation: RIGHT-LEFT on t, LEFT-RIGHT on b 
				//      b			 b       n
				//     / \			/ \     / \
				//    t   O		  n    O   t    b
				//   / \         / \      / \  / \
				//  O   n       t   O    O   O O  O
				//     / \     / \
				//    O   O   O   O

				rightToLeft(node->left);
				leftToRight(node);
			}
			else
			{
				// Simple rotation: LEFT-RIGHT on t 
				//    	  b        t
				//    	 / \      / \
				//      t   O    n    b
				//     / \      / \  / \
				//    n   O    O  O  O  O
				//   / \
				//  O   O

				leftToRight(node->left);
			}
		}
	}
	else
	{
		--node->bal;

		if (node->right)
		{
			add(node->right, value);
		}
		else
		{
			node->right = new DoubleNode{ value };
		}

		// The node was inserted
		if (abs(node->bal) > 1)
		{
			if (dsi(node->bal, node->right->bal))
			{
				// Double rotation: LEFT-RIGHT on t, RIGHT-LEFT on b 
				//    b         b                n   
				//   / \       /  \            /   \
				//  O   t     O    n          b     t
				//     /  \      /  \        / \   / \
				//    n    O    O     t     O   O O   O
				//   /  \            / \
				//  O    O          O   O

				leftToRight(node->right);
				rightToLeft(node);
			}
			else
			{
				// Simple rotation: RIGHT-LEFT on t
				//      b                 t   
				//     /  \             /   \
				//    O    t           b     n
				//        /  \        / \   / \
				//       O     n     O   O O   O
				//            / \
				//           O   O

				rightToLeft(node);
			}
		}
	}
}

template<typename T>
inline void AVL<T>::rightToLeft(DoubleNode<T>*& ptr)
{
	// Simple rotation: RIGHT-LEFT on b
	//      b                 t   
	//     /  \             /   \
	//    O    t           b     n
	//        /  \        / \   / \
	//       O     n     O   O O   O
	//            / \
	//           O   O

	// Change links
	DoubleNode<T>* t = ptr->right;
	ptr->right = t->left;
	t->left = ptr;

	// Change heights
	ptr->bal = ptr->bal + (1 - (t->bal < 0 ? t->bal : 0));
	t->bal = t->bal + (1 - (ptr->bal > 0 ? ptr->bal : 0));

	// New "root"
	ptr = t;
}

template<typename T>
inline void AVL<T>::leftToRight(DoubleNode<T>*& ptr)
{
	// Simple rotation: LEFT-RIGHT on b 
	//    	  b        t
	//    	 / \      / \
	//      t   O    n    b
	//     / \      / \  / \
	//    n   O    O  O  O  O
	//   / \
	//  O   O

	// Change links
	DoubleNode<T>* t = ptr->left;
	ptr->left = t->right;
	t->right = ptr;

	// Change heights
	ptr->bal = ptr->bal - (1 + (t->bal > 0 ? t->bal : 0));
	t->bal = t->bal - (1 - (ptr->bal < 0 ? ptr->bal : 0));

	// Change "root"
	ptr = t;
}

template<typename T>
inline void AVL<T>::rsd(const DoubleNode<T>* node, std::ostream& os)
{
	if (node)
	{
		os << *node << ' ';
		rsd(node->left, os);
		rsd(node->right, os);
	}
}

template<typename T>
inline void AVL<T>::srd(const DoubleNode<T>* node, std::ostream& os)
{
	if (node)
	{
		srd(node->left, os);
		os << *node << ' ';
		srd(node->right, os);
	}
}

template<typename T>
inline void AVL<T>::drs(const DoubleNode<T>* node, std::ostream& os)
{
	if (node)
	{
		drs(node->right, os);
		os << node->value << ' ';
		drs(node->left, os);
	}
}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, const AVL<U>& avl)
{
	Stack<DoubleNode<U>*> stack;

	if (avl.root)
	{
		stack.push(avl.root);

		while (!stack.empty())
		{
			DoubleNode<U>* temporary = stack.pop();

			os << *temporary << ' ';

			if (temporary->getRight())
			{
				stack.push(temporary->getRight());
			}

			if (temporary->getLeft())
			{
				stack.push(temporary->getLeft());
			}
		}
	}

	return os;
}

template<typename U>
inline std::istream& operator>>(std::istream& is, AVL<U>& avl)
{
	U temp; is >> temp;
	avl.add(temp);
	return is;
}