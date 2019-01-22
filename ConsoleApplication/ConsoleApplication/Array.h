#pragma once

#include "Utility.h"

template <typename T>
class Array
{
public:

	Array()
	{

	}

	Array(std::initializer_list<T> InitializerList)
	{
		ArrayPtr = new T[InitializerList.size()];

		uint32_t i = 0;

		for (auto& Element : InitializerList)
		{
			ArrayPtr[i] = Element;

			i++;
		}
	}

	~Array()
	{

	}

private:

	T* ArrayPtr;
};