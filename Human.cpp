#include "Human.h"

template <class weapon_type>
Human<weapon_type>::Human()
	:
	Enemy("Human",50,20,15,100)
{}

template <class weapon_type>
void Human<weapon_type>::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "is wielding a:" << weapon<<"\n";
}

template <class weapon_type>
void Human<weapon_type>::interact(Entity& target)
{
	std::cout << "(<<)\n" << this->name << " attacks " << target.getName() <<" with "<<weapon_type::getName()<< "\n";
	weapon.use(ATK, target);
}

Entity& Human<Staff>::decideTarget(Entity& player, const std::vector<Entity*>& enemies)
{
	if (enemies.empty())
		return player;
	const size_t ind = rand() % (enemies.size() - 1);
	return *enemies[ind];
}



