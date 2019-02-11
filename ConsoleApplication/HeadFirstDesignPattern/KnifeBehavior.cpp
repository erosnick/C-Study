import std.core;
import WeaponBehavior;

using namespace Weapon;

namespace Weapon
{
	class KnifeBehavior : public WeaponBehavior
	{
	public:

		virtual void useWeapon() override
		{
			printf("Use Knife.\n");
		}
	};
}