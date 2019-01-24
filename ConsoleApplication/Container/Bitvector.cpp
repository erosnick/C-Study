import std.core;

namespace Container
{
	class Bitvector
	{
	public:

		Bitvector(size_t BitSize)
		{
			Bits = nullptr;
			ElementCount = 0;
			VectorCapacity = 64;

			Resize(BitSize);
		}

		~Bitvector()
		{
			if (Bits != nullptr)
			{
				delete[] Bits;
				Bits = nullptr;
			}
		}

		void Resize(size_t NewBitSize)
		{
			size_t AllocateSize = 0;

			if (NewBitSize % sizeof(long) == 0)
			{
				AllocateSize = NewBitSize / 32;
			}
			else
			{
				AllocateSize = NewBitSize / 32 + 1;
			}

			size_t Min = 0;

			if (ElementCount > 0 && AllocateSize > ElementCount)
			{
				Min = ElementCount;
			}
			else
			{
				Min = AllocateSize;
			}

			unsigned long* NewBits = new unsigned long[AllocateSize];

			if (Bits != nullptr)
			{
				for (size_t i = 0; i < Min; i++)
				{
					NewBits[i] = Bits[i];
				}

				delete Bits;

				Bits = nullptr;
			}

			Bits = NewBits;

			ElementCount = AllocateSize;

			VectorCapacity = AllocateSize;
		}

		bool operator [] (int Index)
		{
			int Cell = Index / 32;
			int Bit = Index % 32;
			return Bits[Cell] & (1 << Bit) >> Bit;
		}

		void Set(int Index, bool Value)
		{
			int Cell = Index / 32;
			int Bit = Index % 32;

			if (Value)
			{
				Bits[Cell] = Bits[Cell] | (1 << Bit);
			}
			else
			{
				Bits[Cell] = Bits[Cell] & (~(1 << Bit));
			}
		}

		void SetAll()
		{
			for (int i = 0; i < ElementCount; i++)
			{
				Bits[i] = 0xFFFFFFFF;
			}
		}

		void Clear()
		{
			for (int i = 0; i < ElementCount; i++)
			{
				Bits[i] = 0;
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

			fwrite(&ElementCount, sizeof(size_t), 1, OutFile);

			uint64_t Written = fwrite(Bits, sizeof(unsigned long), ElementCount, OutFile);

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

			fread_s(&ElementCount, sizeof(size_t), sizeof(size_t), 1, InFile);

			uint64_t Readed = fread_s(Bits, sizeof(unsigned long) * VectorCapacity, sizeof(unsigned long), ElementCount, InFile);

			fclose(InFile);

			if (Readed != ElementCount)
			{
				return false;
			}

			return true;
		}

	private:
		unsigned long* Bits;
		size_t VectorCapacity;
		size_t ElementCount;
		static const size_t DefaultCapacity = 1;
	};
}