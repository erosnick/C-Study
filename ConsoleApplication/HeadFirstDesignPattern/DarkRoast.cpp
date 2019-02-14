import Beverage;

class DarkRoast : public Beverage
{
public:

	DarkRoast()
	{
		description = "Dark Roast";
	}

	virtual double cost() const override
	{
		return 0.99;
	}
};