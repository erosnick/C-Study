#pragma once

#include "DataType.h"

template <typename T>
class Stack
{
public:

	Stack()
	{
		TopNode = nullptr;
		StackSize = 0;
	}

	~Stack()
	{
		while (!Empty())
		{
			Pop();
		}
	}

	void Push(const T& InValue)
	{
		if (TopNode == nullptr)
		{
			TopNode = new Node<T>();

			TopNode->Value = InValue;
		}
		else
		{
			auto NewNode = new Node<T>();

			NewNode->Next = TopNode;

			TopNode = NewNode;

			TopNode->Value = InValue;
		}

		StackSize++;
	}

	T Pop()
	{
		if (TopNode != nullptr)
		{
			auto PopValue = TopNode->Value;

			auto TempNode = TopNode;

			TopNode = TopNode->Next;

			delete TempNode;

			StackSize--;

			return PopValue;
		}

		return -1;
	}

	T Top() const
	{
		if (Empty())
		{
			throw std::runtime_error("Stack is empty.");
		}

		return TopNode->Value;
	}

	int Size()
	{
		return StackSize;
	}

	bool Empty() const
	{
		return StackSize == 0;
	}

private:

	Node<T>* TopNode;

	int StackSize;
};

