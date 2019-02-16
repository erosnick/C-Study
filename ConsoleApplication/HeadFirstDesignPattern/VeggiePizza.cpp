import std.core;
import Pizza;
import PizzaIngredientFactory;

class VeggiePizza : public Pizza
{
public:

	VeggiePizza(PizzaIngredientFactory* newPizzaIngredientFactory)
		: pizzaIngredientFactory(newPizzaIngredientFactory)
	{

	}

	void prepare() override
	{
		printf(("Preparing " + name).c_str());
		dough = pizzaIngredientFactory->createDough();
		sauce = pizzaIngredientFactory->createSauce();
		veggies = pizzaIngredientFactory->createVeggies();
	}

protected:

	PizzaIngredientFactory* pizzaIngredientFactory;
};