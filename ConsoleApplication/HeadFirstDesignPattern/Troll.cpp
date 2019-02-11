import std.core;
import Character;

class Troll : public Character
{
public:

	virtual void fight() override
	{
		printf("Troll fight.\n");

		Character::fight();
	}
};