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
			ArrayPtr = new T[DefaultCapacity];

			ElementCount = 0;

			ArrayCapacity = DefaultCapacity;
		}

		Array(int Size)
		{
			ArrayCapacity = DefaultCapacity;

			Resize(Size);

			ElementCount = Size;
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
		void Resize(size_t NewSize)
		{
			size_t AllocateSize = NewSize;

			if (NewSize % ArrayCapacity == 0)
			{
				AllocateSize = NewSize / DefaultCapacity * DefaultCapacity;
			}
			else
			{
				AllocateSize = (NewSize / DefaultCapacity + 1) * DefaultCapacity;
			}

			T* NeWArray = new T[AllocateSize];

			memset(NeWArray, 0, sizeof(T) * AllocateSize);

			size_t Min = 0;

			if (AllocateSize > ElementCount)
			{
				Min = ElementCount;
			}
			else
			{
				Min = AllocateSize;
			}

			for (int i = 0; i < Min; i++)
			{
				NeWArray[i] = ArrayPtr[i];
			}

			delete[] ArrayPtr;

			ArrayPtr = NeWArray;

			ArrayCapacity = AllocateSize;
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

		void Push(T Data)
		{
			if (ElementCount == ArrayCapacity)
			{
				Resize(ElementCount + DefaultCapacity);
			}

			ArrayPtr[ElementCount] = Data;

			ElementCount++;
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

			fwrite((void*)&ElementCount, sizeof(int), 1, OutFile);

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

			fread_s((void*)&ElementCount, sizeof(int), sizeof(int), 1, InFile);

			uint64_t Readed = fread_s(ArrayPtr, sizeof(T) * ArrayCapacity, sizeof(T), ElementCount, InFile);

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
		static const size_t DefaultCapacity = 32;
		size_t ArrayCapacity;
		size_t ElementCount;
		T* ArrayPtr;
	};
}