import SimplePizzaFactory;

class PizzaStore
{
public:

	virtual Pizza* createPizza(std::string type) = 0;

	Pizza* orderPizza(std::string type)
	{
		Pizza* pizza = createPizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}
};