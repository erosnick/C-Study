import std.core;
import FlyBehavior;

namespace Behavior
{
	class FlyNoWay : public FlyBehavior
	{
	public:

		virtual void fly() override
		{
			printf("Fly no way.");
		}
	};
}