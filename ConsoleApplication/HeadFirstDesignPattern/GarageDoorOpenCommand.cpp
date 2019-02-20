import Command;
import GarageDoor;

class GarageDoorOpenCommand : public Command
{
public:

	GarageDoorOpenCommand(GarageDoor* newGarageDoor)
		: garageDoor(newGarageDoor)
	{

	}

	void execute() override
	{
		garageDoor->up();
	}

	void undo() override
	{
		garageDoor->down();
	}

private:

	GarageDoor* garageDoor;
};