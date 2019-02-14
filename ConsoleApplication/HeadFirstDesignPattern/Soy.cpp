import CondimentDecorator;

class Soy : public CondimentDecorator
{
public:

	Soy(Beverage* newBeverage)
		: beverage(newBeverage)
	{
	}

	virtual std::string getDescription() const override
	{
		return beverage->getDescription() + ", Soy";
	}

	virtual double cost() const override
	{
		double cost = beverage->cost();

		if (getSize() == Beverage::CupSize::Tall)
		{
			cost += 0.1;
		}
		else if (getSize() == Beverage::CupSize::Grande)
		{
			cost += 0.15;
		}
		else if (getSize() == Beverage::CupSize::Venti)
		{
			cost += 0.2;
		}

		return cost;
	}

	virtual Beverage::CupSize getSize() const override
	{
		return beverage->getSize();
	}

protected:

	Beverage* beverage;
};