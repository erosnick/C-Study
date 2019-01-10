#pragma once

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