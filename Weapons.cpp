#include "Weapons.h"

std::string Sword::name = "Sword";
std::string Staff::name = "Staff";


void Sword::use(unsigned int base_atk, Entity& target)
{
	target.takeDamage(base_atk + 10);
}

void Staff::use(unsigned int base_atk, Entity& target)
{
	target.takeDamage(-1*static_cast<int>(base_atk));
}

std::string Sword::getName()
{
	return name;
}

std::string Staff::getName()
{
	return name;
}

std::ostream& operator<<(std::ostream& out, const Staff& stf)
{
	out << stf.getName() << ", allows the healing of others\n";
	return out;
}
std::ostream& operator<<(std::ostream& out, const Sword& swrd)
{
	out << swrd.getName() << ", increases attack by 10\n";
	return out;
}

PlayerWeapon::PlayerWeapon(unsigned int p_atk)
	:
	ATK(p_atk)
{}

void PlayerWeapon::addAttack(unsigned int add)
{
	ATK += add;
}

unsigned int  PlayerWeapon::use(unsigned int base_atk, Entity& target)
{
	target.takeDamage(base_atk+ATK);
	return 0;
}

LegendaryDecorator::LegendaryDecorator(LegendaryWeapon* p_weapon)
	:
	weapon(p_weapon)
{}

void LegendaryDecorator::addAttack(unsigned int add)
{
	weapon->addAttack(add);
}



VampiricEdge::VampiricEdge(LegendaryWeapon* p_weapon)
	:
	LegendaryDecorator(p_weapon)
{}

BloodLust::BloodLust(LegendaryWeapon* p_weapon)
	:
	LegendaryDecorator(p_weapon)
{}

ReapersLuck::ReapersLuck(LegendaryWeapon* p_weapon)
	:
	LegendaryDecorator(p_weapon)
{}

unsigned int VampiricEdge::use(unsigned int base_atk, Entity& target)
{
	weapon->use(base_atk, target);
	std::cout << "(@)\n" <<"Vampiric effect heals for " << base_atk << "\n";
	return base_atk;
}
unsigned int BloodLust::use(unsigned int base_atk, Entity& target)
{
	weapon->use(base_atk, target);
	weapon->addAttack(10);
	std::cout << "(@)\n" << "Bloodlust adds 10 damage to the weapon \n";
	return 0;
}

unsigned int ReapersLuck::use(unsigned int base_atk, Entity& target)
{
	const unsigned int chance = rand() % 10;
	if (chance == 0)
	{
		base_atk = 999999;
		std::cout << "(@)\n" << "Reaper's Luck activates and instakills!\n";
	}
	weapon->use(base_atk, target);
	return 0;
}







