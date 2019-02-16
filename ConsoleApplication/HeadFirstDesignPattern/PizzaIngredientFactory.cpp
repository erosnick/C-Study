import std.core;
import Dough;
import Sauce;
import Cheese;
import Veggies;
import Pepperoni;
import Clams;

class PizzaIngredientFactory
{
public:

	virtual Dough* createDough() = 0;
	virtual Sauce* createSauce() = 0;
	virtual Cheese* createCheese() = 0;
	virtual std::vector<Veggies*> createVeggies() = 0;
	virtual Pepperoni* createPepperoni() = 0;
	virtual Clams* createClam() = 0;
};