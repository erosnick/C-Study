// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
import Array;

using namespace Container;

int main()
{
	Array<char> CharArray = { 'a', 'b', 'c', 'd', 'e' };

	for (auto Element : CharArray)
	{
		printf("%c\n", Element);
	}

	Array<int> IntArray(10);

	//for (int i = 0; i < IntArray.Length(); i++)
	//{
	//	IntArray[i] = i;
	//}

	//int* IntPtr = IntArray;

	//for (int i = 0; i < IntArray.Length(); i++)
	//{
	//	printf("%d\n", IntPtr[i]);
	//}

	//IntArray.Insert(999, 4);

	//for (int i : IntArray)
	//{
	//	printf("%d\n", i);
	//}

	//IntArray.Delete(4);

	//for (int i : IntArray)
	//{
	//	printf("%d\n", i);
	//}

	//IntArray.Write("Array.dat");

	IntArray.Read("Array.dat");

	for (int i : IntArray)
	{
		printf("%d\n", i);
	}
}
