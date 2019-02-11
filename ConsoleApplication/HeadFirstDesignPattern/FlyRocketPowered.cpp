import std.core;
import FlyBehavior;

using namespace Behavior;

namespace Behavior
{
	class FlyRocketPowered : public FlyBehavior
	{
	public:

		virtual void fly() override
		{
			printf("I'm flying with a rocket!\n");
		}
	};
}