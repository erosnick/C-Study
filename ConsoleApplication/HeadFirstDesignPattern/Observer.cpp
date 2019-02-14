import Subject;

class Observer
{
public:

	friend class ConcrateObserver;

	class ConcrateObserver : public Subject::ObserverBase
	{
	public:

		ConcrateObserver(Observer* newInstance)
			: instance(newInstance)
		{
		}

		virtual void OnMessageXX(int param1, float param2) override
		{
			printf("OnMessageXX()\n");
		}

		virtual void OnMessageYY(int param1, const std::string& param2) override
		{
			printf("OnMessageYY()\n");
		}

		virtual void update(float temp, float humidity, float pressure) override
		{

		}
	private:

		Observer* instance;
	};

	explicit Observer(Subject* newSubject)
		: subject(newSubject)
	{
		listener = new ConcrateObserver(this);
		subject->registerListener(listener);
	}

	~Observer()
	{
		subject->removeListener(listener);
	}

	void DoSomething()
	{
		printf("DoSomething()\n");
	}

private:
	Subject* subject;
	ConcrateObserver* listener;
};