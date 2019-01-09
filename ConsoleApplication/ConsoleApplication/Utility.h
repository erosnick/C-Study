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

const int INVAILD = -100000000;

template <typename T>
struct Node
{
	Node()
	{
		Value = INVAILD;
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

template <typename T>
class LinkList
{
public:

	LinkList()
	{
		Head = new Node<T>();
		Tail = Head->NextNode;
		Cursor = Head;

		NodeCount = 0;
	}

	~LinkList()
	{
		Node<T>* CurrentNode = Head;

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

template <typename T>
int FindSmallest(LinkList<T>& List)
{
	int Smallest = List[0];

	for (int i = 0; i < List.Length(); i++)
	{
		int Value = List[i];

		if (Value < Smallest)
		{
			Smallest = Value;
		}
	}

	return Smallest;
}

template <typename T>
void SelectionSort(LinkList<T>& Array, LinkList<T>& Result)
{
	int Length = Array.Length();

	for (int i = 0; i < Length; i++)
	{
		int Smallest = FindSmallest(Array);

		Array.Delete(Smallest);

		Result.Append(Smallest);
	}
}