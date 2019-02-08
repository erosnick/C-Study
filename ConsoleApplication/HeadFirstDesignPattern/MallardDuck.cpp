import Duck;
import Quack;
import FlyWithWings;

using namespace Behavior;

class MallardDuck : public Duck
{
public:

	MallardDuck()
	{
		flyBehavior = new FlyWithWings();
		quackBehavior = new Quack();
	}

	virtual void display() override
	{
		printf("I'm a real mallard duck!\n");
	}
};