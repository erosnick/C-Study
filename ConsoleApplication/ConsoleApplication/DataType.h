#pragma once

template <typename T>
struct Node
{
	Node()
	{
		Next = nullptr;
		Prior = nullptr;
	}

	T Value;
	Node* Next;
	Node* Prior;
};

template <typename T>
struct BTNode
{
	BTNode()
	{
		LeftChild = nullptr;
		RightChild = nullptr;
		LeftTag = Link;
		RightTag = Link;
	}

	enum PointerTag { Link, Thread };

	T Data;
	BTNode<T>* LeftChild;
	BTNode<T>* RightChild;
	PointerTag LeftTag;
	PointerTag RightTag;
};