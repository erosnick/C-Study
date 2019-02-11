import std.core;
import Character;

class King : public Character
{
public:

	virtual void fight() override
	{
		printf("King fight.\n");

		Character::fight();
	}
};