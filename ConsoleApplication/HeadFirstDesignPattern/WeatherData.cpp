import Subject;

class WeatherData : public Subject
{
public:

	WeatherData()
	{

	}

	virtual void notifyObservers() override
	{
		for (auto observer : observerList)
		{
			observer->update(temperature, humidity, pressure);
		}
	}

	void measurementChanged()
	{
		notifyObservers();
	}

	void setMeasurements(float newTemperature, float newHumidity, float newPressure)
	{
		temperature = newTemperature;
		humidity = newHumidity;
		pressure = newPressure;

		measurementChanged();
	}

private:

	float temperature;
	float humidity;
	float pressure;
};