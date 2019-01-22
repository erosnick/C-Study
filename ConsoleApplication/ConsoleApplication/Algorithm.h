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
	// ��¼ԭʼ�����سߴ硣
	static int OriginWidth = Width;
	static int OriginHeight = Height;

	// ��Ϊ����Ҫ�����ػ���Ϊ���Σ�Ҳ�������ռ�������ؿ鳤��Ҫ��ȣ�
	// ͬʱ�����С�ǿ��Ա����ص�ԭʼ��������������ǻ���������
	if (Width == Height && ((OriginWidth % Width) == 0 && (OriginHeight % Height) == 0))
	{
		return Width;
	}
	else
	{
		// ÿ�εݹ��ýϴ�ı߳���ȥ��С�ı߳������µĲ��ּ����ݹ顣
		// ������̿��Կ�ǰ�����ͼ���֡�
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
	// ��׼������
	// ����������0����һ��Ԫ�أ�Ӧ��ֱ�ӷ��ظ����顣
	if (Array.size() < 2)
	{
		return Array;
	}
	else
	{
		std::vector<int> GreaterThanBase;       // С�ڻ�׼Ԫ�ص�Ԫ�����顣
		std::vector<int> LessThanBase;          // ���ڻ�׼Ԫ�ص�Ԫ�����顣

	   // ������ĵ�һ��Ԫ��ѡ����׼Ԫ�ء�
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

		// �ݹ�������
		// ������LessThanBase��GreaterThanBase���еݹ�����
		// ���ǿ�������һ��ǰ�潲���ĵݹ麯������ջ��ջ���ÿһ��Ԫ��
		// ����һ���ź�������飬��ջ����ջ�װ��������С�
		std::vector<int> SortedLessThanBase = QuickSort(LessThanBase);
		std::vector<int> SortedGreaterThanBase = QuickSort(GreaterThanBase);
		std::vector<int> SortedArray;

		// �ϲ��ź�������顣
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
		// ��������ֱ�������
		if ((Ch >= 48 && Ch <= 57))
		{
			Subfix.push_back(Ch);
		}
		else
		{
			// ����������ֱ����ջ��
			if (Ch == '(')
			{
				Operators.Push(Ch);
			}
			else
			{
				// ���������ţ���ջ����Ԫ�ز������ֱ��')'��ջ��
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
					// ��������������š�
					if (Operators.Size() > 0)
					{
						if (Operators.Top() != '(')
						{
							// ������������ȼ�����ջ��Ԫ�أ�ֱ����ջ��
							if (Priority[Ch] > Priority[Operators.Top()])
							{
								Operators.Push(Ch);
							}
							// ��ǰ���������ȼ�С��ջ��Ԫ�أ���ջ�������ȼ�>=��ǰ��������Ԫ�ز������
							else
							{
								while (Operators.Size() > 0)
								{
									if (Priority[Ch] <= Priority[Operators.Top()])
									{
										Subfix.push_back(Operators.Pop());
									}
								}

								// �����ջ��ǰ��������
								Operators.Push(Ch);
							}
						}
						else
						{
							// ջ��Ԫ����'('�������ֱ����ջ��
							Operators.Push(Ch);
						}
					}
					else
					{
						// ջΪ�գ�������ֱ����ջ��
						Operators.Push(Ch);
					}
				}
			}
		}
	}

	// ��׺���ʽ�������֮�󣬳�ջ����Ԫ�ز������
	while (Operators.Size() > 0)
	{
		Subfix.push_back(Operators.Pop());
	}

	return Subfix;
}

// �����׺���ʽ��
int Calculate(const std::string& Suffix)
{
	Stack<int> Operation;

	for (char Ch : Suffix)
	{
		// �������֣���������ջ���á�
		if (Ch >= 48 && Ch <= 57)
		{
			Operation.Push(Ch - '0');
		}
		// �������������ջ�������������м��㣬Ȼ�󽫽����ջ��
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

// Length�ĳ���Ϊ�ַ�������+1���������һ���ֽ������ڽ�β��'\0'��
char* StrCpy(char* Dest, int Length, const char* Src)
{
	assert("Invalid parameter." && Dest != nullptr && Src != nullptr);

	char* P = Dest;

	int Available = Length;

	// ע������Ҫ��һ����ʱָ������ֵ��
	// ǧ������Dest����Ϊ��ı�ָ���ֵ��
	while ((*P++ = *Src++) != 0 && --Available > 0);

	// ���Ȳ��������Ŀ���ڴ�ռ䲢�������ԡ�
	if (Available == 0)
	{
		memset(Dest, 0, Length);
		assert("Buffer too small!" && 0);
	}

	P = '\0';

	return Dest;
}

// ����ָ���������ַ���
char* StrNCpy(char* Dest, int Length, const char* Src, int MaxCount)
{
	assert("Invalid parameter." && Dest != nullptr && Src != nullptr);
	assert("MaxCount > Length + 1" && MaxCount < Length);

	char* P = Dest;

	int Available = MaxCount + 1;

	// ע������Ҫ��һ����ʱָ������ֵ��
	// ǧ������Dest����Ϊ��ı�ָ���ֵ��
	while (Available > 1)
	{
		(*P++ = *Src++);

		Available--;
	}

	// ���Ȳ��������Ŀ���ڴ�ռ䲢�������ԡ�
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
		// InString[k]��ʾǰ׺��InString[j]��ʾ��׺��
		if (k == -1 || Source[j] == Source[k])
		{
			++k;
			++j;
			Next[j] = k;
		}
		else
		{
			// ����k��Ѱ�Ҹ��̵���ͬǰ׺��׺��
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
		// 1.���j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�(��Source[i] = Pattern[j]������i++��j++��
		if (j == -1 || Source[i] == Pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			// 2.���j != -1���ҵ�ǰ�ַ�ƥ��ʧ��(Source[i] != Pattern[i]������i���䣬j = next[j])��
			// next[j]��Ϊj����Ӧ��nextֵ��
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
		// 1.���j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�(��Source[i] = Pattern[j]������i++��j++��
		if (j == -1 || Source[i] == Pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			// 2.���j != -1���ҵ�ǰ�ַ�ƥ��ʧ��(Source[i] != Pattern[i]������i���䣬j = next[j])��
			// next[j]��Ϊj����Ӧ��nextֵ��
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

// ͼ�����㷨

// ���ʱ�־���顣
bool Visited[255];

// �ڽӾ����������ȵݹ��㷨��
void DepthFirstSearch(const AdjacentMatrixGraph& Graph, int i)
{
	int j = 0;

	Visited[i] = true;

	// ��ӡ���㣬Ҳ����������������
	Print(Graph.Vertices[i]);

	for (j = 0; j < Graph.NumVertexs; j++)
	{
		if (Graph.Arc[i][j] == 1 && !Visited[j])
		{
			// ��δ���ʵ��ڽӶ���ݹ���á�
			DepthFirstSearch(Graph, j);
		}
	}
}

void DepthFirstSearchTraverse(const AdjacentMatrixGraph& Graph)
{
	int i = 0;

	for (i = 0; i < Graph.NumVertexs; i++)
	{
		// ��ʼ�����ж���״̬����δ���ʹ�״̬��
		Visited[i] = false;

		for (i = 0; i < Graph.NumVertexs; i++)
		{
			// ��δ���ʹ��Ķ������DFS,������ͨͼ��ֻ��ִ��һ�Ρ�
			DepthFirstSearch(Graph, i);
		}
	}
}