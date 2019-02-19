import std.core;
import Pizza;
import PizzaIngredientFactory;

class PepperoniPizza : public Pizza
{
public:

	PepperoniPizza()
	{

	}

	PepperoniPizza(PizzaIngredientFactory* newPizzaIngredientFactory)
		: pizzaIngredientFactory(newPizzaIngredientFactory)
	{

	}

	void prepare() override
	{
		printf(("Preparing " + name).c_str());
		dough = pizzaIngredientFactory->createDough();
		sauce = pizzaIngredientFactory->createSauce();
		pepperoni = pizzaIngredientFactory->createPepperoni();
	}

protected:

	PizzaIngredientFactory* pizzaIngredientFactory;
};