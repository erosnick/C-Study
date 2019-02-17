import std.core;
import WeaponBehavior;

using namespace Weapon;

namespace Weapon
{
	class AxeBehavior : public WeaponBehavior
	{
	public:

		virtual void useWeapon() override 
		{
			printf("Use Axe.\n");
		}
	};
}