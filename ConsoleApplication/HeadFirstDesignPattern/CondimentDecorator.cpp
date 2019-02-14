import Beverage;

class CondimentDecorator : public Beverage
{
	virtual std::string getDescription() const = 0;

	virtual Beverage::CupSize getSize() const = 0;
};