#pragma once

// 链表的数据结构。
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