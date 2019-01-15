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

template <typename T>
void Print(T Content)
{
	std::cout << Content << std::endl;
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
							// ջ��Ԫ����'('��')'�������ֱ����ջ��
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

int Calculate(const std::string& Suffix)
{
	Stack<int> Operation;

	for (char Ch : Suffix)
	{
		if (Ch >= 48 && Ch <= 57)
		{
			Operation.Push(Ch - '0');
		}
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