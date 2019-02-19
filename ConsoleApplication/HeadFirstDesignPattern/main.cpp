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

import HouseBlend;
import Expresso;
import DarkRoast;
import Mocha;
import Soy;
import Whip;

import SimpleRemoteControl;
import LightOnCommand;

int main()
{
	//Duck* duck = new MallardDuck();

	//duck->performFly();
	//duck->performQuack();
	//duck->display();

	//Duck* modelDuck = new ModelDuck();

	//modelDuck->performFly();

	//modelDuck->setFlyBehavior(new FlyRocketPowered());

	//modelDuck->performFly();

	//Character* king = new King();

	//king->setWeaponBehavior(new SwordBehavior());
	//king->fight();

	//Beverage* expresso = new Expresso();
	//expresso->setSize(Beverage::CupSize::Tall);

	//printf("%s%3.2f\n", (expresso->getDescription() + " $").c_str(), expresso->cost());

	//Beverage* darkRoast = new DarkRoast();
	//darkRoast->setSize(Beverage::CupSize::Grande);

	//darkRoast = new Mocha(darkRoast);
	//darkRoast = new Mocha(darkRoast);
	//darkRoast = new Whip(darkRoast);

	//printf("%s%3.2f\n", (darkRoast->getDescription() + " $").c_str(), darkRoast->cost());

	//Beverage* houseBlend = new HouseBlend();
	//houseBlend->setSize(Beverage::CupSize::Venti);

	//houseBlend = new Soy(houseBlend);
	//houseBlend = new Whip(houseBlend);
	//houseBlend = new Mocha(houseBlend);

	//printf("%s%3.2f\n", (houseBlend->getDescription() + " $").c_str(), houseBlend->cost());

	SimpleRemoteControl* remote = new SimpleRemoteControl();

	Light* light = new Light();
	LightOnCommand* lightOn = new LightOnCommand(light); 

	remote->setCommand(lightOn);
	remote->buttonWasPressed();

	return 0;
}