import PizzaStore;
import NYPizzaIngredientFactory;

class NYPizzaStore : public PizzaStore
{
public:

	virtual Pizza* createPizza(std::string type) override
	{
		PizzaIngredientFactory* pizzaIngredientFactory = new NYPizzaIngredientFactory();
		Pizza* pizza = nullptr;

		if (type == "cheese")
		{
			pizza = new CheesePizza(pizzaIngredientFactory);
			pizza->setName("New York Style Cheese Pizza");
		}
		else if (type == "veggie")
		{
			pizza = new VeggiePizza(pizzaIngredientFactory);
			pizza->setName("New York Style Veggie Pizza");
		}
		else if (type == "clam")
		{
			pizza = new ClamPizza(pizzaIngredientFactory);
			pizza->setName("New Yor Style Clam Pizza");
		}
		else if (type == "pepperoni")
		{
			pizza = new PepperoniPizza(pizzaIngredientFactory);
			pizza->setName("New York Style Pepperoni Pizza");
		}

		return pizza;
	}
};