// STLModule.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
import std.core;
import Module;

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 };

	for (int i : v)
	{
		printf("%d\n", i);
	}
}