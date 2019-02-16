import std.core;
import Pizza;

class ChicagoStyleCheesePizza : public Pizza
{
public:

	ChicagoStyleCheesePizza()
	{
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thin Crust Dough";
		sauce = "Plum Tomato Sauce";

		toppings.push_back("Shredded Mozzarella Cheese");
	}

	void cut() override
	{
		printf("Cutting the pizza into square slices.\n");
	}
};