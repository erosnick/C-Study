#pragma once

#include "DataType.h"
#include "Utility.h"
#include <functional>

template <typename T>
class BinaryTree
{
public:

	BinaryTree()
	{
		Root = nullptr;
		NodeCount = 0;
		FirstInOrderNode = true;
	}

	~BinaryTree()
	{
		Clear();
	}

	// 根据数据建立二叉树。
	void Create(std::vector<T> Data)
	{
		Create(&Root, Data);
	}

	// 这里要传指向指针的指针，因为我们修改指针本身(也可以传指针的引用)。
	void Create(BTNode<T>** Node, std::vector<T>& Data)
	{
		// Data.size() == 0表示数据处理完成。
		// -1表示此结点是叶子结点。
		if (Data.size() == 0 || Data.front() == -1)
		{
			if (Data.size() > 0)
			{
				Data.erase(Data.begin());
			}

			return;
		}
		else
		{
			(*Node) = new BTNode<T>();
			(*Node)->Data = Data.front();

			// 保存创建好的结点指针，以便删除。
			Nodes.push_back((*Node));

			Data.erase(Data.begin());

			Create(&(*Node)->LeftChild, Data);
			Create(&(*Node)->RightChild, Data);
		}
	}

	// 前序遍历二叉树。
	void PreOrderTraverse(std::function<void(BTNode<int>* Node)> Behavior)
	{
		PreOrderTraverse(Root, Behavior);
	}
	
	void PreOrderTraverse(BTNode<T>* Node, std::function<void(BTNode<int>* Node)> Behavior)
	{
		if (Node == nullptr)
		{
			return;
		}
		else
		{
			if (Behavior != nullptr)
			{
				Behavior(Node);
			}

			PreOrderTraverse(Node->LeftChild, Behavior);
			PreOrderTraverse(Node->RightChild, Behavior);
		}
	}

	// 中序遍历二叉树。
	void InOrderTraverse(std::function<void(BTNode<int>* Node)> Behavior)
	{
		InOrderTraverse(Root, Behavior);
	}

	void InOrderTraverse(BTNode<T>* Node, std::function<void(BTNode<int>* Node)> Behavior)
	{
		if (Node == nullptr)
		{
			return;
		}
		else
		{
			// 中序遍历左子树。
			InOrderTraverse(Node->LeftChild, Behavior);

			if (Behavior != nullptr)
			{
				Behavior(Node);
			}

			// 中序遍历右子树。
			InOrderTraverse(Node->RightChild, Behavior);
		}
	}

	// 中序遍历线索化二叉树。
	void InThreading()
	{
		Head = new BTNode<T>();

		// 头节点的左孩子指向根结点。
		Head->LeftChild = Root;

		InThreading(Root);

		// 这时Pre指向中序遍历的最后一个结点。
		// 让头结点的右孩子指向它。
		Head->RightChild = Pre;

		// 让最后一个结点的右孩子指向头结点。
		Pre->RightChild = Head;
	}

	void InThreading(BTNode<T>* Node)
	{
		if (Node == nullptr)
		{
			return;
		}
		else
		{
			// 递归左子树线索化。
			InThreading(Node->LeftChild);

			// 让中序遍历的第一个结点的左孩子指向根结点。
			if (FirstInOrderNode)
			{
				Node->LeftChild = Root;
				Node->LeftTag = BTNode<T>::Thread;
				FirstInOrderNode = false;
			}

			// 没有左孩子。
			if (Node->LeftChild == nullptr)
			{
				// 前驱线索。
				Node->LeftTag = BTNode<T>::Thread;
				// 左孩子指针指向前驱。
				Node->LeftChild = Pre;
			}

			// 前驱没有右孩子。
			if (Pre != nullptr && Pre->RightChild == nullptr)
			{
				// 后继线索。
				Pre->RightTag = BTNode<T>::Thread;
				// 前驱右孩子指针指向后继(当前结点Node)。
				Pre->RightChild = Node;
			}

			// 保持Pre指向Node的前驱。
			Pre = Node;

			// 递归右子树线索化。
			InThreading(Node->RightChild);
		}
	}

	void InOrderTraverseThreading()
	{
		BTNode<T>* Node;

		// Node指向根节点。
		Node = Head->LeftChild;

		// 遍历结束时Node == Head。
		while (Node != Head)
		{
			while (Node->LeftTag == BTNode<int>::Link)
			{
				Node = Node->LeftChild;
			}

			Print(Node->Data);

			while (Node->RightTag == BTNode<int>::Thread && Node->RightChild != Head)
			{
				Node = Node->RightChild;
				Print(Node->Data);
			}

			// Node进至其右子树根。
			Node = Node->RightChild;
		}
	}

	// 后序遍历二叉树。
	void PostOrderTraverse(std::function<void(BTNode<int>* Node)> Behavior)
	{
		PostOrderTraverse(Root, Behavior);
	}

	void PostOrderTraverse(BTNode<T>* Node, std::function<void(BTNode<int>* Node)> Behavior)
	{
		if (Node == nullptr)
		{
			return;
		}
		else
		{
			// 先遍历左子树。
			PostOrderTraverse(Node->LeftChild, Behavior);
			// 再遍历右子树。
			PostOrderTraverse(Node->RightChild, Behavior);

			// 最后进行结点处理。
			if (Behavior != nullptr)
			{
				Behavior(Node);
			}
		}
	}

	BTNode<T>* GetRoot()
	{
		return Root;
	}

	void Clear()
	{
		for (uint32_t i = 0; i < Nodes.size(); i++)
		{
			delete Nodes[i];
		}

		delete Head;
	}

private:

	BTNode<T>* Root;
	BTNode<T>* Pre;

	BTNode<T>* Head;

	bool FirstInOrderNode;

	std::vector<BTNode<T>*> Nodes;

	int NodeCount;
};