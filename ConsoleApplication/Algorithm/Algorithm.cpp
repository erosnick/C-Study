// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
import Array;
import Bitvector;
import Entity;

using namespace Container;
using namespace Entity;

int main()
{
	//Array<char> CharArray = { 'a', 'b', 'c', 'd', 'e' };

	//for (auto Element : CharArray)
	//{
	//	printf("%c\n", Element);
	//}

	//Array<int> IntArray(10);

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

	//IntArray.Read("Array.dat");

	//for (int i : IntArray)
	//{
	//	printf("%d\n", i);
	//}

	//Array<int> IntArray;

	//for (int i = 0; i < 33; i++)
	//{
	//	IntArray.Push(i);
	//}

	//for (int i : IntArray)
	//{
	//	printf("%d\n", i);
	//}

	//Bitvector Bits(33);
	
	//Bitvector Bits(1);

	//for (int i = 0; i < 32; i++)
	//{
	//	Bits.Set(i, true);
	//}

	//Bits.Write("Bitvector.dat");

	//for (int i = 0; i < 32; i++)
	//{
	//	printf("%d", Bits[i]);
	//}

	//Bits.Clear();

	//printf("\n");

	//Bits.Read("Bitvector.dat");

	//for (int i = 0; i < 32; i++)
	//{
	//	printf("%d", Bits[i]);
	//}

	Array<Player> Players(3);

	for (int i = 0; i < 3; i++)
	{
		Players[i].HP = rand() % 5 + 10;
		Players[i].EXP = rand() % 10 + 50;
		Players[i].Level = rand() % 10 + 1;
		Players[i].Money = rand() % 100 + 1;
	}

	Players.Write("Players.data");

	for (int i = 0; i < 3; i++)
	{
		printf("******\n");

		printf("Player%d\n\n", i);

		printf("HP=%d\n", Players[i].HP);
		printf("EXP=%d\n", Players[i].EXP);
		printf("Level=%d\n", Players[i].Level);
		printf("Money=%d\n", Players[i].Money);

		printf("******\n\n");
	}
}
