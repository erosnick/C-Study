class Singleton
{
	static Singleton& getInstance()
	{
		static Singleton instance;

		return instance;
	}
};