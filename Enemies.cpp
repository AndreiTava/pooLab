#include "Enemies.h"

Goblin::Goblin()
	:
	Enemy("Goblin", 20, 10, 10, 20)
{}

void Goblin::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "No special abilities\n";
}
Treant::Treant()
	:
	Enemy("Treant", 30, 5, 20, 20)
	{}
void Treant::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "Heals others for 5HP\n";
}
Entity& Treant::decideTarget(Entity& player, const std::vector<Entity*>& enemies)
{
	if (enemies.empty())
		return player;
	const size_t ind = rand() % (enemies.size() - 1);
	return *enemies[ind];
}
void Treant::interact(Entity& target)
{
	std::cout << "(@)\n" << this->name << " heals " << target.getName() <<"\n";
	target.takeDamage(-this->ATK);
}

Slime::Slime()
	:
	Enemy("Slime", 15, 5, 0, 10)
{}

void Slime::act(Entity& player , std::vector<Entity*>& enemies)
{
	if (rand() % 3 == 1)
	{
		std::cout << "(@)\n" << this->name << " splits into two!\n";
		const auto newSlime = new Slime();
		enemies.push_back(newSlime);
	}
	else
		interact(player);
}
void Slime::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "Has a 1/3 chance of multiplying\n";
}

Mimic::Mimic()
	:
Enemy("Mimic",5,1,0,5)
{}

void Mimic::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "Turns into a random enemy\n";
}

void Mimic::act(Entity& player, std::vector<Entity*>& enemies)
{
	if (!enemies.empty())
	{
		size_t ind=0;
		do
		{
			ind = rand() % (enemies.size() - 1);
		} while (this == enemies[ind]);
		size_t self = 0;
		for (size_t i = 0; i < enemies.size(); ++i)
			if (enemies[i] == this)
				self = i;
		try
		{
			Enemy::types type = Enemy::resolveType(enemies[ind]->getName());
			
			Enemy* converted = nullptr;
			std::cout << "(@)\n" << this->name << " turns into a "<<enemies[ind]->getName()<<"\n";
			delete enemies[self];
			switch (type)
			{
			case types::goblin:
				converted = new Goblin();
				break;
			case types::treant:
				converted = new Treant();
				break;
			case types::slime:
				converted = new Slime();
				break;
			case types::mimic:
				converted = new Mimic();
				break;
			}
			*converted = *dynamic_cast<Enemy*>(enemies[ind]);
			enemies[self] = converted;

		}
		catch (EnemyException& e)
		{
			std::cout << e.what();
		}

	}
	else
		interact(player);
}




