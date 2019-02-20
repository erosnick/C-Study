import Command;
import CeilingFan;

class CeilingFanLowCommand : public Command
{
public:

	CeilingFanLowCommand(CeilingFan* newCeilingFan)
		: ceilingFan(newCeilingFan)
	{

	}

	void execute() override
	{
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->low();
	}

	void undo() override
	{
		switch (prevSpeed)
		{
		case CeilingFan::HIGH:
			ceilingFan->high();
			break;

		case CeilingFan::MEDIUM:
			ceilingFan->medium();
			break;

		case  CeilingFan::LOW:
			ceilingFan->low();
			break;

		case  CeilingFan::OFF:
			ceilingFan->off();
			break;
		}
	}

private:

	CeilingFan* ceilingFan;
	int prevSpeed;
};