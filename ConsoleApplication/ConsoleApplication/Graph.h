#pragma once

#include "DataType.h"
#include <vector>

// 图的数据结构。
typedef char VertexType;	// 顶点类型应由用户自定义。
typedef int EdgeType;	    // 边上的权值类型应由用户定义。

const int MAXVERTEX = 100;  // 最大顶点数，应由用户定义。
const int INFINITY_INT = 65535;	// 用65535来代表∞。

// 边表结点。
struct EdgeNode
{
	int AdjacentVertex;		// 邻接点域，存储该顶点对应的下标。
	EdgeType Weight;	// 用于存储权值，对于非网图可以不需要。
	EdgeNode* Next;		// 链域，指向下一个邻接点。
};

// 顶点表结点。
struct VertexNode
{
	VertexType Data;		// 顶点域，存储顶点信息。
	EdgeNode* FirstEdge;	// 边表头指针。
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