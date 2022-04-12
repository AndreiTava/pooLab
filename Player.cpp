#include "Player.h"

Player::Player(std::string name)
	:
Entity(std::move(name),100,10,5)
{}

void Player::describe(std::ostream& out) const
{
	out << this->name << " LVL " << this->LVL << " adventurer: \nMaxHealth: " << this->MHP <<" MaxEnergy: "<<this->MEP << " Attack: " << this->ATK << " Defence: " << this->DEF << "\n";
}

Player::commands Player::resolveCommand(std::string command)
{
	if (command == "A")
		return commands::attack;
	if (command == "S")
		return commands::special;
	if (command == "I")
		return commands::item;
	if (command == "R")
		return commands::run;
	throw InputException();
}


void Player::levelUp()
{
	++(this->LVL);
	this->HP = this->MHP+=50;
	this->EP = this->MEP += 50;
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
	std::cout << this->name << " has gained " << exp << " exp\n";
	this->checkLvlUp();
}

void Player::attack(Entity& target)
{
	if (!target.isAlive())
		throw TargetException();
	std::cout <<"(>>)\n" << this->name << " attacks " << target.getName() << "\n";
	target.takeDamage(this->ATK);
	if (!target.isAlive())
		target.die(*this);
}

void Player::act(Entity& me, std::vector<Entity*>& enemies)
{
	if (&me != this)
		return;
	std::string input ="0";
	std::cout <<this->name<<": "<<this->HP<<"/"<<this->MHP<<"HP "<<this->EP<<"/"<<this->MEP<<"EP "<<this->POT << " Potions\n" << "A - Basic Attack      S - Special Attack\nI - Item              R - Run\n";
	std::getline(std::cin,input);
	try {
		auto command = resolveCommand(input);
		unsigned int target = 0;
		switch (command)
		{
		case commands::attack:
			std::cout << "Choose target: \n";
			for (size_t i = 0; i < enemies.size(); ++i)
				if (enemies[i]->isAlive())
					std::cout << i << ": " << *enemies[i] << "\n";
			std::cout << "Target:";
			std::getline(std::cin, input);
			target = std::stoi(input, nullptr, 10);
				if (target >= enemies.size())
					throw TargetException();
				this->attack(*enemies[target]);
			break;
		}
	}
	catch(std::invalid_argument&)
	{
		std::cout << "(E) Input is not a number!\n";
		this->act(me, enemies);
	}
	catch (TargetException&)
	{
		std::cout << "(E) Selected enemy is invalid\n";
		this->act(me, enemies);
	}
	catch(InputException&)
	{
		std::cout << "(E) Invalid command, try again\n";
		this->act(me, enemies);
	}
}
