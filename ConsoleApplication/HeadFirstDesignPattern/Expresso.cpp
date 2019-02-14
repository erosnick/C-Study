import Beverage;

class Expresso : public Beverage
{
public:

	Expresso()
	{
		description = "Espresso";
	}

	virtual double cost() const override
	{
		return 1.99;
	}
};