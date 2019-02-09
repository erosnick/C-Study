import std.core;
import MallardDuck;

int main()
{
	Duck* duck = new MallardDuck();

	duck->performFly();
	duck->performQuack();
	duck->display();

	return 0;
}