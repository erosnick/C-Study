import std.core;
import WeaponBehavior;

using namespace Weapon;

namespace Weapon 
{
	class ArrowAndBowBehavior : public WeaponBehavior
	{
	public:

		virtual void useWeapon() override
		{
			printf("Use Arrow and Bow.\n");
		}
	};
}