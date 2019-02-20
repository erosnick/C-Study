import std.core;

class CeilingFan
{
public:

	CeilingFan(std::string newLocation)
		: location(newLocation)
	{
		speed = OFF;
	}

	void high()
	{
		speed = HIGH;
		printf((location + " ceiling fan is on high.\n").c_str());
	}

	void medium()
	{
		speed = MEDIUM;
		printf((location + " ceiling fan is on medium.\n").c_str());
	}

	void low()
	{
		speed = LOW;
		printf((location + " ceiling fan is on low.\n").c_str());
	}

	void off()
	{
		speed = OFF;
		printf((location + " ceiling fan is off.\n").c_str());
	}

	int getSpeed() const
	{
		return speed;
	}

	static const int HIGH = 3;
	static const int MEDIUM = 2;
	static const int LOW = 1;
	static const int OFF = 0;

private:

	std::string location;
	int speed;
};