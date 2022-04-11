#include "Player.h"

Player::Player(std::string name)
	:
Entity(std::move(name),100,10,10)
{}

//void Player::describe(std::ostream& out) const
//{
//	out << "p";
//}

void Player::levelUp()
{
	++(this->LVL);
	this->HP = this->MHP+=50;
	this->ATK += 10;
	this->DEF += 5;
	
}


void Player::checkLvlUp()
{
	const unsigned int targetExp = 5*this->LVL * (this->LVL + 1);
	if (this->EXP >= targetExp)
		this->levelUp();
}


void Player::gainExp(unsigned int exp)
{
	this->EXP += exp;
	/*std::cout << this->name << " has gained " << exp << " exp\n";*/
	this->checkLvlUp();
}

void Player::attack(Entity& target)
{
	/*std::cout <<"(>>)\n" << this->name << " attacks " << target.getName() << "\n";*/
	target.takeDamage(this->ATK);
	if (!target.isAlive())
		target.die(*this);
}

void Player::act(Entity& me, std::vector<Entity*>& enemies)
{
	if (!(this == &me))
		return;
	char command ='0';
	std::cout << "Choose action: ";
	std::cin >> command;
	switch (command)
	{
	case 'A':
		unsigned int target=0;
		std::cout << "Choose target: \n";
		for (size_t i = 0; i < enemies.size(); ++i)
			if (enemies[i]->isAlive())
				/*std::cout << i << ": "<<*enemies[i]<<"\n";*/
		std::cout << "Target:";
		std::cin >> target;
		this->attack(*enemies[target]);
	}
}
