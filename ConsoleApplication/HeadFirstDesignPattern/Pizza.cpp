import std.core;
import Dough;
import Sauce;
import Veggies;
import Cheese;
import Pepperoni;
import Clams;

class Pizza
{
public:

	virtual void prepare() = 0
	{
		printf(("Preparing " + name + "\n").c_str());
		printf("Tossing dough...\n");
		printf("Adding sauce...\n");
		printf("Adding toppings: \n");

		for (size_t i = 0; i < toppings.size(); i++)
		{
			printf("%s", toppings[i].c_str());
		}
	}

	virtual void bake()
	{
		printf("Bake for 25 minutes at 350.\n");
	}

	virtual void cut()
	{
		printf("Cutting the pizza into diagonal slices.\n");
	}

	virtual void box()
	{
		printf("Place pizza in official PizzaStore box.\n");
	}

	void setName(std::string newName)
	{
		name = newName;
	}

	std::string getName() const
	{
		return name;
	}

protected:

	std::string name;
	Dough* dough;
	Sauce* sauce;
	std::vector<Veggies*> veggies;
	Cheese* cheese;
	Pepperoni* pepperoni;
	Clams* clam;

	std::vector<std::string> toppings;
};