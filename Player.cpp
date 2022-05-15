#include "Player.h"

Player::Player(std::string name,LegendaryWeapon& wpn)
	:
Entity(std::move(name),100,10,10),
weapon(wpn)
{}

void Player::describe(std::ostream& out) const
{
	out << this->name << ": " << this->ATK << " ATK " << this->DEF << " DEF \n" << this->HP << "/" << this->MHP << "HP " << this->EP << "/" << this->MEP << "EP " << this->POT << " Potions\n";
}

Player::commands Player::resolveCommand(const std::string& command)
{
	if (command[0] == 'A')
		return commands::attack;
	if (command[0] == 'S')
		return commands::special;
	if (command[0] == 'I')
		return commands::item;
	throw InputException();
}


void Player::levelUp()
{
	std::cout<<"\n~~" << name << " has leveled up!~~\nHP and EP fully restored!\nAll stats increased!\n\n";
	++(this->LVL);
	this->MHP += 50;
	this->HP = this->MHP;
	this->MEP += 50;
	this->EP = this->MEP;
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
void Player::special(const std::vector<Entity*>& targets)
{
	if (this->EP < 25)
		throw MechanicException();
	std::cout << "(@)\n" << this->name << " uses Whirlwind(-25EP) and hits all enemies!\n";
	this->EP -= 25;
	for (auto target : targets)
	{
		if (target->isAlive())
		{
			target->takeDamage(this->ATK);
			if (!target->isAlive())
				target->die(*this);
		}

	}
}
void Player::item()
{
	if (this->POT == 0)
		throw MechanicException();
	std::cout << "($)\n" << name << " uses a potion and recovers 25HP!\n";
	this->HP = std::min(this->HP + 20, this->MHP);
	--this->POT;
}



void Player::act(Entity& me, std::vector<Entity*>& enemies)
{
	if (&me != this)
		return;
	std::string input ="0";
	std::cout<<*this<< "A - Basic Attack      S - Special Attack\nI - Item\n";
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
		case commands::special:
			this->special(enemies);
			break;
		case commands::item:
			this->item();
			break;
		}
	}
	catch(std::invalid_argument&)
	{
		std::cout << "(E)\nInput is not a number!\n";
		this->act(me, enemies);
	}
	catch(MechanicException& e)
	{
		std::cout << e.what();
		this->act(me, enemies);
	}
	catch (TargetException& e)
	{
		std::cout << e.what();
		this->act(me, enemies);
	}
	catch(InputException& e)
	{
		std::cout << e.what();
		this->act(me, enemies);
	}
}
