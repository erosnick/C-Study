import std.core;
import MallardDuck;
import ModelDuck;
import FlyRocketPowered;

using namespace Behavior;

import King;
import Queen;
import Knight;
import Troll;
import KnifeBehavior;
import SwordBehavior;
import ArrowAndBowBehavior;
import AxeBehavior;

using namespace Weapon;

int main()
{
	Duck* duck = new MallardDuck();

	duck->performFly();
	duck->performQuack();
	duck->display();

	Duck* modelDuck = new ModelDuck();

	modelDuck->performFly();

	modelDuck->setFlyBehavior(new FlyRocketPowered());

	modelDuck->performFly();

	Character* king = new King();

	king->setWeaponBehavior(new SwordBehavior());
	king->fight();

	return 0;
}