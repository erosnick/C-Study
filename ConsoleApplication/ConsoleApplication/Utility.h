#pragma once

#include <vector>

template <typename T>
T BinarySearch(const std::vector<T>& Array, T Find)
{
	auto Size = Array.size();

	auto Index = Size / 2;

	auto Counter = 0;

	while (Index != -1)
	{
		Counter++;

		auto Value = Array[Index];

		if (Value == Find)
		{
			std::cout << "Search Times: " << Counter << std::endl;

			return Index;
		}
		else
		{
			if (Value > Find)
			{
				Index = Index / 2;
			}
			else
			{
				Index = (Index + Size) / 2;
			}
		}
	}

	return -1;
}

template <typename T>
struct Node
{
	Node()
	{
		Value = 0;
		NextNode = nullptr;
	}

	T Value;
	Node* NextNode;
};

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

	void Push(T InValue)
	{
		if (TopNode == nullptr)
		{
			TopNode = new Node<T>();

			TopNode->Value = InValue;
		}
		else
		{
			auto NewNode = new Node<T>();

			NewNode->NextNode = TopNode;

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

			TopNode = TopNode->NextNode;

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
		return StackSize > 0;
	}

private:

	Node<T>* TopNode;

	int StackSize;
};