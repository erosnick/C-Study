#pragma once

#include "DataType.h"

template <typename T>
class LinkedList
{
public:

	LinkedList()
	{
		Head = new Node<T>();
		Tail = Head->NextNode;
		Cursor = Head;

		NodeCount = 0;
	}

	~LinkedList()
	{
		Node<T>* CurrentNode = Head->NextNode;

		while (CurrentNode != nullptr)
		{
			Head = CurrentNode->NextNode;

			delete CurrentNode;

			CurrentNode = Head;
		}
	}

	void Insert(int Position, T Value)
	{
		if (Position >= 0 && Position <= (NodeCount - 1))
		{
			Node<T>* Temp = Head;

			for (int i = 1; i <= Position; i++)
			{
				Temp = Temp->NextNode;
			}

			Node<T>* NewNode = new Node<T>();
			NewNode->Value = Value;
			NewNode->NextNode = Temp->NextNode;
			Temp->NextNode = NewNode;
		}
	}

	void Delete(T Value)
	{
		Node<T>* PreNode = Head;
		Node<T>* Temp = Head->NextNode;

		while (Temp != nullptr)
		{
			if (Temp->Value == Value)
			{
				PreNode->NextNode = Temp->NextNode;

				delete Temp;

				break;
			}

			Temp = Temp->NextNode;
			PreNode = PreNode->NextNode;
		}

		NodeCount--;
	}

	void DeleteAt(int Position)
	{
		int Index = 0;

		Node<T>* PreNode = Head;
		Node<T>* Temp = Head->NextNode;

		while (Temp != nullptr)
		{
			if (Index == Position)
			{
				PreNode->NextNode = Temp->NextNode;

				delete Temp;

				break;
			}

			PreNode = PreNode->NextNode;
			Temp = Temp->NextNode;
			Index++;
		}

		NodeCount--;
	}

	void Append(T Value)
	{
		if (Head->NextNode == nullptr)
		{
			Node<T>* NewNode = new Node<T>();

			NewNode->Value = Value;

			Head->NextNode = NewNode;

			NewNode->NextNode = Tail;

			Last = NewNode;

			NodeCount++;

			return;
		}

		Last->NextNode = new Node<T>();
		Last->NextNode->Value = Value;
		Last = Last->NextNode;
		Tail = Last->NextNode;

		NodeCount++;
	}

	T Next()
	{
		T Value = 0;

		if (Cursor->NextNode != nullptr)
		{
			Value = Cursor->NextNode->Value;

			Cursor = Cursor->NextNode;
		}

		return Value;
	}

	T operator[](int Index)
	{
		int Counter = 0;

		while (Cursor->NextNode != nullptr)
		{
			if (Counter == Index)
			{
				T Value = Cursor->NextNode->Value;
				Reset();
				return Value;
			}

			Cursor = Cursor->NextNode;
			Counter++;
		}

		Reset();

		return T();
	}

	void Reset()
	{
		Cursor = Head;
	}

	int Length() const
	{
		return NodeCount;
	}

	bool Empty() const
	{
		return NodeCount > 0;
	}

	void Print()
	{
		Node<T>* CurrentNode;

		CurrentNode = Head->NextNode;

		while (CurrentNode != nullptr)
		{
			std::cout << CurrentNode->Value << std::endl;

			CurrentNode = CurrentNode->NextNode;
		}
	}

private:

	Node<T>* Head;
	Node<T>* Tail;
	Node<T>* Last;
	Node<T>* Cursor;

	int NodeCount;
};

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