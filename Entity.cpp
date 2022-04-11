#include "Entity.h"
Entity::Entity(std::string p_name, const unsigned int p_hp, const unsigned int p_atk, const unsigned int p_def)
	:
	name(std::move(p_name)),
	HP(p_hp),
	MHP(p_hp),
	ATK(p_atk),
	DEF(p_def)
{}

std::string Entity::getName() const
{
	return name;
}


bool Entity::isAlive() const
{
	return HP <= 0 ? false : true;
}

void Entity::die(Entity& culprit)
{
	if (&culprit != this)
		return;
	/*std::cout << name << " has been defeated by "<<culprit.getName()<<"\n";*/
}

void Entity::takeDamage(const int dmg)
{
	const int dmg_took = dmg * static_cast<int>(1.f - static_cast<float>(this->DEF) / 100);
	HP -= dmg_took;
	/*std::cout << name << " took " << dmg_took << " damage \n";*/
	HP = std::min(HP, MHP);
}

std::ostream& operator<<(std::ostream& out, const Entity& ent)
{
	ent.describe(out);
	return out;
}







