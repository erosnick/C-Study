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

	Print("请输入顶点数:");

	std::cin >> NumVertexs;

	Print("请输入边数:");

	std::cin >> NumEdges;

	// 读入顶点信息，建立顶点表。
	
	Print("请输入顶点信息:");

	for (i = 0; i < NumVertexs; i++)
	{
		std::cin >> Vertices[i];
	}

	// 邻接矩阵初始化。
	for (i = 0; i < NumVertexs; i++)
	{
		for (j = 0; j < NumVertexs; j++)
		{
			Arc[i][j] = INFINITY_INT;
		}
	}

	
	Print("输入边(vi, vj)上的下标i, 下标j和权w:");

	// 读入NumEdges条边，建立邻接矩阵。
	for (k = 0; k < NumEdges; k++)
	{
		std::cin >> i >> j >> w;

		Arc[i][j] = w;
		Arc[j][i] = Arc[i][j];	// 因为是无向图，矩阵对称。
	}
}

void AdjacentListGraph::Create()
{
	int i, j, k;

	EdgeNode* Edge;

	Print("输入顶点数和边数:");

	// 输入顶点数和边数。

	Print("输入顶点数:");
	std::cin >> NumVertexs;

	Print("输入边数:");
	std::cin >> NumEdges;

	// 读取顶点信息，建立顶点表。
	for (i = 0; i < NumVertexs; i++)
	{
		Print("输入顶点数据:");
		// 输入顶点信息。
		std::cin >> List[i].Data;
		// 将边表置为空表。
		List[i].FirstEdge = nullptr;
	}

	// 建立边表。
	for (k = 0; k < NumEdges; k++)
	{
		Print("输入边(vi,vj)上的顶点序号:");

		std::cin >> i >> j;

		Edge = new EdgeNode();

		// 邻接序号为j。
		Edge->AdjacentVertex = j;

		// 将Edge指针指向当前顶点指向的结点。
		Edge->Next = List[i].FirstEdge;
		// 将当前顶点的指针指向Edge。
		List[i].FirstEdge = Edge;

		Edge = new EdgeNode();

		// 邻接序号为i。
		Edge->AdjacentVertex = i;

		// 将Edge指针指向当前顶点指向的结点。
		Edge->Next = List[j].FirstEdge;
		// 将当前顶点的指针指向Edge。
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