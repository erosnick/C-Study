import std.core;
import Command;

class MacroCommand : public Command
{
public:

	MacroCommand(const std::vector<Command*>& newCommands)
		: commands(newCommands)
	{

	}

	void execute() override
	{
		for (auto command : commands)
		{
			command->execute();
		}
	}

	void undo() override
	{
		for (auto command : commands)
		{
			command->undo();
		}
	}

private:

	std::vector<Command*> commands;
};