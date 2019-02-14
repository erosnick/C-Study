import CondimentDecorator;

class Milk : public CondimentDecorator
{
public:

	Milk(Beverage* newBeverage)
		: beverage(newBeverage)
	{

	}

	virtual std::string getDescription() const override
	{
		return beverage->getDescription() + ", Milk";
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