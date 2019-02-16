import std.core;
import Pizza;
import PizzaIngredientFactory;

class ClamPizza : public Pizza
{
public:

	ClamPizza(PizzaIngredientFactory* newPizzaIngredientFactory)
		: pizzaIngredientFactory(newPizzaIngredientFactory)
	{

	}


	void prepare() override
	{
		printf(("Preparing " + name).c_str());
		dough = pizzaIngredientFactory->createDough();
		sauce = pizzaIngredientFactory->createSauce();
		cheese = pizzaIngredientFactory->createCheese();
		clam = pizzaIngredientFactory->createClam();
	}

protected:

	PizzaIngredientFactory* pizzaIngredientFactory;
};