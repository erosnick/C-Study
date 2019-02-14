import CondimentDecorator;

class Mocha : public CondimentDecorator
{
public:

	Mocha(Beverage* newBeverage)
		: beverage(newBeverage)
	{

	}

	virtual std::string getDescription() const override
	{
		return beverage->getDescription() + ", Mocha";
	}

	virtual double cost() const override
	{
		return 0.2 + beverage->cost();
	}

	virtual Beverage::CupSize getSize() const override
	{
		return beverage->getSize();
	}

protected:

	Beverage* beverage;
};