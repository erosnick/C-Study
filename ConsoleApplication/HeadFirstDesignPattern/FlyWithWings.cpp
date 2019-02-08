import std.core;
import FlyBehavior;

namespace Behavior
{
	class FlyWithWings : public FlyBehavior
	{
	public:

		virtual void fly() override
		{
			printf("Fly with wings.");
		}
	};
}