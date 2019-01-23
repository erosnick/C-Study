import std.core;

namespace Container
{
	template <typename T>
	class Iterator
	{
	public:

		explicit Iterator(T NewValue)
			: Value(NewValue)
		{
		}

		bool operator != (const Iterator& Other) const
		{
			return this->GetValue() != Other.GetValue();
		}

		T operator * () const
		{
			return GetValue();
		}

		const Iterator& operator ++ ()
		{
			++Value;
			return *this;
		}

	private:

		T GetValue() const
		{
			return Value;
		}

		T Value;
	};

	template <typename T>
	class Array
	{
	public:

		Array()
		{
			ArrayPtr = new T[DefaultSize];

			ElementCount = 0;

			ArrayCapacity = DefaultSize;
		}

		Array(int Size)
		{
			int AllocateSize = DefaultSize;

			if (Size > DefaultSize)
			{
				AllocateSize = (Size / DefaultSize + 1) * DefaultSize;
			}

			ArrayPtr = new T[AllocateSize];
			ElementCount = Size;
			memset(ArrayPtr, 0, sizeof(T) * ElementCount);

			ArrayCapacity = AllocateSize;
		}

		// 支持C++11的uniform initialization。
		Array(std::initializer_list<T> InitializerList)
		{
			ElementCount = InitializerList.size();

			ArrayPtr = new T[ElementCount];

			int i = 0;

			for (auto& Element : InitializerList)
			{
				ArrayPtr[i] = Element;

				i++;
			}
		}

		// 重新设置数组的尺寸。
		void Resize(int NewSize)
		{
			T* NeWArray = new T[NewSize];

			memset(NeWArray, 0, sizeof(T) * NewSize);
			memcpy_s(NeWArray, sizeof(T) * NewSize, ArrayPtr, sizeof(T) * ElementCount);

			ArrayPtr = NeWArray;

			delete[] ArrayPtr;
		}

		// 在指定索引位置插入一个元素。
		void Insert(T Data, int Index)
		{
			if (Index < 0 || Index > ArrayCapacity - 1)
			{
				throw std::runtime_error("Index out of range!");
			}

			ElementCount++;

			for (size_t i = ElementCount - 1; i > Index; i--)
			{
				ArrayPtr[i] = ArrayPtr[i - 1];
			}

			ArrayPtr[Index] = Data;
		}

		// 删除指定索引位置的元素。
		void Delete(int Index)
		{
			if (Index < 0 || Index > ArrayCapacity - 1)
			{
				throw std::runtime_error("Index out of range!");
			}

			ElementCount--;

			for (size_t i = Index; i < ElementCount; i++)
			{
				ArrayPtr[i] = ArrayPtr[i + 1];
			}
		}

		bool Write(const std::string& FileName)
		{
			FILE* OutFile = nullptr;

			fopen_s(&OutFile, FileName.c_str(), "wb");

			if (OutFile == nullptr)
			{
				return false;
			}

			size_t Size = sizeof(T) * ElementCount;

			fwrite((void*)&Size, sizeof(int), 1, OutFile);

			uint64_t Written = fwrite(ArrayPtr, sizeof(T), ElementCount, OutFile);

			fclose(OutFile);

			if (Written != ElementCount)
			{
				return false;
			}

			return true;
		}

		bool Read(const std::string& FileName)
		{
			FILE* InFile = nullptr;

			fopen_s(&InFile, FileName.c_str(), "rb");

			if (InFile == nullptr)
			{
				return false;
			}

			int Size = 0;

			fread_s((void*)&Size, sizeof(int), sizeof(int), 1, InFile);

			uint64_t Readed = fread_s(ArrayPtr, sizeof(T) * ElementCount, sizeof(T), ElementCount, InFile);

			fclose(InFile);

			if (Readed != ElementCount)
			{
				return false;
			}

			return true;
		}

		// 重载下标访问操作符。
		T& operator [] (int Index)
		{
			return ArrayPtr[Index];
		}

		// 类型转换操作符。
		operator T* ()
		{
			return ArrayPtr;
		}

		// 用于支持range-based for loop的begin/end函数对。
		T* begin() const
		{
			return ArrayPtr;
		}

		T* end() const
		{
			return ArrayPtr + ElementCount;
		}

		size_t Length() const
		{
			return ElementCount;
		}

		size_t Capacity() const
		{
			return ArrayCapacity;
		}

		~Array()
		{
			if (ArrayPtr != nullptr)
			{
				delete[] ArrayPtr;
				ArrayPtr = nullptr;
			}
		}

	private:
		static const int DefaultSize = 32;
		size_t ArrayCapacity;
		size_t ElementCount;
		size_t ArraySize;
		T* ArrayPtr;
	};
}