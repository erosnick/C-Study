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
	}

	~DoubleLinkedList()
	{
		Node<T>* Temp = Head;

		while (Head->Next != nullptr)
		{
			Temp = Head;

			delete Temp;

			Head = Head->Next;
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

private:

	Node<T>* Head;
	Node<T>* Tail;
	Node<T>* Last;
	int NodeCount;
};