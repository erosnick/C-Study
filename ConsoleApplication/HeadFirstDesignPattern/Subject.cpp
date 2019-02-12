import std.core;

class Subject
{
public:

	class ObserverBase
	{
	public:

		virtual void OnMessageXX(int param1, float param2) = 0;
		virtual void OnMessageYY(int param1, const std::string& param2) = 0;
	};

	void registerListener(ObserverBase* listener)
	{
		listenerList.push_back(listener);
	}

	void removeListener(ObserverBase* listener)
	{
		auto iterator = std::find(listenerList.begin(), listenerList.end(), listener);

		if (iterator != listenerList.end())
		{
			listenerList.erase(iterator);
		}
	}

private:

	std::list<ObserverBase*> listenerList;
};