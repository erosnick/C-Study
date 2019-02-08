import std.core;
import FlyBehavior;
import QuackBehavior;

using namespace Behavior;

class Duck
{
public:

	virtual void display() = 0;

	virtual void swin() 
	{ 
		printf("All ducks float, even decoys."); 
	}

	void performFly()
	{
		flyBehavior->fly();
	}

	void performQuack()
	{
		quackBehavior->quack();
	}

protected:

	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};