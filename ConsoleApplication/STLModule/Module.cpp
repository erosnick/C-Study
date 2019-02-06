namespace Module
{
	int Test(int X)
	{
		return 2 + X; 
	}

	template <typename T>
	int Max(T A, T B)
	{
		return A > B ? A : B;
	}
}