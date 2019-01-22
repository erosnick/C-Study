#pragma once

#include "DataType.h"
#include <vector>

// ͼ�����ݽṹ��
typedef char VertexType;	// ��������Ӧ���û��Զ��塣
typedef int EdgeType;	    // ���ϵ�Ȩֵ����Ӧ���û����塣

const int MAXVERTEX = 100;  // ��󶥵�����Ӧ���û����塣
const int INFINITY_INT = 65535;	// ��65535������ޡ�

// �߱��㡣
struct EdgeNode
{
	int AdjacentVertex;		// �ڽӵ��򣬴洢�ö����Ӧ���±ꡣ
	EdgeType Weight;	// ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ��
	EdgeNode* Next;		// ����ָ����һ���ڽӵ㡣
};

// ������㡣
struct VertexNode
{
	VertexType Data;		// �����򣬴洢������Ϣ��
	EdgeNode* FirstEdge;	// �߱�ͷָ�롣
};

typedef VertexNode AdjacentList[MAXVERTEX];

class AdjacentMatrixGraph
{
public:

	void Create();

	VertexType Vertices[MAXVERTEX];
	EdgeType Arc[MAXVERTEX][MAXVERTEX];
	int NumVertexs;
	int NumEdges;
};

class AdjacentListGraph
{
public:
	AdjacentListGraph();

	~AdjacentListGraph();

	void Create();

	void Clear();
private:

	AdjacentList List;
	int NumVertexs;
	int NumEdges;
};