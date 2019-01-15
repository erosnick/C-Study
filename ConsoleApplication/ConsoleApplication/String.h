#pragma once

#include <ostream>

int StrLen(const char* InString)
{
	if (*InString == '\0')
	{
		return 0;
	}
	else
	{
		return StrLen(InString + 1) + 1;
	}
}

class String
{
public:

	String()
	{
		PString = new char[1];
	}

	String(const char* InString)
	{
		int Length = StrLen(InString);
		PString = new char[Length];

		memset(PString, 0, Length);

		for (int i = 0; i < Length; i++)
		{
			*PString++ = *InString++;
		}
	}

	~String()
	{
		delete[] PString;
	}

	friend std::ostream& operator<< (std::ostream& Out, const String& OutputString)
	{
		Out << OutputString.PString;

		return Out;
	}
private:

	char* PString;
};