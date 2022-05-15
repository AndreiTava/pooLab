#include "Weapons.h"

std::string Sword::name = "Sword";
std::string Staff::name = "Staff";


void Sword::use(unsigned int base_atk, Entity& target)
{
	target.takeDamage(base_atk + 5);
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
	out << swrd.getName() << ", increases attack by 5\n";
	return out;
}


