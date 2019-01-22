#include "pch.h"
#include "Graph.h"
#include "Utility.h"

AdjacentListGraph::AdjacentListGraph()
{
	NumVertexs = 0;
	NumEdges = 0;
}

AdjacentListGraph::~AdjacentListGraph()
{
	Clear();
}

void AdjacentMatrixGraph::Create()
{
	int i, j, k, w;

	Print("�����붥����:");

	std::cin >> NumVertexs;

	Print("���������:");

	std::cin >> NumEdges;

	// ���붥����Ϣ�����������
	
	Print("�����붥����Ϣ:");

	for (i = 0; i < NumVertexs; i++)
	{
		std::cin >> Vertices[i];
	}

	// �ڽӾ����ʼ����
	for (i = 0; i < NumVertexs; i++)
	{
		for (j = 0; j < NumVertexs; j++)
		{
			Arc[i][j] = INFINITY_INT;
		}
	}

	
	Print("�����(vi, vj)�ϵ��±�i, �±�j��Ȩw:");

	// ����NumEdges���ߣ������ڽӾ���
	for (k = 0; k < NumEdges; k++)
	{
		std::cin >> i >> j >> w;

		Arc[i][j] = w;
		Arc[j][i] = Arc[i][j];	// ��Ϊ������ͼ������Գơ�
	}
}

void AdjacentListGraph::Create()
{
	int i, j, k;

	EdgeNode* Edge;

	Print("���붥�����ͱ���:");

	// ���붥�����ͱ�����

	Print("���붥����:");
	std::cin >> NumVertexs;

	Print("�������:");
	std::cin >> NumEdges;

	// ��ȡ������Ϣ�����������
	for (i = 0; i < NumVertexs; i++)
	{
		Print("���붥������:");
		// ���붥����Ϣ��
		std::cin >> List[i].Data;
		// ���߱���Ϊ�ձ�
		List[i].FirstEdge = nullptr;
	}

	// �����߱�
	for (k = 0; k < NumEdges; k++)
	{
		Print("�����(vi,vj)�ϵĶ������:");

		std::cin >> i >> j;

		Edge = new EdgeNode();

		// �ڽ����Ϊj��
		Edge->AdjacentVertex = j;

		// ��Edgeָ��ָ��ǰ����ָ��Ľ�㡣
		Edge->Next = List[i].FirstEdge;
		// ����ǰ�����ָ��ָ��Edge��
		List[i].FirstEdge = Edge;

		Edge = new EdgeNode();

		// �ڽ����Ϊi��
		Edge->AdjacentVertex = i;

		// ��Edgeָ��ָ��ǰ����ָ��Ľ�㡣
		Edge->Next = List[j].FirstEdge;
		// ����ǰ�����ָ��ָ��Edge��
		List[j].FirstEdge = Edge;
	}
}

void AdjacentListGraph::Clear()
{
	for (int i = 0; i < NumVertexs; i++)
	{
		EdgeNode* FirstEdge = List[i].FirstEdge;

		EdgeNode* Node = FirstEdge;

		while (Node!= nullptr)
		{
			FirstEdge = FirstEdge->Next;

			delete Node;

			Node = FirstEdge;
		}
	}
}