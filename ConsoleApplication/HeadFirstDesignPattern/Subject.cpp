import std.core;

class Subject
{
public:

	class ObserverBase
	{
	public:

		virtual void OnMessageXX(int param1, float param2) = 0;
		virtual void OnMessageYY(int param1, const std::string& param2) = 0;
		virtual void update(float temp, float humidity, float pressure) = 0;
	};

	void registerListener(ObserverBase* listener)
	{
		observerList.push_back(listener);
	}

	void removeListener(ObserverBase* listener)
	{
		auto iterator = std::find(observerList.begin(), observerList.end(), listener);

		if (iterator != observerList.end())
		{
			observerList.erase(iterator);
		}
	}

	virtual void notifyObservers() = 0;

protected:

	std::list<ObserverBase*> observerList;
};