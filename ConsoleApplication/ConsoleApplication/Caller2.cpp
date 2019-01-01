#include "pch.h"
#include <iostream>

template <typename T>
void foo(const T& v)
{
	std::cout << "Caller2 : " << v << std::endl;
}

void caller2()
{
	foo(20);
	foo(20.0f);
}