import std.core;
import Duck;
import FlyNoWay;
import Quack;

using namespace Behavior;

class ModelDuck : public Duck
{
public:

	ModelDuck()
	{
		flyBehavior = new FlyNoWay();
		quackBehavior = new Quack();
	}

	virtual void display() override
	{
		printf("I'm a model duck.\n");
	}
};