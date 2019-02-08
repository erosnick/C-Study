import std.core;
import QuackBehavior;

namespace Behavior
{
	class Quack : public QuackBehavior
	{
	public:

		virtual void quack() override
		{
			printf("Quack.");
		}
	};
}