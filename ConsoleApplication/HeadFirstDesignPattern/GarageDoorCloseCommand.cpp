import Command;
import GarageDoor;

class GarageDoorCloseCommand : public Command
{
public:

	GarageDoorCloseCommand(GarageDoor* newGarageDoor)
		: garageDoor(newGarageDoor)
	{

	}

	void execute() override
	{
		garageDoor->down();
	}

	void undo() override
	{
		garageDoor->up();
	}

private:

	GarageDoor* garageDoor;
};