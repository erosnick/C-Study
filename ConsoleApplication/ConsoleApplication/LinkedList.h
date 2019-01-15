#pragma once

#include "DataType.h"

template <typename T>
class LinkedList
{
public:

	LinkedList()
	{
		Head = new Node<T>();
		Cursor = Head;
		Last = nullptr;
		NodeCount = 0;
	}

	~LinkedList()
	{
		Node<T>* CurrentNode = nullptr;

		while (Head != nullptr)
		{
			Cursor = Head;

			Head = Head->Next;

			delete Cursor;
		}
	}

	void Insert(int Position, T Value)
	{
		if (Position >= 0 && Position <= (NodeCount - 1))
		{
			Node<T>* Temp = Head;

			for (int i = 1; i <= Position; i++)
			{
				Temp = Temp->Next;
			}

			Node<T>* NewNode = new Node<T>();
			NewNode->Value = Value;
			NewNode->Next = Temp->Next;
			Temp->Next = NewNode;
		}
	}

	void Delete(T Value)
	{
		Node<T>* PreNode = Head;
		Node<T>* Temp = Head->Next;

		while (Temp != nullptr)
		{
			if (Temp->Value == Value)
			{
				PreNode->Next = Temp->Next;

				delete Temp;

				break;
			}

			Temp = Temp->Next;
			PreNode = PreNode->Next;
		}

		NodeCount--;
	}

	void DeleteAt(int Position)
	{
		int Index = 0;

		Node<T>* PreNode = Head;
		Node<T>* Temp = Head->Next;

		while (Temp != nullptr)
		{
			if (Index == Position)
			{
				PreNode->Next = Temp->Next;

				delete Temp;

				break;
			}

			PreNode = PreNode->Next;
			Temp = Temp->Next;
			Index++;
		}

		NodeCount--;
	}

	void Append(T Value)
	{
		if (Head->Next == nullptr)
		{
			Node<T>* NewNode = new Node<T>();

			NewNode->Value = Value;

			Head->Next = NewNode;

			Last = NewNode;

			NodeCount++;

			return;
		}

		Last->Next = new Node<T>();
		Last->Next->Value = Value;
		Last = Last->Next;

		NodeCount++;
	}

	T Next()
	{
		T Value = 0;

		if (Cursor->Next != nullptr)
		{
			Value = Cursor->Next->Value;

			Cursor = Cursor->Next;
		}

		return Value;
	}

	T operator[](int Index)
	{
		int Counter = 0;

		while (Cursor->Next != nullptr)
		{
			if (Counter == Index)
			{
				T Value = Cursor->Next->Value;
				Reset();
				return Value;
			}

			Cursor = Cursor->Next;
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

		CurrentNode = Head->Next;

		while (CurrentNode != nullptr)
		{
			std::cout << CurrentNode->Value << std::endl;

			CurrentNode = CurrentNode->Next;
		}
	}

private:

	Node<T>* Head;
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

	while (true)
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