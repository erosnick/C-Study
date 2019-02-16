import std.core;
import Pizza;
import PizzaIngredientFactory;

class CheesePizza : public Pizza
{
public:

	CheesePizza(PizzaIngredientFactory* newPizzaIngredientFactory)
		: pizzaIngredientFactory(newPizzaIngredientFactory)
	{

	}

	void prepare() override
	{
		printf(("Preparing " + name).c_str());
		dough = pizzaIngredientFactory->createDough();
		sauce = pizzaIngredientFactory->createSauce();
		cheese = pizzaIngredientFactory->createCheese();
	}

protected:

	PizzaIngredientFactory* pizzaIngredientFactory;
};