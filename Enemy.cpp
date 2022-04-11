#include "Enemy.h"


Enemy::Enemy(std::string p_name, const unsigned int p_hp, const unsigned int p_atk, const unsigned int p_def,const unsigned int p_exp)
	:
	Entity(std::move(p_name), p_hp, p_atk, p_def),
	EXP(p_exp)
{}

void Enemy::describe(std::ostream& out) const
{
	out << this->name << ":\nMaxHealth: " << this->MHP<< " Attack: " <<this->ATK<< " Defence: " << this->DEF<< "\nNo Special Abilities. \n";
}

void Enemy::die(Entity& culprit)
{
	try {
		auto player = dynamic_cast<Player&>(culprit);
		std::cout<<"(!)\n" << player.getName() << "'s attack has vanquished the " << this->name << "\n";
		player.gainExp(this->EXP);
	}
	catch (std::bad_cast&)
	{
		Entity::die(culprit);
	}
}


void Enemy::act(Entity& player, std::vector<Entity*>& enemies)
{
	this->interact(this->decideTarget(player, enemies));
}
Entity& Enemy::decideTarget(Entity& player, const std::vector<Entity*>& enemies)
{
	if (enemies.empty())
		return player;
	return player;
}
void Enemy::interact(Entity& target)
{
	std::cout <<"(<<)\n" << this->name << " attacks " << target.getName() << "\n";
	target.takeDamage(this->ATK);
	if (!target.isAlive())
		target.die(*this);
}



