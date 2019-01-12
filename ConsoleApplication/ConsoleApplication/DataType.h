#pragma once

const int INVAILD = -100000000;

template <typename T>
struct Node
{
	Node()
	{
		Value = INVAILD;
		Next = nullptr;
		Prior = nullptr;
	}

	T Value;
	Node* Next;
	Node* Prior;
};