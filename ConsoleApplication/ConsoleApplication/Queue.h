#pragma once

#include "DataType.h"

template <typename T>
class Queue
{
public:

	Queue()
	{
		Front = nullptr;
		Rear = nullptr;
	}

	~Queue()
	{
		Node<T>* Cursor = nullptr;

		while (Front != nullptr)
		{
			Cursor = Front;

			Front = Front->Next;

			delete Cursor;
		}
	}

	T GetFront() const
	{
		if (Length > 0)
		{
			return Front->Value;
		}

		return -1;
	}

	void Enqueue(T Value)
	{
		if (Length == 0)
		{
			Front = new Node<T>();
			Front->Value = Value;
			Rear = Front;
		}
		else
		{
			Node<T>* NewNode = new Node<T>();

			NewNode->Value = Value;

			Rear->Next = NewNode;

			Rear = Rear->Next;
		}

		Length++;
	}

	T Dequeue()
	{
		if (Front != nullptr)
		{
			Node<T>* Temp = Front;

			Front = Front->Next;

			T Value = Temp->Value;

			delete Temp;

			Length--;

			return Value;
		}

		return -1;
	}

	void Print()
	{
		Node<T>* Cursor = Front;

		while (Cursor != nullptr)
		{
			std::cout << Cursor->Value << std::endl;

			Cursor = Cursor->Next;
		}
	}

	bool Empty()
	{
		return Length == 0;
	}

	int GetLength() const
	{
		return Length;
	}

private:

	Node<T>* Front;
	Node<T>* Rear;
	int Length;
};