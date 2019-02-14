import Beverage;

class Decaf : public Beverage
{
public:

	Decaf()
	{
		description = "Decaf";
	}

	virtual double cost() const override
	{
		return 1.05;
	}
};