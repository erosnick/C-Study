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