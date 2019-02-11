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
		printf("All ducks float, even decoys.\n"); 
	}

	void performFly()
	{
		flyBehavior->fly();
	}

	void performQuack()
	{
		quackBehavior->quack();
	}

	void setFlyBehavior(FlyBehavior* newFlyBehavior)
	{
		flyBehavior = newFlyBehavior;
	}

	void setQuackBehaivor(QuackBehavior* newQuackBehavior)
	{
		quackBehavior = newQuackBehavior;
	}

protected:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};