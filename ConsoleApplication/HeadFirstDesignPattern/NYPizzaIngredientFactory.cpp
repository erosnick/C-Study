import PizzaIngredientFactory;
import ThinCrustDough;
import MarinaraSauce;
import ReggianoCheese;
import Garlic;	
import Onion;
import Mushroom;
import RedPepper;
import SlicedPepperoni;
import FreshClams;

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:

	Dough* createDough() override
	{
		return new ThinCrustDough();
	}

	Sauce* createSauce() override
	{
		return new MarinaraSauce();
	}

	Cheese* createCheese() override
	{
		return new ReggianoCheese();
	}

	std::vector<Veggies*> createVeggies() override
	{
		std::vector<Veggies*> veggies = { new Garlic(), new Onion(), new Mushroom(), new RedPepper() };

		return veggies;
	}

	Pepperoni* createPepperoni() override
	{
		return new SlicedPepperoni();
	}

	Clams* createClam() override
	{
		return new FreshClams();
	}
};