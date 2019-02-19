import Command;

class SimpleRemoteControl
{
public:

	SimpleRemoteControl() {}

	void setCommand(Command* newCommand)
	{
		command = newCommand;
	}

	void buttonWasPressed()
	{
		command->execute();
	}

private:

	Command* command;
};