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

	// �������ݽ�����������
	void Create(std::vector<T> Data)
	{
		Create(&Root, Data);
	}

	// ����Ҫ��ָ��ָ���ָ�룬��Ϊ�����޸�ָ�뱾��(Ҳ���Դ�ָ�������)��
	void Create(BTNode<T>** Node, std::vector<T>& Data)
	{
		// Data.size() == 0��ʾ���ݴ�����ɡ�
		// -1��ʾ�˽����Ҷ�ӽ�㡣
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

			// ���洴���õĽ��ָ�룬�Ա�ɾ����
			Nodes.push_back((*Node));

			Data.erase(Data.begin());

			Create(&(*Node)->LeftChild, Data);
			Create(&(*Node)->RightChild, Data);
		}
	}

	// ǰ�������������
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

	// ���������������
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
			// ���������������
			InOrderTraverse(Node->LeftChild, Behavior);

			if (Behavior != nullptr)
			{
				Behavior(Node);
			}

			// ���������������
			InOrderTraverse(Node->RightChild, Behavior);
		}
	}

	// ���������������������
	void InThreading()
	{
		Head = new BTNode<T>();

		// ͷ�ڵ������ָ�����㡣
		Head->LeftChild = Root;

		InThreading(Root);

		// ��ʱPreָ��������������һ����㡣
		// ��ͷ�����Һ���ָ������
		Head->RightChild = Pre;

		// �����һ�������Һ���ָ��ͷ��㡣
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
			// �ݹ���������������
			InThreading(Node->LeftChild);

			// ����������ĵ�һ����������ָ�����㡣
			if (FirstInOrderNode)
			{
				Node->LeftChild = Root;
				Node->LeftTag = BTNode<T>::Thread;
				FirstInOrderNode = false;
			}

			// û�����ӡ�
			if (Node->LeftChild == nullptr)
			{
				// ǰ��������
				Node->LeftTag = BTNode<T>::Thread;
				// ����ָ��ָ��ǰ����
				Node->LeftChild = Pre;
			}

			// ǰ��û���Һ��ӡ�
			if (Pre != nullptr && Pre->RightChild == nullptr)
			{
				// ���������
				Pre->RightTag = BTNode<T>::Thread;
				// ǰ���Һ���ָ��ָ����(��ǰ���Node)��
				Pre->RightChild = Node;
			}

			// ����Preָ��Node��ǰ����
			Pre = Node;

			// �ݹ���������������
			InThreading(Node->RightChild);
		}
	}

	void InOrderTraverseThreading()
	{
		BTNode<T>* Node;

		// Nodeָ����ڵ㡣
		Node = Head->LeftChild;

		// ��������ʱNode == Head��
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

			// Node����������������
			Node = Node->RightChild;
		}
	}

	// ���������������
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
			// �ȱ�����������
			PostOrderTraverse(Node->LeftChild, Behavior);
			// �ٱ�����������
			PostOrderTraverse(Node->RightChild, Behavior);

			// �����н�㴦��
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