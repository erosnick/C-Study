import std.core;
import Character;

class Queen : public Character
{
public:

	virtual void fight() override
	{
		printf("Queen fight.\n");

		Character::fight();
	}
};