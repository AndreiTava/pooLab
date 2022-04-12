#include "Enemy.h"


Enemy::Enemy(std::string p_name, const unsigned int p_hp, const unsigned int p_atk, const unsigned int p_def,const unsigned int p_exp)
	:
	Entity(std::move(p_name), p_hp, p_atk, p_def),
	EXP(p_exp)
{}

Enemy::Enemy(const Enemy& rhs) :
	Entity(rhs),
	EXP(rhs.EXP)
{};
void Enemy::operator=(const Enemy& rhs)
{
	this->Entity::operator=(rhs);
	this->EXP = rhs.EXP;
}



void Enemy::describe(std::ostream& out) const
{
	out << this->name << ":"<<this->HP<<"/"<<this->MHP<<"HP\nAttack: " <<this->ATK<< " Defence: " << this->DEF<< "\n";
}

void Enemy::die(Entity& culprit)
{
	try {
		auto& player =  dynamic_cast<Player&>(culprit);
		std::cout<<"(!)\n" << player.getName() << "'s attack has vanquished the " << this->name << "\n";
		player.gainExp(this->EXP);
	}
	catch (std::bad_cast&)
	{
		Entity::die(culprit);
	}
}

Enemy::types Enemy::resolveType(std::string name)
{
	if (name == "Goblin")
		return types::goblin;
	if (name == "Treant")
		return types::treant;
	if (name == "Slime")
		return types::slime;
	if (name == "Mimic")
		return types::mimic;
	throw(EnemyException());
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



