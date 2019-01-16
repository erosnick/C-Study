#pragma once

#include <ostream>
#include <cassert>

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

// Length�ĳ���Ϊ�ַ�������+1���������һ���ֽ������ڽ�β��'\0'��
char* StrCpy(char* Dest, int Length, const char* Src)
{
	assert("Invalid parameter." && Dest != nullptr && Src != nullptr);

	char* P = Dest;

	int Available = Length;

	// ע������Ҫ��һ����ʱָ������ֵ��
	// ǧ������Dest����Ϊ��ı�ָ���ֵ��
	while ((*P++ = *Src++) != 0 && --Available > 0);

	// ���Ȳ��������Ŀ���ڴ�ռ䲢�������ԡ�
	if (Available == 0)
	{
		memset(Dest, 0, Length);
		assert("Buffer too small!" && 0);
	}

	P = '\0';

	return Dest;
}

class String
{
public:

	String()
	{
		PString = new char[0];
		Size = 0;
		printf("fuck");
	}

	String(const char* InString)
	{
		Size = StrLen(InString);;

		PString = new char[Size + 1];

		StrCpy(PString, Size + 1, InString);
	}

	String(const String& InString)
	{
		Size = InString.Length();

		PString = new char[Size + 1];

		StrCpy(PString, Size + 1, InString.PString);
	}

	String& operator=(const String& InString)
	{
		Assign(InString.PString);

		return *this;
	}

	String& Assign(const char* InString)
	{
		int InStringLength = StrLen(InString);

		// ���Դ�ַ������ȴ���Ŀ���ַ������������ַ����ڴ�ռ䣬
		// Ȼ������ַ�������������ֱ�ӽ��п�����
		if (InStringLength > Size)
		{
			delete PString;

			PString = new char[InStringLength + 1];

			Size = InStringLength + 1;

			StrCpy(PString, InStringLength + 1, InString);
		}
		else
		{
			StrCpy(PString, InStringLength + 1, InString);
		}

		return *this;
	}

	int Compare(const String& InString)
	{
		int Result = -2;

		if (InString.Length() > 0)
		{
			// *****ע��*****
			// String��һ���ṩ�������캯�������ظ�ֵ��������
			// ��ȻĬ�ϵĿ�������������Stringָ��ͬһ���ڴ棬
			// String�������ٵ�ʱ�򣬻�����ڴ����
			String LowerString = *this;
			String LowerInString = InString;

			LowerString.ToLower();
			LowerInString.ToLower();

			int Counter = InString.Length() < Size ? InString.Length() : Size;

			for (int i = 0; i < Counter; i++)
			{
				if (LowerString[i] > LowerInString[i])
				{
					Result = 1;
				}
				else if (LowerString[i] == LowerInString[i])
				{
					Result = 0;
				}
				else
				{
					Result = -1;
				}
			}
		}

		return Result;
	}

	String& ToLower()
	{
		if (Size > 0)
		{
			for (int i = 0; i < Size; i++)
			{
				if (PString[i] >= 'A' && PString[i] <= 'Z')
				{
					PString[i] += 32;
				}
			}
		}

		return *this;
	}

	String& ToUpper()
	{
		if (Size > 0)
		{
			for (int i = 0; i < Size; i++)
			{
				if (PString[i] >= 'a' && PString[i] <= 'z')
				{
					PString[i] -= 32;
				}
			}
		}

		return *this;
	}

	void Clear()
	{
		memset(PString, 0, Size);
	}

	~String()
	{
		if (PString != nullptr)
		{
			delete[] PString;
			PString = nullptr;
			Size = 0;
		}
	}

	friend std::ostream& operator<< (std::ostream& Out, const String& OutputString)
	{
		Out << OutputString.PString;

		return Out;
	}

	char operator[](int Index)
	{
		assert("Out of range!" && Index <= (Size - 1));

		return PString[Index];
	}

	int Length() const
	{
		return Size;
	}

	const char* Str()
	{
		return const_cast<const char*>(PString);
	}

private:

	char* PString;
	int Size;
};