#include "Entity.h"

Entity::Entity(std::string p_name, const unsigned int p_hp, const unsigned int p_atk, const unsigned int p_def)
	:
	name(std::move(p_name)),
	HP(p_hp),
	MHP(p_hp),
	ATK(p_atk),
	DEF(p_def)
{}

Entity::Entity(const Entity& rhs)
	:
	name(rhs.name),
	HP(rhs.HP),
	MHP(rhs.MHP),
	ATK(rhs.ATK),
	DEF(rhs.DEF)
{}
void Entity::operator=(const Entity& rhs)
{
	this->HP = rhs.MHP;
	this->MHP = rhs.MHP;
	this->ATK = rhs.ATK;
	this->DEF = rhs.DEF;
}



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
	std::cout << name << " has been defeated by "<<culprit.getName()<<"\n";
}

void Entity::takeDamage(const int dmg)
{
	const int dmg_took = static_cast<int>(static_cast<float>(dmg) * 1.f - static_cast<float>(this->DEF) / 100.f);
	HP -= dmg_took;
	if(dmg_took >=0)
		std::cout << name << " took " << dmg_took << " damage \n";
	else
		std::cout << name << " was healed for " << -dmg_took << " HP \n";
	HP = std::min(HP, MHP);
}

std::ostream& operator<<(std::ostream& out, const Entity& ent)
{
	ent.describe(out);
	return out;
}







