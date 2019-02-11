import std.core;
import Character;

class Knight : public Character
{
public:

	virtual void fight() override
	{
		printf("Knight fight.\n");

		Character::fight();
	}
};