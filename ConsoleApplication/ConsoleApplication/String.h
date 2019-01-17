#pragma once

#include <ostream>
#include <cassert>

#include "Algorithm.h"

class String
{
public:

	String()
	{
		PString = nullptr;
		Size = 0;
	}

	String(const char* InString)
	{
		Size = StrLen(InString);;

		PString = new char[Size + 1];

		StrCpy(PString, Size + 1, InString);
	}

	// ��ֵ���캯����
	String(const String& InString)
	{
		Size = InString.Length();

		PString = new char[Size + 1];

		StrCpy(PString, Size + 1, InString.PString);
	}

	// ��ֵ���������ء�
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

			StrCpy(PString, InStringLength + 1, InString);
		}
		else
		{
			StrCpy(PString, InStringLength + 1, InString);
		}

		Size = InStringLength;

		return *this;
	}

	String& Append(const char* InString)
	{
		int Length = StrLen(InString);

		char* Temp = new char[Length + Size + 1];

		StrCpy(Temp, Size + 1, PString);
		StrCpy(Temp + Size, Length + 1, InString);

		delete PString;

		PString = Temp;

		Size += Length;

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

	String SubString(int Position, int Length)
	{
		assert(Position >= 0 && Position < Size && "Position out of range!");

		int CopyLength = Length;

		if ((Position + Length) > Size)
		{
			CopyLength = Size;
		}

		char* PSubString = new char[CopyLength + 1];

		memset(PSubString, 0, CopyLength + 1);

		StrNCpy(PSubString, CopyLength + 1, PString, CopyLength);

		String Sub;

		Sub.PString = PSubString;
		Sub.Size = CopyLength;

		return Sub;
	}

	// ʹ��KMP�㷨�����Ӵ���
	int Search(const char* Pattern)
	{
		int Length = StrLen(Pattern);

		int* Next = new int[Length];

		GetNext(Pattern, Next);

		int Find = KMPSearch(PString, Pattern, Next);

		delete [] Next;

		return Find;
	}

	String& Replace(const char* Pattern, const char* ReplaceString)
	{
		int Find = KMPSearch(PString, Pattern);

		if (Find < 0)
		{
			return *this;
		}
		else
		{
			int PatternLength = StrLen(Pattern);
			int ReplaceLength = StrLen(ReplaceString);

			if (PatternLength == ReplaceLength)
			{
				for (int i = 0; i <  PatternLength; i++)
				{
					PString[i + Find] = ReplaceString[i];
				}
			}
			else
			{
				int NewStringLength = Size - PatternLength + ReplaceLength + 1;
				char* NewString = new char[NewStringLength];

				memset(NewString, 0, NewStringLength);

				if (Find > 0)
				{
					StrNCpy(NewString, NewStringLength, PString, Find);
				}	
				
				StrCpy(NewString + Find, NewStringLength, ReplaceString);

				int Offset = Find + ReplaceLength;
				StrNCpy(NewString + Offset, NewStringLength, PString + Find + PatternLength, Size - Find - PatternLength);

				delete PString;

				PString = NewString;

				Size = NewStringLength;
			}
		}

		return Replace(Pattern, ReplaceString);
	}

	String& Insert(int Position, const char* InsertString)
	{
		assert(Position >= 0 && Position < Size && "Position out of range!");

		if (Position == Size - 1)
		{
			Append(InsertString);
		}

		int InsertStringLength = StrLen(InsertString);

		int NewStringLength = Size + InsertStringLength + 1;

		char* NewString = new char[NewStringLength];

		memset(NewString, 0, NewStringLength);

		if (Position == 0)
		{
			StrCpy(NewString, NewStringLength, InsertString);
			StrCpy(NewString + NewStringLength, Size + 1, PString);
		}

		StrNCpy(NewString, NewStringLength, PString, Position);
		StrNCpy(NewString + Position, NewStringLength, InsertString, InsertStringLength);
		StrNCpy(NewString + Position + InsertStringLength, NewStringLength, PString + Position, Size - Position);

		delete PString;

		PString = NewString;

		Size += InsertStringLength;

		return *this;
	}

	String& Delete(int Position, int Length)
	{
		assert(Position >= 0 && Position < Size && Length <= Size && "Out of range!");


		int DeleteLength = Length;

		if (Length > (Size - Position))
		{
			DeleteLength = Size - Position;
		}

		int NewStringLength = Size - DeleteLength + 1;

		char* NewString = new char[NewStringLength];

		memset(NewString, 0, NewStringLength);

		if (Position == 0)
		{
			StrNCpy(NewString, NewStringLength, PString + Length, Size - Length - 1);
		}

		StrNCpy(NewString, NewStringLength, PString, Position);
		StrNCpy(NewString + Position, NewStringLength, PString + Position + DeleteLength, Size - DeleteLength - Position);

		delete PString;

		PString = NewString;

		Size -= DeleteLength;

		return *this;
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
		assert(Index >= 0 && Index < Size && "Index out of range!");

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