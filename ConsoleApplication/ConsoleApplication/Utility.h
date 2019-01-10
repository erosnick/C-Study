#pragma once

#include <iostream>
#include <vector>

#include "LinkedList.h"

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