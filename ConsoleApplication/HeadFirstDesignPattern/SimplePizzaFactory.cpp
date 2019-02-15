import std.core;
import CheesePizza;
import ClamPizza;
import PepperoniPizza;
import VeggiePizza;

class SimplePizzaFactory
{
public:

	Pizza* createPizza(std::string type)
	{
		Pizza* pizza = nullptr;

		// 根据披萨类型实例化具体类。
		if (type == "cheese")
		{
			pizza = new CheesePizza();
		}
		else if (type == "pepperoni")
		{
			pizza = new PepperoniPizza();
		}
		else if (type == "clam")
		{
			pizza = new ClamPizza();
		}
		else if (type == "veggie")
		{
			pizza = new VeggiePizza();
		}

		return pizza;
	}
};