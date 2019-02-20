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
import LightOffCommand;
import GarageDoorOpenCommand;
import GarageDoorCloseCommand;
import RemoteControl;
import CeilingFan;
import CeilingFanHighCommand;
import CeilingFanMediumCommand;
import CeilingFanLowCommand;
import CeilingFanOffCommand;
import MacroCommand;

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

	RemoteControl* remote = new RemoteControl();

	Light* light = new Light();
	LightOnCommand* lightOn = new LightOnCommand(light);
	LightOffCommand* lightOff = new LightOffCommand(light);

	remote->setCommand(0, lightOn, lightOff);
	remote->onButtonWasPushed(0);

	GarageDoor* garageDoor = new GarageDoor();
	GarageDoorOpenCommand* garageDoorOpen = new GarageDoorOpenCommand(garageDoor);
	GarageDoorCloseCommand* garageDoorClose = new GarageDoorCloseCommand(garageDoor);

	remote->setCommand(1, garageDoorOpen, garageDoorClose);
	remote->onButtonWasPushed(1);
	remote->undoButtonWasPushed();

	CeilingFan* ceilingFan = new CeilingFan("Living Room");

	CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
	CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
	CeilingFanLowCommand* ceilingFanLow = new CeilingFanLowCommand(ceilingFan);
	CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

	remote->setCommand(2, ceilingFanHigh, ceilingFanOff);
	remote->setCommand(3, ceilingFanMedium, ceilingFanOff);
	remote->setCommand(4, ceilingFanLow, ceilingFanOff);

	remote->onButtonWasPushed(2);
	remote->offButtonWasPushed(2);
	remote->undoButtonWasPushed();

	remote->onButtonWasPushed(3);
	remote->onButtonWasPushed(2);
	remote->undoButtonWasPushed();
	remote->offButtonWasPushed(3);

	printf("MacroCommand test.\n");

	std::vector<Command*> onCommands = { lightOn, garageDoorOpen, ceilingFanHigh };
	std::vector<Command*> offCommands = { lightOff, garageDoorClose, ceilingFanOff };

	Command* macroCommandOn = new MacroCommand(onCommands);
	Command* macroCommandOff = new MacroCommand(offCommands);

	remote->setCommand(5, macroCommandOn, macroCommandOff);
	remote->onButtonWasPushed(5);
	remote->undoButtonWasPushed();

	return 0;
}