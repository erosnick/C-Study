import Command;
import Light;

class LightOnCommand : public Command
{
public:

	LightOnCommand(Light* newLight)
		: light(newLight)
	{
	}

	void execute()
	{
		light->on();
	}

private:

	Light* light;
};