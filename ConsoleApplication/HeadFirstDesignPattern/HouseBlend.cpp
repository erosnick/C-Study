import Beverage;

class HouseBlend : public Beverage
{
public:

	HouseBlend()
	{
		description = "House Blend Coffee";
	}

	double cost() const
	{
		return 0.89;
	}
};