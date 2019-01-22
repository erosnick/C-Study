#pragma once

#include <vector>
#include <string>
#include <map>

template <typename T>
int FindSmallest(LinkedList<T>& List)
{
	int Smallest = List[0];

	for (int i = 0; i < List.Length(); i++)
	{
		int Value = List[i];

		if (Value < Smallest)
		{
			Smallest = Value;
		}
	}

	return Smallest;
}

template <typename T>
void SelectionSort(LinkedList<T>& Array, LinkedList<T>& Result)
{
	int Length = Array.Length();

	for (int i = 0; i < Length; i++)
	{
		int Smallest = FindSmallest(Array);

		Array.Delete(Smallest);

		Result.Append(Smallest);
	}
}

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int Factorial(int n)
{
	Print(n);

	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

int Sum(std::vector<int> Array)
{
	if (Array.empty())
	{
		return 0;
	}
	else
	{
		int First = Array[0];
		Array.erase(Array.begin());
		return First + Sum(Array);
	}
}

int Counter(std::vector<int> Array)
{
	if (Array.size() == 0)
	{
		return 0;
	}
	else
	{
		Array.erase(Array.begin());

		return 1 + Counter(Array);
	}
}

int Max(std::vector<int> Array)
{
	if (Array.size() == 1)
	{
		return Array[0];
	}
	else
	{
		if (Array[0] > Array[1])
		{
			Array.erase(Array.begin() + 1);
		}
		else
		{
			Array.erase(Array.begin());
		}

		return Max(Array);
	}
}

//int Divide(int Width, int Height)
//{
//	static int OriginWidth = Width;
//	static int OriginHeight = Height;
//
//	if (Width == Height && ((OriginWidth % Width) == 0 && (OriginHeight % Height) == 0))
//	{
//		return Width;
//	}
//	else
//	{
//		if (Width > Height)
//		{
//			int Left = Width - Height * 2;
//
//			if (Left > 0)
//			{
//				return Divide(Left, Height);
//			}
//			else
//			{
//				return Divide(Width - Height, Height);
//			}
//		}
//		else
//		{
//			int Left = Height - Width * 2;
//
//			if (Left > 0)
//			{
//				return Divide(Width, Left);
//			}
//			else
//			{
//				return Divide(Width, Height - Width);
//			}
//		}
//	}
//}

int Divide(int Width, int Height)
{
	// 记录原始的土地尺寸。
	static int OriginWidth = Width;
	static int OriginHeight = Height;

	// 因为问题要求土地划分为方形，也就是最终计算的最大地块长宽要相等，
	// 同时这个大小是可以被土地的原始长宽整除，这就是基线条件。
	if (Width == Height && ((OriginWidth % Width) == 0 && (OriginHeight % Height) == 0))
	{
		return Width;
	}
	else
	{
		// 每次递归用较大的边长减去较小的边长，余下的部分继续递归。
		// 具体过程可以看前面的配图部分。
		if (Width > Height)
		{
			int Left = Width - Height;

			return Divide(Left, Height);
		}
		else
		{
			int Left = Height - Width;

			return Divide(Width, Left);
		}
	}
}

std::vector<int> QuickSort(std::vector<int> Array)
{
	// 基准条件。
	// 如果数组包含0个或一个元素，应该直接返回该数组。
	if (Array.size() < 2)
	{
		return Array;
	}
	else
	{
		std::vector<int> GreaterThanBase;       // 小于基准元素的元素数组。
		std::vector<int> LessThanBase;          // 大于基准元素的元素数组。

	   // 将数组的第一个元素选作基准元素。
		auto Base = Array[0];

		for (uint32_t i = 1; i < Array.size(); i++)
		{
			if (Array[i] < Base)
			{
				LessThanBase.push_back(Array[i]);
			}
			else
			{
				GreaterThanBase.push_back(Array[i]);
			}
		}

		LessThanBase.push_back(Base);

		// 递归条件。
		// 继续对LessThanBase和GreaterThanBase进行递归排序。
		// 我们可以想象一下前面讲过的递归函数调用栈，栈里的每一个元素
		// 都是一个排好序的数组，从栈顶至栈底按升序排列。
		std::vector<int> SortedLessThanBase = QuickSort(LessThanBase);
		std::vector<int> SortedGreaterThanBase = QuickSort(GreaterThanBase);
		std::vector<int> SortedArray;

		// 合并排好序的数组。
		SortedArray.insert(SortedArray.end(), SortedLessThanBase.begin(), SortedLessThanBase.end());
		SortedArray.insert(SortedArray.end(), SortedGreaterThanBase.begin(), SortedGreaterThanBase.end());

		return SortedArray;
	}
}

template <typename T>
DoubleLinkedList<T>& Merge(const DoubleLinkedList<T>& Lhs, const DoubleLinkedList<T>& Rhs, DoubleLinkedList<T>& Result)
{
	Result = Lhs;

	Result.Insert(Rhs);

	return Result;
}

std::string Infix2Suffix(const std::string& Infix)
{
	Stack<char> Operators;
	std::string Subfix;

	std::map<char, int> Priority;

	Priority['+'] = 0;
	Priority['-'] = 0;
	Priority['*'] = 1;
	Priority['/'] = 1;
	Priority['('] = 2;
	Priority[')'] = 2;

	const char Add = 43;
	const int Sub = 45;
	const int Mul = 42;
	const int Div = 47;

	for (char Ch : Infix)
	{
		// 遇到数字直接输出。
		if ((Ch >= 48 && Ch <= 57))
		{
			Subfix.push_back(Ch);
		}
		else
		{
			// 遇到左括号直接入栈。
			if (Ch == '(')
			{
				Operators.Push(Ch);
			}
			else
			{
				// 遇到右括号，出栈所有元素并输出，直到')'出栈。
				if (Ch == ')')
				{
					while (true)
					{
						char Pop = Operators.Pop();

						if (Pop == '(')
						{
							break;
						}
						else
						{
							Subfix.push_back(Pop);
						}
					}
				}
				else
				{
					// 处理四则运算符号。
					if (Operators.Size() > 0)
					{
						if (Operators.Top() != '(')
						{
							// 如果操作符优先级大于栈顶元素，直接入栈。
							if (Priority[Ch] > Priority[Operators.Top()])
							{
								Operators.Push(Ch);
							}
							// 当前操作符优先级小于栈顶元素，出栈所有优先级>=当前操作符的元素并输出。
							else
							{
								while (Operators.Size() > 0)
								{
									if (Priority[Ch] <= Priority[Operators.Top()])
									{
										Subfix.push_back(Operators.Pop());
									}
								}

								// 最后入栈当前操作符。
								Operators.Push(Ch);
							}
						}
						else
						{
							// 栈顶元素是'('的情况，直接入栈。
							Operators.Push(Ch);
						}
					}
					else
					{
						// 栈为空，操作符直接入栈。
						Operators.Push(Ch);
					}
				}
			}
		}
	}

	// 后缀表达式处理完毕之后，出栈所有元素并输出。
	while (Operators.Size() > 0)
	{
		Subfix.push_back(Operators.Pop());
	}

	return Subfix;
}

// 计算后缀表达式。
int Calculate(const std::string& Suffix)
{
	Stack<int> Operation;

	for (char Ch : Suffix)
	{
		// 遇到数字，将数字入栈备用。
		if (Ch >= 48 && Ch <= 57)
		{
			Operation.Push(Ch - '0');
		}
		// 遇到运算符，出栈两个操作数进行计算，然后将结果入栈。
		else
		{
			int Result = 0;

			int Operand1 = Operation.Pop();
			int Operand2 = Operation.Pop();

			switch (Ch)
			{
			case '+':

				Result = Operand1 + Operand2;

				break;

			case '-':

				Result = Operand2 - Operand1;

				break;

			case '*':

				Result = Operand1 * Operand2;

				break;

			case '/':

				Result = Operand2 / Operand1;

				break;
			}

			Operation.Push(Result);
		}
	}

	return Operation.Pop();
}

int StrLen(const char* InString)
{
	if (*InString == '\0')
	{
		return 0;
	}
	else
	{
		return StrLen(InString + 1) + 1;
	}
}

// Length的长度为字符串长度+1，多出来的一个字节是用于结尾符'\0'。
char* StrCpy(char* Dest, int Length, const char* Src)
{
	assert("Invalid parameter." && Dest != nullptr && Src != nullptr);

	char* P = Dest;

	int Available = Length;

	// 注意这里要用一个临时指针来赋值，
	// 千万不能用Dest，因为会改变指针的值。
	while ((*P++ = *Src++) != 0 && --Available > 0);

	// 长度不够，清空目标内存空间并引发断言。
	if (Available == 0)
	{
		memset(Dest, 0, Length);
		assert("Buffer too small!" && 0);
	}

	P = '\0';

	return Dest;
}

// 拷贝指定数量的字符。
char* StrNCpy(char* Dest, int Length, const char* Src, int MaxCount)
{
	assert("Invalid parameter." && Dest != nullptr && Src != nullptr);
	assert("MaxCount > Length + 1" && MaxCount < Length);

	char* P = Dest;

	int Available = MaxCount + 1;

	// 注意这里要用一个临时指针来赋值，
	// 千万不能用Dest，因为会改变指针的值。
	while (Available > 1)
	{
		(*P++ = *Src++);

		Available--;
	}

	// 长度不够，清空目标内存空间并引发断言。
	if (Available == 0)
	{
		memset(Dest, 0, Length);
		assert("Buffer too small!" && 0);
	}

	P = '\0';

	return Dest;
}

void GetNext(const char* Source, int Next[])
{
	int Length = StrLen(Source);

	Next[0] = -1;

	int k = -1;

	int j = 0;
	
	while (j < Length - 1)
	{
		// InString[k]表示前缀，InString[j]表示后缀。
		if (k == -1 || Source[j] == Source[k])
		{
			++k;
			++j;
			Next[j] = k;
		}
		else
		{
			// 回溯k，寻找更短的相同前缀后缀。
			k = Next[k];
		}
	}
}

int KMPSearch(const char* Source, const char* Pattern, int Next[])
{
	int i = 0;
	int j = 0;

	int SourceLength = StrLen(Source);
	int PatternLength = StrLen(Pattern);

	while (i < SourceLength && j < PatternLength)
	{
		// 1.如果j = -1，或者当前字符匹配成功(即Source[i] = Pattern[j]，都令i++，j++。
		if (j == -1 || Source[i] == Pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			// 2.如果j != -1，且当前字符匹配失败(Source[i] != Pattern[i]，则令i不变，j = next[j])。
			// next[j]即为j所对应的next值。
			j = Next[j];
		}
	}

	if (j == PatternLength)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}

int KMPSearch(const char* Source, const char* Pattern)
{
	int i = 0;
	int j = 0;

	int SourceLength = StrLen(Source);
	int PatternLength = StrLen(Pattern);

	int* Next = new int[PatternLength];
	
	GetNext(Pattern, Next);

	while (i < SourceLength && j < PatternLength)
	{
		// 1.如果j = -1，或者当前字符匹配成功(即Source[i] = Pattern[j]，都令i++，j++。
		if (j == -1 || Source[i] == Pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			// 2.如果j != -1，且当前字符匹配失败(Source[i] != Pattern[i]，则令i不变，j = next[j])。
			// next[j]即为j所对应的next值。
			j = Next[j];
		}
	}

	delete[] Next;

	if (j == PatternLength)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}

// 图遍历算法

// 访问标志数组。
bool Visited[255];

// 邻接矩阵的深度优先递归算法。
void DepthFirstSearch(const AdjacentMatrixGraph& Graph, int i)
{
	int j = 0;

	Visited[i] = true;

	// 打印顶点，也可以是其他操作。
	Print(Graph.Vertices[i]);

	for (j = 0; j < Graph.NumVertexs; j++)
	{
		if (Graph.Arc[i][j] == 1 && !Visited[j])
		{
			// 对未访问的邻接顶点递归调用。
			DepthFirstSearch(Graph, j);
		}
	}
}

void DepthFirstSearchTraverse(const AdjacentMatrixGraph& Graph)
{
	int i = 0;

	for (i = 0; i < Graph.NumVertexs; i++)
	{
		// 初始化所有顶点状态都是未访问过状态。
		Visited[i] = false;

		for (i = 0; i < Graph.NumVertexs; i++)
		{
			// 对未访问过的顶点调用DFS,若是连通图，只会执行一次。
			DepthFirstSearch(Graph, i);
		}
	}
}