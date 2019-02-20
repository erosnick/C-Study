import Command;
import Light;

class LightOffCommand : public Command
{
public:

	LightOffCommand(Light* newLight)
		: light(newLight)
	{

	}

	void execute() override
	{
		light->off();
	}

	void undo() override
	{
		light->on();
	}
private:

	Light* light;
};