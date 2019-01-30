import std.core;

namespace Container
{
	template <typename T>
	class Array3DExp
	{
	public:

		Array3DExp(int InDimensionX, int InDimensionY, int InDimensionZ)
		{
			DimensionX = InDimensionX;
			DimensionY = InDimensionY;
			DimensionZ = InDimensionZ;

			ArrayPtr = decltype(ArrayPtr)(new T**[DimensionZ]);

			for (int z = 0; z < DimensionZ; z++)
			{
				ArrayPtr[z] = new int*[DimensionY];

				for (int y = 0; y < DimensionY; y++)
				{
					ArrayPtr[z][y] = new int[DimensionX];
				}
			}

			memset(ArrayPtr.get(), 0, sizeof(T) * Size());
		}

		// 用于支持C++11的initializer_list特性的构造函数。
		Array3DExp(const std::initializer_list<std::initializer_list<std::initializer_list<T>>>& InitializerList)
		{
			DimensionZ = InitializerList.size();

			if (DimensionZ > 0)
			{
				DimensionY = InitializerList.begin()->size();
			}

			if (DimensionY > 0)
			{
				auto TwoDimensionArrayList = *(InitializerList.begin());

				DimensionX = TwoDimensionArrayList.begin()->size();
			}

			ArrayPtr = decltype(ArrayPtr)(new T**[DimensionZ]);

			int DepthCounter = 0;

			for (auto& Depth : InitializerList)
			{
				int RowCounter = 0;

				ArrayPtr[DepthCounter] = new T*[DimensionY];

				for (auto& Row : Depth)
				{
					int ColumnCounter = 0;

					ArrayPtr[DepthCounter][RowCounter] = new T[DimensionX];

					for (auto& Element : Row)
					{
						ArrayPtr[DepthCounter][RowCounter][ColumnCounter] = Element;

						ColumnCounter++;
					}

					RowCounter++;
				}

				DepthCounter++;
			}
		}

		Array3DExp(const Array3DExp& InArray3D)
		{
			*this = InArray3D;
		}

		void Resize(int InDimensionX, int InDimensionY, int InDimensionZ)
		{
			size_t AllocateSize = InDimensionX * InDimensionY * InDimensionZ;

			T** NewArrayPtr = decltype(ArrayPtr)(new T**[InDimensionZ]);

			size_t MinDepth = InDimensionZ < DimensionZ ? InDimensionZ : DimensionZ;
			size_t MinHeight = InDimensionY < DimensionY ? InDimensionY : DimensionY;
			size_t MinWidth = InDimensionX < DimensionX ? InDimensionX : DimensionX;

			for (int z = 0; z < MinDepth; z++)
			{
				NewArrayPtr[z] = new T*[DimensionY];

				for (int y = 0; y < MinHeight; y++)
				{
					NewArrayPtr[z][y] = new T[DimensionX];

					for (int x = 0; x < MinWidth; x++)
					{
						NewArrayPtr[z][y][x] = ArrayPtr[z][y][x];
					}
				}
			}

			ArrayPtr = std::unique_ptr<T**>(NewArrayPtr.release());

			DimensionX = InDimensionX;
			DimensionY = InDimensionY;
			DimensionZ = InDimensionZ;
		}

		// 拷贝构造函数需要提供赋值操作符。
		Array3DExp& operator = (const Array3DExp& InArray3D)
		{
			DimensionX = InArray3D.DimensionX;
			DimensionY = InArray3D.DimensionY;
			DimensionZ = InArray3D.DimensionZ;


			ArrayPtr = decltype(ArrayPtr)(new T**[DimensionZ]);

			for (int z = 0; z < DimensionZ; z++)
			{
				ArrayPtr[z] = new int*[DimensionY];

				for (int y = 0; y < DimensionY; y++)
				{
					ArrayPtr[z][y] = new int[DimensionX];

					for (int x = 0; x < DimensionX; x++)
					{
						ArrayPtr[z][y][x] = InArray3D[z][y][x];
					}
				}
			}

			return *this;
		}

		T** operator [] (int Depth)
		{
			return ArrayPtr[Depth];
		}

		T Get(int InDepth, int InHeight, int Width)
		{
			return ArrayPtr[InDepth * DimensionX * DimensionZ + InHeight * DimensionX + Width];
		}

		size_t Width() const
		{
			return DimensionX;
		}

		size_t Height() const
		{
			return DimensionY;
		}

		size_t Depth() const
		{
			return DimensionZ;
		}

		size_t Size() const
		{
			return DimensionX * DimensionY * DimensionZ;
		}

	private:

		std::unique_ptr<T**[]> ArrayPtr;
		size_t DimensionX;
		size_t DimensionY;
		size_t DimensionZ;
	};
}