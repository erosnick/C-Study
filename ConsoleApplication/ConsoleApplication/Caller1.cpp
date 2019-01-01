#include "pch.h"
#include <iostream>

template <typename T>
void foo(const T& v)
{
	std::cout << "Caller1 : " << v << std::endl;
}

void caller1()
{
	foo(10);
	foo(10.0f);
}