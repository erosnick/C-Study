#pragma once

#include "DataType.h"
#include "Utility.h"

template <typename T>
class DoubleLinkedList
{
public:

	DoubleLinkedList()
	{
		Head = new Node<T>;
		Tail = new Node<T>;
		Last = nullptr;
		NodeCount = 0;
	}

	DoubleLinkedList& operator=(const DoubleLinkedList& Lhs)
	{
		if (this != &Lhs)
		{
			Node<T>* Cursor = Lhs.Head->Next;

			while (Cursor != nullptr)
			{
				Append(Cursor->Value);

				Cursor = Cursor->Next;
			}
		}

		return *this;
	}

	~DoubleLinkedList()
	{
		Node<T>* Cursor = nullptr;

		while (Head != nullptr)
		{
			Cursor = Head;

			Head = Head->Next;

			delete Cursor;
		}
	}

	void Append(T Value)
	{
		if (Last == nullptr)
		{
			Node<T>* NewNode = new Node<T>();

			NewNode->Value = Value;

			Head->Next = NewNode;

			NewNode->Prior = Head;

			Last = NewNode;
		}
		else
		{
			Node<T>* NewNode = new Node<T>();

			NewNode->Value = Value;

			Last->Next = NewNode;

			NewNode->Prior = Last;

			Last = Last->Next;
		}

		Last->Next = Tail;
		Tail->Prior = Last;

		NodeCount++;
	}

	void Insert(int Position, T Value)
	{
		ASSERT(Position >= 0 && Position <= NodeCount, "Illegal insert position.");

		Node<T>* Cursor = Head;

		for (int i = 0; i < Position; i++)
		{
			Cursor = Cursor->Next;
		}

		Node<T>* NewNode = new Node<T>();

		NewNode->Value = Value;

		NewNode->Next = Cursor->Next;
		NewNode->Prior = Cursor;
		Cursor->Next = NewNode;

		NodeCount++;
	}

	void Insert(const DoubleLinkedList<int>& List)
	{
		Node<T>* Cursor = List.Head->Next;

		while (Cursor != List.Tail)
		{
			Append(Cursor->Value);

			Cursor = Cursor->Next;
		}
	}

	void Delete(T Value)
	{
		Node<T>* Prior = Head;
		Node<T>* Cursor = Head->Next;

		for (int i = 0; i < NodeCount; i++)
		{
			if (Cursor != nullptr)
			{
				if (Cursor->Value == Value)
				{
					Prior->Next = Cursor->Next;
					Cursor->Next->Prior = Prior;
					delete Cursor;
					break;
				}
			}

			Prior = Prior->Next;
			Cursor = Cursor->Next;
		}
	}

	void DeleteAt(int Position)
	{
		Node<T>* Prior = Head;
		Node<T>* Cursor = Head->Next;

		for (int i = 0; i < NodeCount; i++)
		{
			if (Cursor != nullptr)
			{
				if (i == Position)
				{
					Prior->Next = Cursor->Next;
					Cursor->Next->Prior = Prior;
					delete Cursor;
					break;
				}
			}

			Prior = Prior->Next;
			Cursor = Cursor->Next;
		}
	}

	void Print(bool Forward = true)
	{
		if (Forward)
		{
			Node<T>* Cursor = Head->Next;

			while (Cursor != nullptr && Cursor != Tail)
			{
				std::cout << Cursor->Value << std::endl;

				Cursor = Cursor->Next;
			}
		}
		else
		{
			Node<T>* Cursor = Tail->Prior;

			while (Cursor != nullptr && Cursor != Head)
			{
				std::cout << Cursor->Value << std::endl;
				Cursor = Cursor->Prior;
			}
		}
	}

	int Length() const
	{
		return NodeCount;
	}

public:

	Node<T>* Head;
	Node<T>* Tail;
	Node<T>* Last;
	int NodeCount;
};