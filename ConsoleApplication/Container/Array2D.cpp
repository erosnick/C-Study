import std.core;

namespace Container
{
	template <typename T>
	class Array2D
	{
	public:

		Array2D(int InDimensionX, int InDimensionY)
		{
			DimensionX = InDimensionX;
			DimensionY = InDimensionY;

			ArrayPtr = decltype(ArrayPtr)(new T[DimensionX * DimensionY]);
		}

		// ����֧��C++11��initializer_list���ԵĹ��캯����
		Array2D(const std::initializer_list<std::initializer_list<T>>& InitializerList)
		{
			DimensionX = InitializerList.size();

			DimensionY = 0;

			if (DimensionX > 0)
			{
				DimensionY = InitializerList.begin()->size();
			}

			ArrayPtr = decltype(ArrayPtr)(new T[DimensionX * DimensionY]);

			size_t CounterWidth = 0;
			
			for (auto& Row : InitializerList)
			{
				size_t CounterHeight = 0;

				for (auto& Element : Row)
				{
					ArrayPtr[DimensionX * CounterHeight + CounterWidth] = Element;

					CounterHeight++;
				}

				CounterWidth++;
			}
		}

		Array2D(const Array2D& InArray2D)
		{
			*this = InArray2D;
		}

		// �������캯����Ҫ�ṩ��ֵ��������
		Array2D& operator = (const Array2D& InArray2D)
		{
			DimensionX = InArray2D.DimensionX;
			DimensionY = InArray2D.DimensionY;

			ArrayPtr = decltype(ArrayPtr)(new T[DimensionX * DimensionY]);

			for (int i = 0; i < DimensionX * DimensionY; i++)
			{
				ArrayPtr[i] = InArray2D.ArrayPtr[i];
			}

			return *this;
		}

		void Resize(int InDimensionX, int InDimensionY)
		{
			T* NewArrayPtr = decltype(ArrayPtr)(new T[InDimensionX * InDimensionY]);

			// �ҳ���С���к��С�
			int MinWidth = DimensionX < InDimensionX ? DimensionX : InDimensionX;
			int MinHeight = DimensionY < InDimensionY ? DimensionY : InDimensionY;

			for (int y = 0; y < MinHeight; y++)
			{
				for (int x = 0; x < MinWidth; x++)
				{
					NewArrayPtr[y * MinHeight + x] = ArrayPtr[y * DimensionY + x];
				}
			}
		}

		size_t Width() const
		{
			return DimensionX;
		}

		size_t Height() const
		{
			return DimensionY;
		}

		~Array2D()
		{
		}
		
		// ����һ���������������֧��Array2D[][]�����﷨��
		class Array2DAccessor
		{
		public:

			Array2DAccessor(Array2D<T>& InArray2D, int InColumn)
				: InternalArrray2D(InArray2D), Column(InColumn)
			{

			}

			// ģ��Array2D[][]���ʲ�������
			T operator [] (int Row)
			{
				return InternalArrray2D.ArrayPtr[Row * InternalArrray2D.DimensionX + Column];
			}

		private:

			int Column;
			Array2D InternalArrray2D;
		};

		Array2DAccessor operator [] (int Row)
		{
			return Array2DAccessor(*this, Row);
		}

	private:

		std::unique_ptr<T []> ArrayPtr;
		size_t DimensionX;
		size_t DimensionY;
	};
}