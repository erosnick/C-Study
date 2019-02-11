import WeaponBehavior;

using namespace Weapon;

class Character
{
public:

	virtual void fight() = 0
	{
		weaponBehavior->useWeapon();
	}

	void setWeaponBehavior(WeaponBehavior* newWeaponBehavior)
	{
		weaponBehavior = newWeaponBehavior;
	}

private:

	WeaponBehavior* weaponBehavior;
};