import std.core;
import WeaponBehavior;

using namespace Weapon;

namespace Weapon
{
	class SwordBehavior : public WeaponBehavior
	{
	public:

		virtual void useWeapon() override
		{
			printf("Use Sword.\n");
		}
	};
}