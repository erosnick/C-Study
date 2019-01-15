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
							// 栈顶元素是'('或')'的情况，直接入栈。
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