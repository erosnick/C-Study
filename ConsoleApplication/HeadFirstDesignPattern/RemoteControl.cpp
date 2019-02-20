import Command;
import NoCommand;

class RemoteControl
{
public:

	RemoteControl()
	{
		Command* noCommand = new NoCommand();

		for (int i = 0; i < 7; i++)
		{
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}

		undoCommand = noCommand;
	}

	void setCommand(int slot, Command* onCommand, Command* offCommand)
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}

	void onButtonWasPushed(int slot)
	{
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}

	void offButtonWasPushed(int slot)
	{
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}

	void undoButtonWasPushed()
	{
		undoCommand->undo();
	}

private:

	Command* onCommands[7];
	Command* offCommands[7];
	Command* undoCommand;
};