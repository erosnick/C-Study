import std.core;

namespace Container
{
	template <typename T>
	class Array3D
	{
	public:

		Array3D(int InDimensionX, int InDimensionY, int InDimensionZ)
		{
			DimensionX = InDimensionX;
			DimensionY = InDimensionY;
			DimensionZ = InDimensionZ;

			ArrayPtr = decltype(ArrayPtr)(new T[Size()]);

			memset(ArrayPtr.get(), 0, sizeof(T) * Size());
		}

		// 用于支持C++11的initializer_list特性的构造函数。
		Array3D(const std::initializer_list<std::initializer_list<std::initializer_list<T>>>& InitializerList)
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

			ArrayPtr = decltype(ArrayPtr)(new T[DimensionX * DimensionY * DimensionZ]);

			size_t DepthCounter = 0;

			for (auto& Depth : InitializerList)
			{
				size_t HeightCounter = 0;

				for (auto& Row : Depth)
				{
					size_t WidthCounter = 0;

					for (auto& Element : Row)
					{
						ArrayPtr[DepthCounter * DepthCounter + HeightCounter * DimensionX + WidthCounter] = Element;
					}
				}
			}
		}

		void Resize(int InDimensionX, int InDimensionY, int InDimensionZ)
		{
			size_t AllocateSize = InDimensionX * InDimensionY * InDimensionZ;

			T* NewArrayPtr = decltype(ArrayPtr)(new T[AllocateSize]);

			size_t MinDepth = InDimensionZ < DimensionZ ? InDimensionZ : DimensionZ;
			size_t MinHeight = InDimensionY < DimensionY ? InDimensionY : DimensionY;
			size_t MinWidth = InDimensionX < DimensionX ? InDimensionX : DimensionX;

			for (int z = 0; z < MinDepth; z++)
			{
				for (int y = 0; y < MinHeight; y++)
				{
					for (int x = 0; x < MinWidth; x++)
					{

					}
				}
			}

			DimensionX = InDimensionX;
			DimensionY = InDimensionY;
			DimensionZ = InDimensionZ;
		}

		// 拷贝构造函数需要提供赋值操作符。
		Array3D& operator = (const Array3D& InArray3D)
		{
			DimensionX = InArray3D.DimensionX;
			DimensionY = InArray3D.DimensionY;
			DimensionZ = InArray3D.DimensionZ;


			ArrayPtr = decltype(ArrayPtr)(new T[Size()]);

			for (int i = 0; i < Size(); i++)
			{
				ArrayPtr[i] = InArray3D.ArrayPtr[i];
			}

			return *this;
		}

		size_t Width() const
		{
			return Width;
		}

		size_t Height() const
		{
			return Height;
		}

		size_t Size() const
		{
			return DimensionX * DimensionY * DimensionZ;
		}

	private:

		std::unique_ptr<T[]> ArrayPtr;
		size_t DimensionX;
		size_t DimensionY;
		size_t DimensionZ;
	};
}