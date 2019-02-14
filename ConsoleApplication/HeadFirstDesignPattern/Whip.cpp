import CondimentDecorator;

class Whip : public CondimentDecorator
{
public:

	Whip(Beverage* newBeverage)
		: beverage(newBeverage)
	{

	}

	virtual std::string getDescription() const override
	{
		return beverage->getDescription() + ", Whip";
	}

	virtual double cost() const override
	{
		return 0.1 + beverage->cost();
	}

	virtual Beverage::CupSize getSize() const override
	{
		return beverage->getSize();
	}

protected:

	Beverage* beverage;
};