// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
import Array;
import Array2D;
import Bitvector;
import Entity;

using namespace Container;
using namespace Entity;

const int SEEK_CUR = 1;
const int SEEK_END = 2;
const int SEEK_SET = 0;

template <typename T>
struct foo {
	int x[2];
	std::unique_ptr<T []> ArrayPtr;

	foo(const std::initializer_list<std::initializer_list<T>>& List)
	{
		ArrayPtr = decltype(ArrayPtr)(new T[3 * 3]);
	}

	template <typename... T>
	foo(T... ts) : x{ ts... } { // note the use of brace-init-list
	}

	~foo()
	{
		printf("I'm dead.");
	}
};

class Square
{
public:

	Square(const std::initializer_list<int>& Parameter)
	{

	}

private:

	int Width;
	int Height;
};

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

	//Array<Player> Players(3);

	//for (int i = 0; i < 3; i++)
	//{
	//	Players[i].HP = rand() % 5 + 10;
	//	Players[i].EXP = rand() % 10 + 50;
	//	Players[i].Level = rand() % 10 + 1;
	//	Players[i].Money = rand() % 100 + 1;
	//}

	//Players.Write("Players.dat");

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("******\n");

	//	printf("Player%d\n\n", i);

	//	printf("HP=%d\n", Players[i].HP);
	//	printf("EXP=%d\n", Players[i].EXP);
	//	printf("Level=%d\n", Players[i].Level);
	//	printf("Money=%d\n", Players[i].Money);

	//	printf("******\n\n");
	//}

	//FILE* InFile = nullptr;

	//fopen_s(&InFile, "Players.dat", "rb+");

	//if (InFile != nullptr)
	//{
	//	Player God;
	//	God.HP = 999;
	//	God.EXP = 999;
	//	God.Level = 99;
	//	God.Money = 999;

	//	fseek(InFile, sizeof(Player) * 2 + 4, SEEK_SET);
	//	uint64_t Written = fwrite(&God, sizeof(Player), 1, InFile);

	//	fclose(InFile);
	//}

	//Players.Read("Players.dat");

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("******\n");

	//	printf("Player%d\n\n", i);

	//	printf("HP=%d\n", Players[i].HP);
	//	printf("EXP=%d\n", Players[i].EXP);
	//	printf("Level=%d\n", Players[i].Level);
	//	printf("Money=%d\n", Players[i].Money);

	//	printf("******\n\n");

	Square S = { 10, 20};
	
	Array2D<int> TwoDimensionArray = { {1, 2, 3}, {4, 5, 6} };

	printf("%d\n", TwoDimensionArray[0][2]);
}
